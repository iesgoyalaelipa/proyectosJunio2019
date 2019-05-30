#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

char command;
int toSensor = 0;

void setup() {
  Serial.begin(9600);       // set up Serial library at 9600 bpsç
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.read();
    motor_stop();

    /*if(toSensor == 1) {
      
    }
    else {
     
      if(strcmp(command, 'Q') == 0) {
        toSensor = 1;
      }
  
      else {*/
        switch(command){
    
        case 'F':
          forward();
          break;
          
        case 'B':    
          backward();
          break;
        
        case 'L':    
          left();
          break;
        
        case 'R':    
          right();
          break;
          
        case 'S':    
          motor_stop();
          break;
        }
     /* }
    }*/
  }
}
/*
void sensor(int x) {
  if((0 < x) && (x <= 4)) {
    motor1.setSpeed(100);
    motor1.run(FORWARD);
  }
  else if((4 < x) && (x <= 8)) {
    motor1.setSpeed(255);
    motor1.run(FORWARD);
  }
  else if((0 > x) && (x <= -4)) {
    motor1.setSpeed(100);
    motor1.run(BACKWARD);
  }
  else if((4 > x) && (x <= -8)) {
    motor1.setSpeed(255);
    motor1.run(BACKWARD);
  }
}
*/

void forward() {
  
  motor1.setSpeed(255);
  motor1.run(FORWARD);
}

void backward() {
    
  motor1.setSpeed(255);
  motor1.run(BACKWARD);
}

void left() {
  
  motor2.setSpeed(255);
  motor2.run(FORWARD);
}

void right() {
  
  motor2.setSpeed(255);
  motor2.run(BACKWARD);
}

void motor_stop(){
  
  motor1.setSpeed(0);
  motor2.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
}
