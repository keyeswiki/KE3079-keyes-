//**********************************************************************************
/*
 * 名称   : Touch_Avoidance_Sensor
 * 功能   : 读取电容触摸传感器的数值
 * 作者   : http://www.keyes-robot.com/ 
*/
byte val = 0;
#define TouchPin  15   //电容触摸传感器的引脚定义为GPIO15
void setup() {
  Serial.begin(115200);   //波特率设置为115200
  pinMode(TouchPin, INPUT);    //将传感器设置为输入模式
}

void loop() {
  val = digitalRead(TouchPin);    //读取传感器值
  Serial.print(val);    //打印传感器值
  if (val == 1) {    //感应区感应到触摸时，输出高电平
    Serial.print("        ");
    Serial.println("Touch the button");
    delay(100);
  }
  else {    //感应区未感应到触摸时，输出低电平
    Serial.print("        ");
    Serial.println("Loosen the button");
    delay(100);
  }
}
//**********************************************************************************