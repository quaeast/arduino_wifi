#include "PubSubClient.h"

char mqtt_server = "tcp://39.96.177.143"; //你的服务器地址
WiFiEspClient espClient;
PubSubClient client(espClient);

void my_mqtt_set_up()
{
    client.setServer(mqtt_server, 1883);
    client.setCallback(callback);
}

void callback(char *topic, byte *payload, unsigned int length)
{

    Serial.print("Message arrived [");
    Serial.print(topic);
    Serial.print("]： ");
    Serial.println();
    //servo_run();
}

void reconnect()
{
    while (!client.connected())
    {
        Serial.println("Attempting MQTT connection...");
        String clientId = "ESP8266Client-";      //该板子的链接名称
        clientId += String(random(0xffff), HEX); //产生一个随机数字 以免多块板子重名
        if (client.connect(clientId.c_str()))
        {
            Serial.println("connected");
            client.publish("outTopic", "hello world"); //链接成功后 会发布这个主题和语句
            client.subscribe("inTopic");               //这个是你让板子订阅的主题（接受该主题的消息）
        }
        else
        {
            Serial.print("failed, rc=");
            Serial.print(client.state());
            Serial.println(" try again in 5 seconds");
            delay(5000);
        }
    }
}
