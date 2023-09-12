#include <Arduino.h>

#define TRIGGER_PIN 9
#define ECHO_PIN 10
#define MAX_DISTANCE 400
#define DISTANCE_ALERT 30
#define VELOCITY  90
#define VELOCITY_BACK 70

#define ENA 6
#define IN1 13
#define IN2 12

#define ENB 5
#define IN3 4
#define IN4 3

int motorSpeedA = 0;
int motorSpeedB = 0;


// Functions
int getDistance();
void velocity(int vel);
void goFoward();
void findWay();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(13, OUTPUT);

  velocity(VELOCITY);
}

void loop() {
  // put your main code here, to run repeatedly:
  
    // Show visual alerts 
  //digitalWrite(13, alert);

  int distance =  getDistance();
  Serial.println(distance);

  /* if((distance > DISTANCE_ALERT) && (distance < 0)){
    goFoward();
    velocity(VELOCITY);
  } */
  if((distance < DISTANCE_ALERT) && (distance > 5)){
    findWay();
  }
  else if((distance < 0) || (distance > DISTANCE_ALERT)){
    goFoward();
  }
  velocity(VELOCITY);
}

// To controll distance alert
int getDistance(){
  int distance = 0, duration = 0;

  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);  

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration/58.2;

  delay(10);
  return distance;
}

void velocity(int vel){
  analogWrite(ENA, vel);
  analogWrite(ENB, vel);
}


void goFoward(){
  String msg = "foward!";

  // Set Motor A 
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  // Set Motor B
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  Serial.println(msg);
}

void findWay(){
  String msg = "findWay!";

  // Set Motor A 
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  // Set Motor B
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  Serial.println(msg);
}