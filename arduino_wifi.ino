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
  if (!client.connected()) {
    Serial.println('lost');
    long now = millis();
    if (now - lastReconnectAttempt > 5000) {
      lastReconnectAttempt = now;
      // Attempt to reconnect
      if (reconnect()) {
        lastReconnectAttempt = 0;
      }
    }
  } else {
    // Client connected
    client.loop();
  }
}
