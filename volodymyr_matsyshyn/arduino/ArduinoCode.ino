#include <stdio.h>
#include <AFMotor.h>
#include <SoftwareSerial.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

int valor = 0;
const byte numChars = 32;
char receivedChars[numChars];

boolean newData = false;

void setup() {
  Serial.begin(9600);  // set up Serial library at 9600 bps
}

void loop() {
  endMarker();
  showData();
  metodo();
}
/*
 * Hace falta una marca para saber cuando tiene que dejar de recibir caracteres y guardarlo en un array de caracteres
 */
void endMarker() {
  static byte counter = 0;
  char endMarker = '\n';
  char receivedChar;

  while (Serial.available() > 0 && newData == false) {
    receivedChar = Serial.read();

    if (receivedChar != endMarker) {
      receivedChars[counter] = receivedChar;
      counter++;
      if (counter >= numChars) {
        counter = numChars - 1;
      }
    }
    else {
      receivedChars[counter] = '\0';
      counter = 0;
      newData = true;
    }
  }
}
/*
 * Envia el array de chars recibido
 */
void showData() {
 if (newData == true) {
  Serial.println(receivedChars);
  newData = false;
 }
}

/*
 * Controla la recepcion de comandos 
 */
void metodo() {
  
  if(receivedChars[0] == ('N')) {
    motor_stop();
  }
  else {
    char e = receivedChars[2];
    char *x;
    *x = e;
    valor = atoi(x);

    if(receivedChars[0] == ('F')) {
      forward(valor * 27);
    }
    else if(receivedChars[0] == ('B')) {
      backward(valor * 27);
    }

    if(receivedChars[4] == '0') {
      motor2_stop();
    }
    else {
      if(receivedChars[4] == ('L')) {
        left();
      }
      else if(receivedChars[4] == ('R')) {
        right();
      }
    }
  }
}

void forward(int speed) {
  
  motor1.setSpeed(speed);
  motor1.run(FORWARD);
}

void backward(int speed) {
    
  motor1.setSpeed(speed);
  motor1.run(BACKWARD);
}

void left() {
  
  motor2.setSpeed(250);
  motor2.run(BACKWARD);
}

void right() {
  
  motor2.setSpeed(250);
  motor2.run(FORWARD);
}

void motor2_stop() {
  motor2.setSpeed(0);
  motor2.run(RELEASE);
}

void motor_stop(){
  
  motor1.setSpeed(0);
  motor2.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
}
