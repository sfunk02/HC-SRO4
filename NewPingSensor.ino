//Sam Funk
//NewPing HCSR04
//Uses the NewPing library to determine distance with a HC-SRO4 ultrasonic sensor.

#include <NewPing.h>

#define TRIGGER_PIN   12
#define ECHO_PIN      11
#define MAX_DISTANCE 100
int cm = 0;
int cm0 = 0;
NewPing myHCSR04(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

int ledPin = 10;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {

  cm0 = myHCSR04.ping_cm();
  if (cm0 != 0 && cm0 < 100) {
    cm = cm0;
    Serial.println(cm);
  }
  /*
    digitalWrite(ledPin, HIGH);
    delay(cm);
    digitalWrite(ledPin, LOW);
    delay(cm);
    }
  */

  for (int brightness = 0; brightness < 255; brightness+=5) {
    analogWrite(ledPin, brightness);
    delay(cm);
  }

  for (int brightness = 255; brightness > 0; brightness-=5) {
    analogWrite(ledPin, brightness);
    delay(cm);
  }
}

//Credit to Tim Eckel for making the NewPing library.
