//**********************************************************************************
/*  
 * 名称   : Simulate_life_scenes
 * 功能   : 多种传感器和模块组合模拟生活场景
 * 作者   : http://www.keyes-robot.com/ 
*/
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

// LCD连接的引脚：sda--GP4, scl--GP5
LiquidCrystal_I2C lcd(0x27, 16, 2);

int val1 = 0;
int val2 = 0;
int val3 = 0;
int val4 = 0;

void setup() {
  Serial.begin(115200);
  pinMode(18, INPUT);
  pinMode(26, INPUT);
  pinMode(27, INPUT);
  pinMode(28, INPUT);
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void loop() {
  val1=analogRead(26);
  val2=analogRead(27);
  val3=analogRead(28);
  val4=digitalRead(18);
  Serial.print("water_volume:  ");
  Serial.print(val1);
  Serial.print("   sound_volume:  ");
  Serial.println(val2);
 
  if (val1 > 250) {
    digitalWrite(16, HIGH);
    digitalWrite(15, HIGH);
    delay(200);
    digitalWrite(16, LOW);
    digitalWrite(15, LOW);
    delay(200);
  }
  else{
    digitalWrite(16, LOW);
    digitalWrite(15, LOW);
  }
  if (val2 > 100) {
    digitalWrite(15, HIGH);
    delay(5000);
  }
  else{
    digitalWrite(15, LOW);
  }
  if (val3 > 300) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Val:");
    lcd.setCursor(5, 0);
    lcd.print(val3);
    lcd.setCursor(0, 1);
    lcd.print("Smoke or Gas!");
    digitalWrite(16, HIGH);
    delay(200);
    digitalWrite(16, LOW);
    delay(200);
  }
  else{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Val:");
    lcd.setCursor(5, 0);
    lcd.print(val3);
    lcd.setCursor(0, 1);
    lcd.print("None!");
    digitalWrite(16, LOW);
    delay(200);
  }
  if (val4 == 0) {
    digitalWrite(16, HIGH);
    digitalWrite(15, HIGH);
    delay(200);
    digitalWrite(16, LOW);
    digitalWrite(15, LOW);
    delay(200);
  }
  else{
    digitalWrite(16, LOW);
    digitalWrite(15, LOW);
  }
}
//**********************************************************************************
