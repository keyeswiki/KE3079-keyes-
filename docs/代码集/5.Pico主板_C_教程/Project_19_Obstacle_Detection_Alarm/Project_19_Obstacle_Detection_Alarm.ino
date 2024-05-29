//**********************************************************************************
/*  
 * 名称   : Obstacle_Detection_Alarm
 * 功能   : 避障传感器控制LED和蜂鸣器
 * 作者   : http://www.keyes-robot.com/ 
*/
byte item = 0;

void setup() {
  Serial.begin(115200); //设置串口波特率为115200
  pinMode(16, INPUT);  //避障传感器连接GPIO16上，并设置为输入模式
  pinMode(17, OUTPUT); //将有源蜂鸣器连接到GPIO17上，并设置为输出模式
  pinMode(18, OUTPUT);  //将LED连接到GPIO18上，并设置为输出模式
}

void loop() {
  item = digitalRead(16); //读取避障传感器输出的数字信号
  Serial.println(item);  //串口打印避障传感器输出的数字信号
  if (item == 0) {  //避障传感器检测到障碍物
    digitalWrite(17, HIGH); //打开蜂鸣器
    digitalWrite(18, HIGH);  //打开LED
    delay(500);  //延迟 500ms
    digitalWrite(17, LOW);  //关闭蜂鸣器
    digitalWrite(18, LOW);  //关闭LED
    delay(500);  //延迟 500ms
  } else {  //没有检测到任何障碍物
    digitalWrite(17, LOW); //关闭蜂鸣器
    digitalWrite(18, LOW);  //关闭LED
  }
}
//**********************************************************************************