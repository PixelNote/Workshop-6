//Importación de librerias
#include <Arduino.h>
#include <Wire.h>
#include "WiFi.h"
#include "ThingSpeak.h"

//Configuración de ThingSpeak
#define CHANNEL_ID 2528518
#define CHANNEL_API_KEY "79B9X6LRT7FFG4GR"

WiFiClient client;
int temp = 0; 
#define WIFI_TIMEOUT_MS 20000 //SEGUNDOS PARA CONECTARSE ANTES DE MOSTRAR ERROR
#define WIFI_NETWORK "Diego Andrés's Galaxy S23 Ultra" //RED WIFI
#define WIFI_PASSWORD "elbichosiu" //CONTRASEÑA DE RED WIFI

void setup() {
  Serial.begin(9600);
  Wire.begin(); //Se une al bus i2c
  pinMode(27, OUTPUT); //Pin para encender el led configurado como salida
  connectToWiFi(); //Llamar a la función para iniciar la conexión a Wifi
  ThingSpeak.begin(client); // Inicializa la conexión con ThingSpeak
}

void loop() {
  Wire.requestFrom(8, 2); //Realiza la petición al Arduino
  // Espera a que lleguen los datos
  while(Wire.available()<2){
    delay(1);
  }
  temp = Wire.read() | (Wire.read() << 8);
    ThingSpeak.writeField(CHANNEL_ID, 1, temp, CHANNEL_API_KEY);
  Serial.println(temp);
  // Enciende un LED en el pin 27 si la temperatura es mayor o igual a 30 grados Celsius
  if(temp >= 30){
    digitalWrite(27, HIGH);
  } else {
    digitalWrite(27, LOW);
  }
  delay(1000);
}
// Función para conectar a la red WiFi
void connectToWiFi(){
  WiFi.mode(WIFI_STA); // Configura el modo WiFi como estación (cliente)
  WiFi.begin(WIFI_NETWORK, WIFI_PASSWORD);
  unsigned long startAttemptTime = millis();
  // Espera hasta que se establezca la conexión o se alcance el tiempo límite
  while (WiFi.status() != WL_CONNECTED && millis()- startAttemptTime < WIFI_TIMEOUT_MS){
    Serial.println(".");
    delay(100);
  }
  // Si la conexión no se establece después del tiempo límite, se muestra un mensaje de falla
  if(WiFi.status()!= WL_CONNECTED){
    Serial.println("Fallido");
  } else{
    Serial.println(WiFi.localIP());
  }
}
