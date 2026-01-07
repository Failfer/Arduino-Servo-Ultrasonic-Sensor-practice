#include <Servo.h>
  const int triggerPin = 2;
  const int echoPin = 7;
  long cm;
  Servo servo;

void setup() {
  // put your setup code here, to run once:
  // some servos arent calibrated to the standard wavelenth and when you use attach need to set it to the correct pulse wavelegnth instead of between 1 and 2 (if it goes less than 180 degrees of room check and experiment)
  Serial.begin(9600);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  servo.attach(12); //also assigns the pin but using the built in servo.h 

  servo.write(0); //reset servo to default position
  delay(800); // wait a moment to allow it to reset if its not yet reset before starting

  //examples on changing angles with servo.write(time in ms)
  /*
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

void ultraSonicSensorLoop(){
  long duration;

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

void loop() {
  ultraSonicSensorLoop(); // cm defined outside ultrasonic loop so others can acess it
  // sensor loop detects and prints the distance in centimeters
  servo.write(distance_to_servo_angle(cm));
  delay(1000); //waits a second in between, you can remove this for more quick reactions, I keep it as mine starts spazing out very rapidly and sounds like a small mouse going through their 3rd divorce after a little too much cheese
}

long microsecondsToCentimeters(long ms){

return ms / 29 /2; // divide by 2 since sound waves have to go to and from the object it hits to return 

}

float distance_to_servo_angle(long cm){ //takes in the distance in centimeters and makes the servo rotate to a set roation. numbers are arbitrary and what I thought looked cool.
  if(cm >= 0 && cm < 10){
    return 0;
  }
  else if(cm < 20){
    return 45;
  }

  else if(cm < 30){
    return 90;
  }

  else if(cm < 40){
    return 135;
  }
  else {
    return 180;
  }
}
