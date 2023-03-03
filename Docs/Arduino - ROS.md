# COMUNICACIÓN ROS - ARDUINO.
## 1. Instalación de la libreria rosserial. 
Para instalar la herramienta, simplemente sigue estos pasos: 
* Abre el IDE de Arduino en tu computadora Windows.

* En la barra de menú superior, selecciona "Herramientas" y luego "Administrador de librerías".

* En la ventana del Administrador de librerías, busca "rosserial" en el cuadro de búsqueda en la esquina superior derecha.

* Aparecerán varias opciones de rosserial. Selecciona la versión que deseas descargar e instalar. Asegúrate de seleccionar la versión que sea compatible con la versión de tu sistema operativo y el IDE de Arduino que estés utilizando.

* Haz clic en el botón "Instalar" en la parte inferior derecha de la ventana.

* Espera a que se complete la instalación de la librería.

Una vez que la instalación haya finalizado, puedes cerrar la ventana del Administrador de librerías.

---

## 2. Instalar paquete rosserial 
* Abre una terminal en Ubuntu Mate.

* Instala la librería de rosserial con los siguientes comandos:

```
sudo apt-get install ros-melodic-rosserial
sudo apt-get install ros-melodic-rosserial-arduino
```
---

## 3. Encontrar el puerto USB.
* Conecta el Arduino a tu computadora mediante un cable USB.

* Abre una terminal en Ubuntu Mate.

* Escribe el siguiente comando en la terminal para mostrar una lista de los puertos seriales disponibles:

```
ls /dev/tty*
```
---

Esto mostrará una lista de todos los dispositivos de puerto serie disponibles en tu sistema, incluyendo los puertos a los que está conectado el Arduino.

* Busca el nombre del puerto en la lista que se muestra. Por lo general, el puerto que usa el Arduino suele tener un nombre similar a "/dev/ttyACM0" o "/dev/ttyUSB0". Si tienes más de un dispositivo conectado a tu computadora, es posible que debas desconectar los otros dispositivos para determinar qué puerto está utilizando el Arduino.

* Ahora que has identificado el nombre del puerto en el que está conectado el Arduino, puedes usar ese nombre para el siguiente paso.

---

## 4. Prueba de comunicación
```
rosrun rosserial_python serial_node.py "puerto"
```

Para escuchar el topico publicado:
```
rostopic echo /chatter
```