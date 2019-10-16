/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

Servo base;
Servo armone;  
Servo armtwo;  
Servo armthree;  
Servo gripper;  

int joy1x = A1;
int joy1y = A0;
int joy2x = A3;
int joy2y = A2;

int swivel = 0;
int arms = 0;

int j1x;
int j1y;
int j2x;
int j2y;

void setup() {
  base.attach(6);
  armone.attach(9);
  armtwo.attach(8);
  armthree.attach(7);
  gripper.attach(5);

  pinMode(joy1x, INPUT);
  pinMode(joy1y, INPUT);
  pinMode(joy2x, INPUT);
  pinMode(joy2y, INPUT);

  base.write(90);     
  delay(250); 
  armone.write(90); 
  delay(250);
  armtwo.write(90); 
  delay(250);
  armthree.write(90); 
  delay(250);
  gripper.write(90);           
  delay(1000); 

 // Serial.begin(9600);
}

void loop() {
//  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
//  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)

  joypoll();
//  joyreport();
  joymap();
  base.write(swivel);
  armone.write(arms);
  armtwo.write(arms);
  armthree.write(arms);
}

void joypoll(){
  j1x = analogRead(joy1x);
  j1y = analogRead(joy1y);
  j2x = analogRead(joy2x);
  j2y = analogRead(joy2y);
}

void joyreport(){
  Serial.print("J1X: ");
  Serial.print(j1x);
  Serial.print(" | J1Y: ");
  Serial.print(j1y);
  Serial.print(" | J2X: ");
  Serial.print(j2x);
  Serial.print(" | J2Y: ");
  Serial.println(j2y);
}

void joymap() {
  swivel = map(j1x, 0, 1023, 0, 180);
  arms = map(j2y, 0, 1023, 40, 140);
}
