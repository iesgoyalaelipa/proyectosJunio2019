#include "EEPROM.h"

#include <Adafruit_MotorShield.h>
char inByte;   
  
char command;       

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *motor1 = AFMS.getMotor(1);
Adafruit_DCMotor *motor2 = AFMS.getMotor(2);

void setup() {
  Serial.begin(9600);       // set up Serial library at 9600 bpsç
  Serial.println("Inicio");

      motor1->setSpeed(150);
      
      motor2->setSpeed(150);
  
}

 
void loop() {
  if (Serial.available() > 0) {       
    inByte = Serial.read();
    Serial.write(inByte);   
    if(inByte == '1') {
      motor1->run(FORWARD);
    }
    else if(inByte == '2') {   
      motor2->run(FORWARD);
    }
    else if(inByte == '3') {     
    motor1->run(BACKWARD);
    } 
    else if(inByte == '4') {     
    motor2->run(BACKWARD);
    }
    else if(inByte == 's') {
      motor1->run(RELEASE);
    }
    else if(inByte == 'd') {
      motor2->run(RELEASE);
    }
  }
}
