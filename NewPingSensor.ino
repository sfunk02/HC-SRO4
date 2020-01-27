//Sam Funk
//NewPing HCSRO4
//Uses the NewPing library to determine distance with a HC-SRO4 ultrasonic sensor.

#include <NewPing.h>
 
#define TRIGGER_PIN   12
#define ECHO_PIN      11
#define MAX_DISTANCE 200
 
NewPing myHCSR04(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
 
void setup() {
 Serial.begin(9600);
}
 
void loop() {
     Serial.println(myHCSR04.ping_cm());
     delay(50); 
}

//Credit to Tim Eckel
