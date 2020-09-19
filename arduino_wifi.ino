
#include "moto.h"
#include "my_mqtt.h"
#include "my_wifi.h"

void setup() {
  // initialize serial for debugging
  Serial.begin(9600);
  my_wifi_set_up();
  servo_initial();
  my_mqtt_set_up();
  reconnect();
}

void loop() {
//  servo_loop();
}
