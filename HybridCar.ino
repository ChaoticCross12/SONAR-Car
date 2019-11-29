#include <Servo.h>

//servo motor code
Servo sonar_servo;
int angle = 0;

//SONAR function code
const int trigPin = 9;
const int echoPin = 12;
long duration;
long distance;

//DC Motor code
#define in1 4
#define in1r 5
#define in2 6
#define in2r 7


//speed control
#define enA 3  
#define enB 11


void setup() {
  
  //servo code
  sonar_servo.attach(8);


  //SONAR code
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);


  //DC Motor code
  pinMode(in1, OUTPUT);
  digitalWrite(in1, HIGH);

  pinMode(in2, OUTPUT);
  digitalWrite(in2, HIGH);

  pinMode(enA, OUTPUT);
  analogWrite(enA, 100);
  pinMode(enB, OUTPUT);
  analogWrite(enB, 100);
}



void loop() {
  for(angle = 60; angle <= 180; angle += 60){
    sonar_servo.write(angle);

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);

    distance = duration * 0.034 / 2;

    Serial.print("Distance: ");
    Serial.println(distance);

    while(distance < 20){
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      break;
      }
      
      delay(200);
    }

  for(angle = 120; angle >= 0; angle -= 60){
    sonar_servo.write(angle);

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);

    distance = duration * 0.034 / 2;

    Serial.print("Distance: ");
    Serial.println(distance);

    while(distance < 20){
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      break;
      }
    
    delay(200);
}



//MODULE 1 START

//void sonarMovement(){
 
  
//  }
}
