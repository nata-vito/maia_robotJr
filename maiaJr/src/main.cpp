#include <NewPing.h>

#define TRIGGER_PIN 9
#define ECHO_PIN 10
#define MAX_DISTANCE 400
#define DISTANCE_ALERT 20

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
bool getDistance();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  bool alert = true;
  alert = getDistance();
  digitalWrite(13, alert);
  Serial.print(alert);
}

// To controll distance alert
bool getDistance(){
  int distance = sonar.ping_cm();

  if(distance <= DISTANCE_ALERT){
    return false;
  }
  return true;
}

