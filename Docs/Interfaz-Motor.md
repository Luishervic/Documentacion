# Interfaz Motor - Usuario.
---
SimpleFOC Studio es un entorno de desarrollo integrado (IDE, por sus siglas en inglés) para la programación y el control de motores eléctricos utilizando la biblioteca SimpleFOC. 

Se basa en la plataforma Qt y proporciona una interfaz gráfica de usuario para ayudar a los usuarios a configurar y ajustar los parámetros de control de motores, visualizar los datos del motor en tiempo real y realizar pruebas y simulaciones. La aplicación se puede utilizar con una variedad de tarjetas de desarrollo, incluyendo Arduino, STM32 y ESP32, lo que la hace altamente flexible y adaptable a diferentes proyectos.

La herramienta está diseñada para simplificar el proceso de desarrollo de aplicaciones de control de motores eléctricos, lo que permite a los usuarios enfocarse en el desarrollo de su proyecto en lugar de tener que preocuparse por la complejidad del control de motores. Con su interfaz gráfica de usuario intuitiva y su amplia gama de características y opciones de configuración, SimpleFOC Studio es una herramienta poderosa y fácil de usar para cualquier persona interesada en el control de motores eléctricos.

---
## Instalación.
Debido a que estamos utilizando el puerto USB del Arduino MEGA para la comunicación con ROS a través de rosserial, no podemos usarlo para otras tareas. Por lo tanto, para visualizar el comportamiento del motor y configurar los parámetros en tiempo real, utilizaremos el puerto Serial1, que se encuentra en los pines TX1 y RX1, para enviar y recibir información del motor.

Hay varias formas de lograr esto. Una opción es utilizar un convertidor USB a TTL, aunque esto requeriría la compra de un componente de hardware adicional. Otra alternativa es habilitar el puerto Serial de la interfaz GPIO de la Raspberry Pi y utilizarlo para la comunicación.

Esto nos permitirá realizar la comunicación de manera efectiva sin interferir con el uso del puerto USB para la comunicación con ROS.

1. Abre la terminal de la Raspberry Pi.

2. Ingresa el siguiente comando para abrir la configuración de Raspberry Pi y presiona enter:

```
sudo raspi-config
```
3. Usa las teclas de flecha en el teclado para seleccionar "Interfacing Options" (Opciones de Interfaz) en el menú.

4. Luego, selecciona "Serial", aparecerá un mensaje preguntandote lo siguiente; **Would you like a login shell to be accessible over serial?**, selecciona No, después te preguntará lo siguiente;
**Would you like the serial port hardware to be enabled?**, selecciona Sí.

5. Al finalizar el paso anterior, selecciona la opción **Finish** ahora te preguntará si quieres reiniciar seleccionamos No, porque instalaremos otras utilidades más adelante.

## Instalación SimpleFOC Studio.
1. En la misma terminal o en otra, ingresa el siguiente comando:

```
git clone https://github.com/JorgeMaker/SimpleFOCStudio.git
```
2. Cambia de directorio.

```
cd SimpleFOCStudio/
```
3. Instala todos los paquetes necesarios.

```
pip install -r "requirements.txt"
```
4. Ahora reinicia la Raspberry.

```
sudo shutdown -r now
```
5. ¡Listo! al iniciar de nuevo, solo cambia de directorio usando la instrucción 2 para después usar el siguiente comando:

```
python3 simpleFOCStudio.py
```
La interfaz luce semenjante a la siguiente:
![SimpleFOCStudio](/imgs/SimpleFOCStudio.png)