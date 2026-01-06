#include <Servo.h>
  const int triggerPin = 2;
  const int echoPin = 7;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);

/*
  Servo servo;
  servo.attach(12); //also assigns the pin but using the built in servo.h 
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

*/

}



void loop() {

  long duration, cm;

  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10); //check datasheet for what num you need
  digitalWrite(triggerPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  cm = microsecondsToCentimeters(duration);



  Serial.print("Distance: ");
  Serial.print(cm);
  Serial.println(" cm");


  




}

long microsecondsToCentimeters(long ms){

return ms / 29 /2; // divide by 2 since sound waves have to go to and from the object it hits to return 

}


