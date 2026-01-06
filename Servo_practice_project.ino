#include <Servo.h>
void setup() {
  // put your setup code here, to run once:
  Servo servo;
  servo.attach(12);
  servo.write(0);

  delay(500);
  servo.write(180);
  
  delay(900);
  servo.write(95);
  
  delay(500);
  servo.write(25);
  
  delay(400);
  servo.write(0);
  
  delay(800);
  servo.write(180);
  
  delay(1500);
  servo.write(145);
  
  delay(500);
  servo.write(0);
  
  delay(500);


}

void loop() {
  // put your main code here, to run repeatedly:

}
