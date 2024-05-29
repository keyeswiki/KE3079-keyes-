//**********************************************************************************
/*  
 * 名称   : Smoke_Alarm
 * 功能   : 烟雾或可燃性气体控制蜂鸣器和LCD
 * 作者   : http://www.keyes-robot.com/ 
*/
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

// LCD连接的引脚：sda--io21, scl--io22
LiquidCrystal_I2C lcd(0x27,16,2); // 将显示16字符,2行的LCD设置地址为0x27
int item = 0;

void setup() {
  Serial.begin(115200);
  lcd.init(); // 初始化LCD
  lcd.backlight(); // 打开LCD背光
  lcd.clear();
  pinMode(36, INPUT);  //模拟气体(MQ-2)传感器连接GPIO36上，并设置为输入模式
  pinMode(25, OUTPUT); //将有源蜂鸣器连接到GPIO25上，并设置为输出模式
}

void loop() {
  item = analogRead(36); //读取模拟气体(MQ-2)传感器输出的模拟信号
  Serial.println(item);  //串口打印模拟气体(MQ-2)传感器输出的模拟信号
  lcd.setCursor(0, 0);
  lcd.print("val: ");
  lcd.setCursor(6, 0);
  lcd.print(item);
  delay(500);
  lcd.clear();
  if (item > 800) {  //检测到烟雾或可燃性气体，模拟值大于800
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Smoke or Gas!");
    digitalWrite(25, HIGH); //打开蜂鸣器   
    
  } else {  //烟雾或可燃性气体模拟值小于800
    lcd.clear();   
    lcd.setCursor(0, 1);
    lcd.print("None!");
    digitalWrite(25, LOW); //关闭蜂鸣器  

  }
}
//**********************************************************************************