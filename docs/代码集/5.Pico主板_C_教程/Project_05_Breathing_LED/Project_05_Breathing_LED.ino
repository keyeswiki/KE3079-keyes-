//**********************************************************************************
/*
 * 名称   : Breathing_LED
 * 功能   : 使用PWM让led灯像呼吸一样忽明忽暗。
 * 作者   : http://www.keyes-robot.com/
*/
#define PIN_LED  16  // 定义LED的引脚为GPIO16.

void setup() {
  pinMode(PIN_LED,OUTPUT); // 设置LED引脚为输出模式.
}

void loop(){
  for (int value = 0 ; value < 255; value=value+1) {  //使灯光渐亮
    analogWrite(PIN_LED, value);
    delay(10);
  }
  for (int value = 255; value > 0; value=value-1) {  //使灯光渐暗
    analogWrite(PIN_LED, value);
    delay(10);
  } 
}      
//**********************************************************************************
