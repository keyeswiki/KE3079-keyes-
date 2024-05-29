//*********************************************************************************
/*
 * 名称   : Traffic_Lights
 * 功能   : 模拟交通灯
 * 作者   : http://www.keyes-robot.com/ 
*/
#define PIN_LED_RED  16     // 红色LED连接到数字管脚GPIO16.
#define PIN_LED_YELLOW  17  // 黄色LED连接到数字管脚GPIO17.
#define PIN_LED_GREEN  18  // 绿色LED连接数字管脚GPIO18.

void setup() {
  pinMode(PIN_LED_RED, OUTPUT);  // 将红色LED引脚设置为输出模式
  pinMode(PIN_LED_YELLOW, OUTPUT);  // 将黄色LED引脚设置为输出模式
  pinMode(PIN_LED_GREEN, OUTPUT);  // 将绿色LED的引脚设置为输出模式
}

void loop(){
  digitalWrite(PIN_LED_GREEN, HIGH); // 点亮绿色LED
  delay(5000); // 延时5秒
  digitalWrite(PIN_LED_GREEN, LOW); // 熄灭绿色LED
  for(int i=0;i<3;i++){// 闪烁3次
    digitalWrite(PIN_LED_YELLOW, HIGH); //点亮黄色LED
    delay(500); // 延时0.5秒
    digitalWrite(PIN_LED_YELLOW, LOW); // 熄灭黄色LED
    delay(500); // 延时0.5秒
  } 
  digitalWrite(PIN_LED_RED, HIGH); // 点亮红色LED
  delay(5000); // 延时5秒
  digitalWrite(PIN_LED_RED, LOW); // 熄灭红色LED
}
//*********************************************************************************
