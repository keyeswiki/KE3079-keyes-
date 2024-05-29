#导入I2C_LCD,引脚和时间模块 
import time
from machine import I2C, Pin
from I2C_LCD import I2CLcd 
   
# 定义模拟气体(MQ-2)传感器，LCD和有源蜂鸣器的引脚
sensor_smoke = machine.ADC(26)
buzzer = machine.Pin(17, machine.Pin.OUT)
i2c = I2C(1, sda=Pin(14), scl=Pin(15), freq=400000)
devices = i2c.scan()
adcvalue = 0

try:
    if devices != []:
        lcd = I2CLcd(i2c, devices[0], 2, 16)
        while True:
            adcvalue = sensor_smoke.read_u16()
            lcd.move_to(0, 0)
            lcd.putstr("Val:%d" %(adcvalue))
            time.sleep(0.5)
            lcd.clear()
             
            if adcvalue > 35000:
               lcd.move_to(0, 1)
               lcd.putstr("Smoke!")
               buzzer.value(1)
               
            else:
               lcd.move_to(0, 1)
               lcd.putstr("None!!") 
               buzzer.value(0)
    else:
         print("No address found")
except:
    pass