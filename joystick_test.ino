#include <Servo.h>

Servo servoLeft;
Servo servoRight;

int xPosition = 0;
int yPosition = 0;
int SW_state = 0;
boolean buttonPressed = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT_PULLUP); 
  servoLeft.attach(13);
  servoRight.attach(12);
}

void loop() {
  // put your main code here, to run repeatedly:
  xPosition = analogRead(A0);
  yPosition = analogRead(A1);
  SW_state = analogRead(A2);
  delay(100);

  Serial.println(xPosition);
  Serial.println(yPosition);
  Serial.println();

//  if(SW_state == 0) {
//    if(buttonPressed == false) {;
//      buttonPressed = true
//    }
//    else if(buttonPressed == true) {
//      buttonPressed = false;
//    }
//  }
//
//  if(buttonPressed == false) {
//    
//  }
  
  if(xPosition > 510 && xPosition < 520 && yPosition > 0 && yPosition < 10) {
//    servoLeft.detach();
//    servoRight.detach();
//    servoLeft.writeMicroseconds(1505);
//    servoRight.writeMicroseconds(1480);
    servoRight.detach();
    servoLeft.detach();
  }
  
  else if(xPosition == 0) {
    servoLeft.attach(13);
    servoRight.attach(12);
    servoRight.writeMicroseconds(1400);
    servoLeft.writeMicroseconds(1300);
  }
  else if(xPosition >= 1005) {
    servoLeft.attach(13);
    servoRight.attach(12);
    servoRight.writeMicroseconds(1700);
    servoLeft.writeMicroseconds(1600);
  }

  else if(yPosition >= 450) { // Forward
    servoLeft.attach(13);
    servoRight.attach(12);
    servoLeft.writeMicroseconds(1300);
    servoRight.writeMicroseconds(1700);
  }
  else if(yPosition == 0) { // Reverse
    servoLeft.attach(13);
    servoRight.attach(12);
    servoLeft.writeMicroseconds(1700);
    servoRight.writeMicroseconds(1300);
  }
}
