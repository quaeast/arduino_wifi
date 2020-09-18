#include "WiFiEsp.h"
#include "arduino_rotate.h"
#include "PubSubClient.h"

#ifndef HAVE_HWSERIAL1
#include "SoftwareSerial.h"
SoftwareSerial Serial1(6, 7); // RX, TX
#endif

char ssid[] = "fang";            // your network SSID (name)
char pass[] = "12345678";        // your network password
char mqtt_server = "tcp://39.96.177.143";//你的服务器地址

int status = WL_IDLE_STATUS;     // the Wifi radio's status
WiFiEspClient espClient;
PubSubClient client(espClient);

void setup()
{
  Serial.begin(9600);
  Serial1.begin(9600);
  WiFi.init(&Serial1);
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    while (true);
  }

  while ( status != WL_CONNECTED) {
    Serial.print("Attempting to connect to WPA SSID: ");
    Serial.println(ssid);
    status = WiFi.begin(ssid, pass);
  }

  Serial.println("You're connected to the network");

  printCurrentNet();
  printWifiData();

  servo_init();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop()
{
  while (!client.connected()) {
    reconnect();
  }
  //servo_run();
}

void printWifiData()
{
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  byte mac[6];
  WiFi.macAddress(mac);
  char buf[20];
  sprintf(buf, "%02X:%02X:%02X:%02X:%02X:%02X", mac[5], mac[4], mac[3], mac[2], mac[1], mac[0]);
  Serial.print("MAC address: ");
  Serial.println(buf);
  
}

void printCurrentNet()
{
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  byte bssid[6];
  WiFi.BSSID(bssid);
  char buf[20];
  sprintf(buf, "%02X:%02X:%02X:%02X:%02X:%02X", bssid[5], bssid[4], bssid[3], bssid[2], bssid[1], bssid[0]);
  Serial.print("BSSID: ");
  Serial.println(buf);

  long rssi = WiFi.RSSI();
  Serial.print("Signal strength (RSSI): ");
  Serial.println(rssi);
}

void callback(char* topic, byte* payload, unsigned int length) 
{ 
 
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("]： ");
  Serial.println();
  //servo_run();

}

void reconnect() {
  while (!client.connected()) {
    Serial.println("Attempting MQTT connection...");
    String clientId = "ESP8266Client-";//该板子的链接名称
    clientId += String(random(0xffff), HEX);//产生一个随机数字 以免多块板子重名
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      client.publish("outTopic", "hello world");//链接成功后 会发布这个主题和语句
      client.subscribe("inTopic");//这个是你让板子订阅的主题（接受该主题的消息）
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}
