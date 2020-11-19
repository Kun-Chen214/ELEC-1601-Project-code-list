#include <Servo.h>  // Include servo library

Servo servoLeft;     
Servo servoRight;

void setup() {
  // put your setup code here, to run once:
  servoLeft.attach(13);  // Attach left signal to pin 13
  servoRight.attach(12); // Attach right signal to pin 12
  pinMode(4, INPUT);
  pinMode(2, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int irRight = digitalRead(4);
  int irLeft = digitalRead(2);
//  Serial.println(irRight);
//  Serial.println(irLeft);
  servoLeft.attach(13);  // Attach left signal to pin 13
  servoRight.attach(12); // Attach right signal to pin 12
  if(irLeft == HIGH && irRight == HIGH) {
    servoLeft.writeMicroseconds(1300); // Left wheel counterclockwise
    servoRight.writeMicroseconds(1700); // Right wheel clockwise
    Serial.println("forward");
  }
  else if(irLeft == LOW && irRight == LOW) { // Both detect black
    servoLeft.detach();
    servoRight.detach();
    Serial.println("stop");
  }
  else if (irLeft == LOW && irRight == HIGH) { // Left Detects Black
    //servoRight.detach();
    servoRight.writeMicroseconds(1300);
    servoLeft.writeMicroseconds(1400);
    Serial.println("left");
  }
  else if (irLeft == HIGH && irRight == LOW) { // Right Detecst Black
    servoLeft.writeMicroseconds(1600);
//servoLeft.detach();
    servoRight.writeMicroseconds(1700);
    Serial.println("right");
  }
  delay(100);
}
