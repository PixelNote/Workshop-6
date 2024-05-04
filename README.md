# Workshop-6

## Integrantes

- Andres Felipe Jimenez Albornoz
- Miguel Angel Timoté Moya

## Descripción de requerimientos

Se debe crear un controlador de 2 capas con los siguientes requerimientos: 
1.	Se debe usar una configuración maestro-esclavo conectados con el protocolo I2C.
2.	El esclavo envía datos de temperatura periódicamente, capturados a través de un sensor de referencia TMP36, LM35 o Ds18b20.
3.	El maestro debe encender un led si la temperatura recibida por el esclavo es mayor a 30 grados.
4.	Se debe publicar la temperatura actual y alertar mediante un dashboard usando la plataforma ThingSpeak. Se debe asegurar que el dashboard muestre el historial de datos.

## Solución
Antes de llevar a cabo la solución de los requerimientos mencionados previamente, es necesario aclarar que es el protocolo I2C. Las siglas I2C viene del inglés Inter-Integrated Circuit y es un protocolo usado para permitir la conexión con uno más controladores [1]. Esta permite la transferencia de bits a partir de 2 cables de comunicación, SDA y SCL, Serial Data y Serial Clock respectivamente [2]. 

Con el concepto claro, el siguiente paso es seleccionar los sistemas embebidos necesarios para llevar a cabo la implementación del sistema con el protocolo I2C. En este caso, se usó la tarjeta de desarrollo esp32 junto con la tarjeta Arduino Nano. El esp32 fue seleccionado para actuar como maestro, mientras que el Arduino actúa como esclavo en la solución. 

Si revisamos la documentación de Arduino, podemos ver que para un Arduino Nano, el pin A4 sirve como conexión SDA y el puerto A5 sirve como conexión SCL [3]. En el caso del esp32, el pin 32 funciona para conexión SDA, mientras que el pin 22 sirve para la conexión SCL [4].

## Referencias
[1] https://cursos.mcielectronics.cl/2022/08/23/i2c/

[2] https://hetpro-store.com/TUTORIALES/i2c/

[3] https://docs.arduino.cc/learn/communication/wire/#arduino-i2c-pins

[4] https://www.luisllamas.es/esp32-i2c/


