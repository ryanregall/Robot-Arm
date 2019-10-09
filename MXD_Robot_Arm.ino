#include <Servo.h>

long randNumber;

Servo base;
Servo armone;  
Servo armtwo;  
Servo armthree;  
Servo gripper;  

void setup() {
  base.attach(6);
  armone.attach(9);
  armtwo.attach(8);
  armthree.attach(7);
  gripper.attach(5);
  randomSeed(analogRead(0));
}

void loop() {

  randNumber = random(5, 175);

  base.write(randNumber);  
  delay(1500);    
  armthree.write(90); 
  delay(500);
  armtwo.write(90); 
  delay(500);
  armone.write(90); 
  delay(500);
  gripper.write(90); 
  delay(1500);  
  armone.write(60); 
  delay(1500);
  armtwo.write(165); 
  delay(1500);
  armthree.write(135); 
  delay(2500); 
}
