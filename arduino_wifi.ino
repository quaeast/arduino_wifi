#include "my_mqtt.h"
#include "my_wifi.h"

long lastReconnectAttempt = 0;

void setup() {
  // initialize serial for debugging
  Serial.begin(9600);
  my_wifi_init();
  my_wifi_connect();
  servo_initial();
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if (!client.connected()) {
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
