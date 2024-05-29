//**********************************************************************************
/*  
 * 名称   : Sound Controlled Lamp
 * 功能   : 声音传感器控制LED
 * 作者   : http://www.keyes-robot.com/ 
*/
int item = 0;  //设置item为0
int PIN_ANALOG_IN = A0;   //声音传感器的引脚定义为A0

void setup() {
  Serial.begin(9600); //设置串口波特率为9600
  pinMode(PIN_ANALOG_IN, INPUT);    //将传感器的引脚设置为输入模式
  pinMode(5, OUTPUT);  // 设置led引脚为输出模式.
}

void loop() {
  item = analogRead(PIN_ANALOG_IN);    //读取传感器的模拟信号
  Serial.print(item);  //串口打印声音传感器输出的模拟信号
  if (item > 200) {  //模拟值大于200
    digitalWrite(5, HIGH);  //打开LED
    Serial.println("  led on");
    delay(5000);  //延迟 5s
  } else {  //模拟值小于等于200
    digitalWrite(5, LOW);  //关闭LED
    Serial.println("  led off");
  }
}
//**********************************************************************************