# 导入machine, Pin, I2C, lcd_api, i2c_lcd, ADC, time, sleep
import machine
import time
from machine import Pin, ADC, I2C 
from lcd_api import LcdApi
from i2c_lcd import I2cLcd
from time import sleep 

I2C_ADDR = 0x27    # 初始化I2C_lcd的地址
totalRows = 2      # I2C_lcd的行
totalColumns = 16   # I2C_lcd的列
  
# 定义模拟气体(MQ-2)传感器，LCD和有源蜂鸣器的引脚
sensor_smoke = ADC(Pin(36))
sensor_smoke.atten(ADC.ATTN_11DB)
sensor_smoke.width(ADC.WIDTH_12BIT)
buzzer = Pin(25, Pin.OUT)
i2c=I2C(0, scl=Pin(22), sda=Pin(21), freq=10000)   # 初始化ESP32的I2C方法

devices = i2c.scan()
if len(devices) == 0:
    print("No i2c device !")
else:
    print('i2c devices found:',len(devices))
for device in devices:
    print("At address: ",hex(device))

lcd = I2cLcd(i2c, I2C_ADDR, totalRows, totalColumns)
adcvalue = 0

while True:
     adcvalue = sensor_smoke.read()
     if adcvalue > 1500:
        lcd.move_to(0, 0)
        lcd.putstr("Val:%d" %(adcvalue))
        lcd.move_to(0, 1)
        lcd.putstr("Smoke!")
        buzzer.value(1)
        time.sleep(0.5)
        lcd.clear()
               
     else:
        lcd.move_to(0, 0)
        lcd.putstr("Val:%d" %(adcvalue))
        lcd.move_to(0, 1)
        buzzer.value(0)
        time.sleep(0.5)
        lcd.putstr("None!!")
        lcd.clear()
