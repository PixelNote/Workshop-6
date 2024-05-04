#include <Wire.h>

int sensorValue = 0; // Variable para almacenar el valor del sensor
void setup() {
  Serial.begin(9600);
  Wire.begin(8); // Inicia la comunicación I2C con el ESP32
  Wire.onRequest(requestEvent);
}

void loop() {
  delay(100);
}
void requestEvent(){
  int temp = analogRead(A1); // Lee el valor analógico del pin A1 (sensor de temperatura LM35)
  temp = ((temp * 500) / 1024); // Convierte el valor analógico a temperatura en grados Celsius
  Wire.write((byte*)&temp, sizeof(temp));// Envía la temperatura a través de I2C como un byte
}
