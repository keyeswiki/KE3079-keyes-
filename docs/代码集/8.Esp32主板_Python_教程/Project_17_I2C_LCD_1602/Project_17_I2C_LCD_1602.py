# 导入machine, Pin, I2C, lcd_api, i2c_lcd, sleep
import machine
from machine import Pin, I2C
from lcd_api import LcdApi
from i2c_lcd import I2cLcd
from time import sleep 

I2C_ADDR = 0x27    # 初始化I2C_lcd的地址
totalRows = 2      # I2C_lcd的行
totalColumns = 16   # I2C_lcd的列

#i2c = I2C(0, scl=Pin(5), sda=Pin(4), freq=10000)   # 初始化ESP8266的I2C方法

i2c=I2C(0, scl=Pin(22), sda=Pin(21), freq=10000)   # 初始化ESP32的I2C方法

devices = i2c.scan()
if len(devices) == 0:
    print("No i2c device !")
else:
    print('i2c devices found:',len(devices))
for device in devices:
    print("At address: ",hex(device))

lcd = I2cLcd(i2c, I2C_ADDR, totalRows, totalColumns)

while True:
    lcd.move_to(2,0)
    lcd.putstr("Hello World!")
    lcd.move_to(2,1)
    lcd.putstr("Hello Keyes!")
