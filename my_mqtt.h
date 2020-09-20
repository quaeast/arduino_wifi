#include "PubSubClient.h"
#include "WiFiEsp.h"
#include "moto.h"

IPAddress mqtt_server(39, 96, 177, 143);  //你的服务器地址
WiFiEspClient espClient;
void callback(char* topic, byte* payload, unsigned int length);

PubSubClient client(mqtt_server, 1883, callback, espClient);

void callback(char* topic, byte* payload, unsigned int length) {
  client.publish("outTopic","servo start to move");
  servo_move();
  client.publish("outTopic","servo moved");
}

boolean reconnect() {
  if (client.connect("arduinoClient")) {
    // Once connected, publish an announcement...
    client.publish("outTopic","reconnect");
    // ... and resubscribe
    client.subscribe("inTopic");
  }
  return client.connected();
}
