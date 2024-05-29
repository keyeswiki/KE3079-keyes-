//*************************************************************************************
/*
 * 名称   : Turn_On_LED
 * 功能   : 点亮 LED
 * 作者   : http://www.keyes-robot.com/
*/
int ledPin = 3;  // 定义LED的引脚为D3.

void setup() {
  pinMode(ledPin, OUTPUT);  // 设置led引脚为输出模式.
}

void loop() {
  digitalWrite(ledPin, HIGH); //  点亮LED.
}
//*************************************************************************************
