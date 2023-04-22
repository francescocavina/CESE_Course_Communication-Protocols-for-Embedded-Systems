Este repositorio contiene el trabajo integrador de las materias "Programación de Microcontroladores" y "Protocolos de Comunicación en Sistemas Embebidos" de la Carrera de Especialización en Sistemas Embebidos (CESE). 

El mismo consta de una brújula digital, donde se utiliza la placa NUCLEO F429ZI como componente principial del sistema embebido y además un display OLED de 0.96'' cuyo controlador es el SSD1306 (la comunicación con este dispositivo se realiza mediante I2C). Las mediciones del campo magnético se iban a realizar en un principio utilizando el sensor MPU9250 (acelerómetro, giróscopo y magnetómetro), pero por distintas causas esto no pudo ser posible y quedará para la próxima versión de este sistema. En su lugar, se decidió implementar un módulo que genere números aleatorios en el rango en el que lo haría el sensor, es decir, entre -4800 a 4800 uT (campo magnético). 

El sistema incia al encenderlo con un mensaje de bienvenida y seguidamente se muestra un círculo con una aguja que simula apuntar hacia el norte. Si el pulsador de la placa NUCLEO es presionado, entonces se pasa a otra pantalla donde muestra los datos en crudo obtenidos del sensor. 

Para la implementación de este sistema se utilizó el concepto de modularización, máquinas de estado, antirrebote para el pulsador, delay no bloqueante, entre otros, y también un driver para el display.

En este repositorio se encuentra el proyecto completo desarrollado en CUBE IDE de STM.
