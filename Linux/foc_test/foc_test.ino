#include <SimpleFOC.h>
#include <Arduino.h>

MagneticSensorSPI sensor = MagneticSensorSPI(48, 14, 0x3FFF);
BLDCMotor motor = BLDCMotor(8,0.066,1320);
BLDCDriver3PWM driver = BLDCDriver3PWM(11,9,10,6,3,5);

//Full comunicacion
Commander command = Commander(Serial);
void doMotor(char* cmd) { command.motor(&motor, cmd); }


void setup(){
    // initialise magnetic sensor hardware
  sensor.init();
  motor.linkSensor(&sensor);

  driver.pwm_frequency = 2500;
    // monitoring port
  Serial.begin(115200);
     // Fuente de poder. [V]
  driver.voltage_power_supply = 12;
  
  // Iniciamos el driver.
  driver.init();
  motor.linkDriver(&driver);

  motor.current_limit = 15;
  motor.velocity_limit = 20;



  //Serial.println("as5047p ready");

  //Corremos en open loop.
  motor.controller = MotionControlType::angle;

  // contoller configuration
  // default parameters in defaults.h

  // velocity PI controller parameters
  motor.PID_velocity.P = 0.5f;
  motor.PID_velocity.I = 20;
  motor.PID_velocity.D = 0;

  motor.LPF_velocity.Tf = 0.01f;
  
  // angle P controller 
  // default P=20
  motor.P_angle.P = 10;

  motor.init();
  motor.initFOC();

  motor.target = 0;
  // The letter (here 'M') you will provide to the SimpleFOCStudio
  command.add('M',doMotor,"motor");
  // tell the motor to use the monitoring
  motor.useMonitoring(Serial);
  Serial.println("Configuracion terminada");
  
  _delay(1000);
}

void loop(){
  motor.loopFOC();
/*   sensor.update();
  // display the angle and the angular velocity to the terminal
  Serial.print(sensor.getAngle());
  Serial.print("\t");
  Serial.println(sensor.getVelocity()); */
  motor.move();
  
  command.run();
}
