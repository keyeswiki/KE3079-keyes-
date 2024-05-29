//**********************************************************************************
/*  
 * 名称   : I2C_LCD_1602
 * 功能   : I2C LCD 1602 显示屏显示字符串
 * 作者   : http://www.keyes-robot.com/ 
*/
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2); // 将显示16字符,2行的LCD设置地址为0x27

void setup()
{
lcd.init(); // 初始化LCD
// 打印信息到LCD屏幕.
lcd.backlight();
lcd.setCursor(2,0);
lcd.print("Hello World!");
lcd.setCursor(2,1);
lcd.print("Hello Keyes!");
}
void loop()
{
}
//********************************************************************************
