//*************************************************************************************
/*
 * 名称   : Turn_On_LED
 * 功能   : 点亮 LED
 * 作者   : http://www.keyes-robot.com/
*/
#define PIN_LED 16   //定义led引脚为GPIO16

void setup() {
  pinMode(PIN_LED, OUTPUT);  // 设置led引脚为输出模式.
}

void loop() {
  digitalWrite(PIN_LED, HIGH); //  点亮LED.
}
//*************************************************************************************
