#include "PubSubClient.h"
#include "WiFiEsp.h"
#include "moto.h"

IPAddress mqtt_server(39, 96, 177, 143);  //你的服务器地址
WiFiEspClient espClient;
void callback(char* topic, byte* payload, unsigned int length);

PubSubClient client(mqtt_server, 1883, callback, espClient);

void callback(char* topic, byte* payload, unsigned int length) {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  
  client.publish("outTopic","blinked");
}



boolean reconnect() {
  if (client.connect("arduinoClient")) {
    // Once connected, publish an announcement...
    client.publish("outTopic","hello world");
    // ... and resubscribe
    client.subscribe("inTopic");
  }
  return client.connected();
}
