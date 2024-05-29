//**********************************************************************************
/*
 * 名称   : Flowing_Water_Light
 * 功能   : 流水灯
 * 作者   : http://www.keyes-robot.com/ 
*/
byte ledPins[] = {0, 2, 15}; // LED的I/O引脚
int ledCounts; // LED 数量

void setup(){
   ledCounts = sizeof(ledPins);
   for (int i = 0; i < ledCounts; i++) {
     pinMode(ledPins[i], OUTPUT);   // 设置I/O引脚为输出模式
   }
}
void loop(){
   for (int i = 0; i < ledCounts; i++) {
     digitalWrite(ledPins[i], HIGH); // 设置I/O引脚为高，依次点亮led灯
     delay(100); // 延时0.1秒
     digitalWrite(ledPins[i], LOW);  // 设置I/O引脚为低，依次熄灭led灯
   }
   for (int i = ledCounts - 1; i > -1; i--) {
    digitalWrite(ledPins[i], HIGH);
    delay(100);
    digitalWrite(ledPins[i], LOW);
   }  
}
//**********************************************************************************
