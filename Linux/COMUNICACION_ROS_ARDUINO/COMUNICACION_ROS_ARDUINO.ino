
// Librerias necesarias para la comunicacion con ROS.
#include <ros.h>
#include <math.h>
#include <sensor_msgs/JointState.h>
#include <AS5X47.h>

int slaveSelectPin = 48;

// Start connection to the sensor.
AS5X47 as5047p(slaveSelectPin);


//Creamos el nodo.
ros::NodeHandle  nodo;
//---------------------------------PUBLICADOR---------------------------------//
sensor_msgs::JointState joint_msg;
ros::Publisher joint_state_pub("/joint_states", &joint_msg);




void setup() {
  nodo.getHardware()->setBaud(9600);
  //sensor.init();
  // put your setup code here, to run once:
  //--------------------------------CONFIGURACIONES DE ROS----------------------------//
  nodo.initNode();
  nodo.advertise(joint_state_pub);

}

void loop() {
    
    float angulo = -(radians(as5047p.readAngle()));

    //llenando el mensaje.
    joint_msg.header.stamp = nodo.now();
    joint_msg.name_length = 1;
    joint_msg.position_length = 1;
    joint_msg.name = new char*[1];
    joint_msg.position = new float[1];
    joint_msg.name[0] = "Revolute_2";
    joint_msg.position[0] = angulo;


    
  // put your main code here, to run repeatedly:
    //configurar_mensaje_juntas(angulo);
    joint_state_pub.publish(&joint_msg);
    nodo.spinOnce();
    delay(400);
}

//void configurar_mensaje_juntas(float angulo){
  /* Esta linea es una de las principales pues aqui le mandamos los valores de la posicion del arduino a ROS;*/
  //joint_msg.header.stamp = nodo.now();
  // Aqui se modificara de acuerdo al numero de juntas que tengamos en el robot, en este caso tenemos solo 1.
  //joint_msg.name_length = 1;
  //joint_msg.position_length = 1;
  //joint_msg.velocity_length = 1;
  //joint_msg.effort_length = 3;
  //joint_msg.name = new char*[1];
  //joint_msg.position = new float[1];
  //joint_msg.velocity = new float[3];
  //joint_msg.effort = new float[3];

  //joint_msg.name[0] = "Revolute_2";
  //joint_msg.name[1] = "joint2";
  //joint_msg.name[2] = "joint3";
  //joint_msg.position[0] = angulo;
  //joint_msg.position[1] = 2.0;
  //joint_msg.position[2] = 3.0;
  //joint_msg.velocity[0] = 0.5;
  //joint_msg.velocity[1] = 1.0;
  //joint_msg.velocity[2] = 1.5;
  //joint_msg.effort[0] = 1.0;
  //joint_msg.effort[1] = 2.0;
  //joint_msg.effort[2] = 3.0;
//}
