//**********************************************************************************
/*
 * 名称   : Flame_Sensor
 * 功能   : 读取火焰传感器的数值
 * 作者   : http://www.keyes-robot.com/  
*/
int val1 = 0;   //设置value1为0
int val2 = 0;   //设置value2为0
#define PIN_ANALOG_IN 26   //火焰传感器的模拟引脚定义为GPIO26
#define PIN_DIGITAL_IN 16   //火焰传感器的数字引脚定义为GPIO16

void setup() {
  Serial.begin(115200);   //波特率设置为115200
  pinMode(PIN_ANALOG_IN, INPUT);    //将传感器的模拟引脚设置为输入模式
  pinMode(PIN_DIGITAL_IN, INPUT);    //将传感器的数字引脚设置为输入模式
}

void loop() {
  val1 = analogRead(PIN_ANALOG_IN);    //读取传感器的模拟信号
  val2 = digitalRead(PIN_DIGITAL_IN);    //读取传感器的数字信号
  Serial.print("D0:  ");    //打印字符串D0:
  Serial.print(val2);    //打印且显示val2数值
  if (val2 == 0) {    //检测到火焰，输出低电平
    Serial.print("  On fire!");
    Serial.print("  A0:  ");
    Serial.println(val1);
    delay(100);
  }
  else {    //未检测到火焰，输出高电平
    Serial.println("  All going well");
    delay(100);
  }
}
//**********************************************************************************