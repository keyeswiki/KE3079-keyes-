//**********************************************************************************
/*  
 * 名称   : Night_Lamp
 * 功能   : 光敏传感器控制LED
 * 作者   : http://www.keyes-robot.com/ 
*/
int item = 0;
void setup() {
  Serial.begin(115200); //设置串口波特率为115200
  pinMode(26, INPUT);    //将光敏传感器连接到GPIO26上，并设置为输入模式
  pinMode(18, OUTPUT);  //将LED连接到GPIO18上，并设置为输出模式
}

void loop() {
  item = analogRead(26);   //光敏传感器读取光照强度，将读取到模拟值赋予变量Item
  Serial.println(item);  //串口打印光敏传感器的模拟信号
  if (item > 200) {  //模拟值大于200
    digitalWrite(18, LOW);  //关闭LED
  } else {  //否则，模拟值不大于200
    digitalWrite(18, HIGH);  //打开LED
  }
}
//**********************************************************************************