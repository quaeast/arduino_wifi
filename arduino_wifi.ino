
#include "moto.h"
#include "my_mqtt.h"
#include "my_wifi.h"

void setup() {
  // initialize serial for debugging
  Serial.begin(9600);
  my_wifi_set_up();
  servo_initial();
  my_mqtt_set_up();
}

void loop() {
  // print the network connection information every 10 seconds
  // 把输出关了就不鬼畜了
  //  Serial.println();
  //  delay(5000);
  //  servo_loop();
  reconnect();
}
