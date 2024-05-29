//*************************************************************************************
/*
 * 名称   : LED_Blinking
 * 功能   : LED 闪烁1秒
 * 作者   : http://www.keyes-robot.com/
*/
#define PIN_LED 15  // 定义LED的引脚为GPIO15.

void setup(){
  pinMode(PIN_LED, OUTPUT);// 设置led引脚为输出模式.
}

void loop(){
  digitalWrite(PIN_LED, HIGH); // 点亮LED.
  delay(1000); // 等待1秒.
  digitalWrite(PIN_LED, LOW); // 熄灭LED.
  delay(1000); // 等待1秒
}
//*************************************************************************************
