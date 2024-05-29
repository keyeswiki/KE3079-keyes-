//**********************************************************************************
/*  
 * 名称   : PIR_Motion_Alarm
 * 功能   : PIR控制LED和蜂鸣器
 * 作者   : http://www.keyes-robot.com/ 
*/
byte item = 0;

void setup() {
  Serial.begin(115200); //设置串口波特率为115200
  pinMode(15, INPUT);  //PIR运动传感器连接GPIO15上，并设置为输入模式
  pinMode(2, OUTPUT);  //将LED连接到GPIO2上，并设置为输出模式
  pinMode(0, OUTPUT); //将有源蜂鸣器连接到GPIO0上，并设置为输出模式
}

void loop() {
  item = digitalRead(15); //读取人体红外热释传感器输出的数字信号
  Serial.println(item);  //串口打印人体红外热释传感器输出的数字信号
  if (item == 1) {  //运动检测
    digitalWrite(0, HIGH); //打开蜂鸣器
    digitalWrite(2, HIGH);  //打开LED
    delay(500);  //延迟 500ms
    digitalWrite(0, LOW);  //关闭蜂鸣器
    digitalWrite(2, LOW);  //关闭LED
    delay(500);  //延迟 500ms
  } else {  //没有检测到任何信号或数据
    digitalWrite(0, LOW); //关闭蜂鸣器
    digitalWrite(2, LOW);  //关闭LED
  }
}
//**********************************************************************************