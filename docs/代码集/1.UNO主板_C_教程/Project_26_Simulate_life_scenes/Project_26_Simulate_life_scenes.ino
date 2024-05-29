//**********************************************************************************
/*  
 * 名称   : Simulate_life_scenes
 * 功能   : 多种传感器和模块组合模拟生活场景
 * 作者   : http://www.keyes-robot.com/ 
*/
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int val1 = 0;
int val2 = 0;
int val3 = 0;
int val4 = 0;
int val5 = 0;

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(4, INPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(10, OUTPUT);
  pinMode(12, OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void loop() {
  val1=analogRead(A0);
  val2=analogRead(A1);
  val3=analogRead(A2);
  val4=digitalRead(2);
  val5=digitalRead(4);
  Serial.print("water_volume:  ");
  Serial.print(val1);
  Serial.print("   sound_volume:  ");
  Serial.println(val2);
  if (val1 > 250) {
    digitalWrite(10, HIGH);
    digitalWrite(12, HIGH);
    delay(200);
    digitalWrite(10, LOW);
    digitalWrite(12, LOW);
    delay(200);
  }
  else{
    digitalWrite(10, LOW);
    digitalWrite(12, LOW);
  }
  if (val2 > 250) {
    digitalWrite(12, HIGH);
    delay(5000);
  }
  else{
    digitalWrite(12, LOW);
  }
  if (val3 > 300) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Val:");
    lcd.setCursor(5, 0);
    lcd.print(val3);
    lcd.setCursor(0, 1);
    lcd.print("Smoke or Gas!");
    digitalWrite(10, HIGH);
    delay(200);
    digitalWrite(10, LOW);
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
    digitalWrite(10, LOW);
    delay(200);
  }
  if (val4 == 1) {
    digitalWrite(10, HIGH);
    delay(200);
    digitalWrite(10, LOW);
    delay(200);
  }
  else{
    digitalWrite(10, LOW);
  }
  if (val5 == 0) {
    digitalWrite(10, HIGH);
    digitalWrite(12, HIGH);
    delay(200);
    digitalWrite(10, LOW);
    digitalWrite(12, LOW);
    delay(200);
  }
  else{
    digitalWrite(10, LOW);
    digitalWrite(12, LOW);
  }
}
//**********************************************************************************
