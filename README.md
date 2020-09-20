# arduino_wifi

## 芯片和配件

* Arduino UNO
* Esp 8266-01s
* MG995

## 依赖库

* [Arduino Client for MQTT](https://github.com/knolleary/pubsubclient/)
* [WiFiEsp](https://github.com/bportaluri/WiFiEsp)

## 连接

### Arduino -- Esp 8266-01s

| Esp-01s | Arduino      |
| ------- | ------------ |
| 3v3     | 3v3          |
| GND     | GND          |
| Tx      | 6（soft Rx） |
| Rx      | 7（soft Tx） |

### Adruino -- MG996

| MG996  | Arduino |
| ------ | ------- |
| Red    | 5v      |
| Black  | GND     |
| Yellow | 9       |

## MQTT

```bash
# 安装客户端
brew install mosquitto

# 终端1 订阅
mosquitto_sub -h 39.96.177.143 -t  "outTopic"  -v

# 终端2 发送消息
mosquitto_pub -h 39.96.177.143 -t "inTopic"  -m  "inTopic mqtt"
```