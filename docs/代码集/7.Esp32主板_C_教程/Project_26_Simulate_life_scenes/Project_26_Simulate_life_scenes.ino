//**********************************************************************************
/*  
 * 名称   : Simulate_life_scenes
 * 功能   : 多种传感器和模块组合模拟生活场景
 * 作者   : http://www.keyes-robot.com/ 
*/
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

// LCD连接的引脚：sda--io21, scl--io22
LiquidCrystal_I2C lcd(0x27, 16, 2);

int val1 = 0;
int val2 = 0;
int val3 = 0;
int val4 = 0;
int val5 = 0;

void setup() {
  Serial.begin(115200);
  pinMode(15, INPUT);
  pinMode(2, INPUT);
  pinMode(36, INPUT);
  pinMode(39, INPUT);
  pinMode(34, INPUT);
  pinMode(0, OUTPUT);
  pinMode(4, OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void loop() {
  val1=analogRead(34);
  val2=analogRead(39);
  val3=analogRead(36);
  val4=digitalRead(15);
  val5=digitalRead(2);
  Serial.print("water_volume:  ");
  Serial.print(val1);
  Serial.print("   sound_volume:  ");
  Serial.println(val2);

  if (val1 > 300) {
    digitalWrite(0, HIGH);
    digitalWrite(4, HIGH);
    delay(200);
    digitalWrite(0, LOW);
    digitalWrite(4, LOW);
    delay(200);
  }
  else{
    digitalWrite(0, LOW);
    digitalWrite(4, LOW);
  }

  if (val2 > 200) {
    digitalWrite(4, HIGH);
    delay(5000);
  }
  else{
    digitalWrite(4, LOW);
  }

  if (val3 > 300) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Val:");
    lcd.setCursor(5, 0);
    lcd.print(val3); 
    lcd.setCursor(0, 1);
    lcd.print("Smoke or Gas!");
    digitalWrite(0, HIGH);
    delay(200);
    digitalWrite(0, LOW);
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
    digitalWrite(0, LOW);
    delay(200);

  }
  if (val4 == 1) {
    digitalWrite(0, HIGH);
    delay(200);
    digitalWrite(0, LOW);
    delay(200);
  }
  else{
    digitalWrite(0, LOW);
  }
  
  if (val5 == 0) {
    digitalWrite(0, HIGH);
    digitalWrite(4, HIGH);
    delay(200);
    digitalWrite(0, LOW);
    digitalWrite(4, LOW);
    delay(200);
  }
  else{
    digitalWrite(0, LOW);
    digitalWrite(4, LOW);
  }
}
//**********************************************************************************
