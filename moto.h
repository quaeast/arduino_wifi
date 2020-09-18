 /* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void servo_initial() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void servo_loop() {
  myservo.write(180);   
  delay(5000);
  myservo.write(0);   
  delay(5000);
}
