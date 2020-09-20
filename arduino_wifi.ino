#include "my_mqtt.h"
#include "my_wifi.h"

long lastReconnectAttempt = 0;

void setup() {
  // initialize serial for debugging
  Serial.begin(9600);
  my_wifi_init();
  my_wifi_connect();
  reconnect();
}

void loop() {
  if (!client.loop()) {
    Serial.println("lost connection");
    reconnect();   
  }
}
