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

Con el concepto claro, el siguiente paso es seleccionar los sistemas embebidos necesarios para llevar a cabo la implementación del sistema con el protocolo I2C. En este caso, se usó la tarjeta de desarrollo esp32 junto con la tarjeta Arduino Uno. El esp32 fue seleccionado para actuar como maestro, mientras que el Arduino actúa como esclavo en la solución. 

Si revisamos la documentación de Arduino, podemos ver que para un Arduino Uno, el pin A4 sirve como conexión SDA y el puerto A5 sirve como conexión SCL [3]. En el caso del esp32, el pin 32 funciona para conexión SDA, mientras que el pin 22 sirve para la conexión SCL [4].

Conociendo los puertos encargados para el uso del protocolo I2C en nuestras dos tarjetas de desarrollo, lo siguiente fue crear un diagrama de actividades para entender el proceso que iban a realizar cada una de las tarjetas y así tener claro todo el flujo de trabajo de las tarjetas. 

La tarjeta esclava, en este caso el Arduino Uno, cumple la función de registrar los datos recibidos por el sensor analógico. Después de registrar los datos, son enviados mediante la conexión I2C a la tarjeta master, en este caso el esp32. Cuando el esp32 recibe los datos del sensor de temperatura enviado por el Arduino Uno, se envían los datos a ThingSpeak para poder visualizarse en el dashboard de la aplicación. Seguido de esto, se debe hacer una comprobación, si la temperatura recibida por parte del Arduino Uno es mayor a 30°C, se debe encender un actuador led para comprobar que la temperatura es mayor a 30°C, de lo contrario, se debe apagar el actuador led. El siguiente diagrama de actividades resume todo lo mencionado anteriormente.


<p align="center">
  <img src="https://github.com/PixelNote/Workshop-6/assets/81392047/92e8ba92-0489-4741-b4be-0d282a5e7170" alt="Daigrama de actividades" width="600"/>
</p>

Al tener el diagrama de actividades hecho, el siguiente paso es realizar la conexión de los dispositivos correspondientes. La siguiente imagen muestra la simulación de la conexión usando la plataforma tinkercad. Sin embargo, no hay que tomar en cuenta los pines utilizados en la simulación, ya que tinkercad no cuenta con un modulo para mostrar el esp32. Esta simulación solo fue con fines visuales de referencia para su posterior conexión física.
<p align="center">
  <img src="https://github.com/PixelNote/Workshop-6/assets/81392047/6639ea00-6a7f-44f0-98d5-6dc0e736916e" alt="Daigrama de actividades" width="600"/>
</p>

Para la conexión, la tarjeta Arduino Uno tiene puertos específicos para el SCL y SDA, estos se encuentras dos posiciones despues del pin 13. El sensor de temperatura se encuentra ubicado en la entrada análoga A5 de la tarjeta Arduino. Para el esp32, se usaron los puertos mencionados al inicio de la wiki, y el actuador led se encuentra ubicado en el puerto D27. Las siguientes imagenes muestran la conexión física de todos los pines de ambas tarjetas.

<p align="center">
  <img src="https://github.com/PixelNote/Workshop-6/assets/81392047/10c4b96f-7673-4fb0-985b-e3b150413906" alt="Conexión física 1" width="600"/>
  <img src="https://github.com/PixelNote/Workshop-6/assets/81392047/6393ed59-028c-4d34-a2a9-647d4e9aef6e" alt="Conexión física 2" width="600"/>
</p>


Finalmente, el siguiente código fue usado por cada tarjeta, tanto maestra como esclava, para permitir la conexión entre las tarjetas, el envió de datos y la visualización de la información del sensor en ThingSpeak.

### Código de la tarjeta Maestra (esp32)

```
// the hello world program
console.log('Hello World');
```

### Código de la tarjeta Esclava (Arduino Uno)
```
// the hello world program
console.log('Hello World');
```

## Referencias
[1] https://cursos.mcielectronics.cl/2022/08/23/i2c/

[2] https://hetpro-store.com/TUTORIALES/i2c/

[3] https://docs.arduino.cc/learn/communication/wire/#arduino-i2c-pins

[4] https://www.luisllamas.es/esp32-i2c/


