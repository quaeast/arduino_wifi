#include <Servo.h> //此程序的功能是将舵机从0到180度然后从180到0度不停的旋转
Servo myservo;  //创建一个舵机控制对象
                          // 使用Servo类最多可以控制8个舵机
int pos = 0;    // 该变量用与存储舵机角度位置
int val;
void setup() 
{ 
  myservo.attach(9);  // 该舵机由arduino第九脚控制
} 
void loop() 
{ 
  myservo.write(180);
  delay(10000);
  myservo.write(0);
  delay(10000);
}
