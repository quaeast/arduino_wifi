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

int pos = 0;  // variable to store the servo position

void servo_initial() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void servo_move(){
  Serial.println("servo start to move");
  myservo.attach(9);
  myservo.write(180);
  delay(3000);
  myservo.attach(9);
  for (int i=180; i>=0;i--){
    myservo.write(i);
    delay(15);
  }
  myservo.detach();
  Serial.println("servo moved");
}

void servo_move_ex() {
  myservo.attach(9);
  for (int i=0; i<=180;i++){
    myservo.write(i);
    delay(15);
  }
  for (int i=180; i>=0;i--){
    myservo.write(i);
    delay(15);
  }
  myservo.detach();
}
