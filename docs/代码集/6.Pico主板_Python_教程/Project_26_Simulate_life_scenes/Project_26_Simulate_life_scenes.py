#导入I2C_LCD,引脚和时间模块 
import time
from machine import I2C, Pin
from I2C_LCD import I2CLcd
  
# 定义水滴传感器，声音传感器，模拟气体(MQ-2)传感器，火焰传感器，LED，LCD和有源蜂鸣器的引脚
sensor_steam = machine.ADC(26)
sensor_sound = machine.ADC(27)
sensor_smoke = machine.ADC(28)
sensor_flame = machine.Pin(16, machine.Pin.IN)
buzzer = machine.Pin(14, machine.Pin.OUT)
led = machine.Pin(15, machine.Pin.OUT)
i2c = I2C(0, sda=Pin(20), scl=Pin(21), freq=400000)
devices = i2c.scan()

adcvalue1 = 0 
adcvalue2 = 0
adcvalue3 = 0
val4 = 0

try:
    if devices != []:
        lcd = I2CLcd(i2c, devices[0], 2, 16)

        while True:
            adcvalue1 = sensor_steam.read_u16()
            adcvalue2 = sensor_sound.read_u16()
            adcvalue3 = sensor_smoke.read_u16()
            val4 = sensor_flame.value()

            lcd.move_to(0, 0)
            lcd.putstr("Val:%d" %(adcvalue3))
            time.sleep(0.2)
            lcd.clear()
            
            print("water_volume: ", adcvalue1, " sound_volume: ", adcvalue2)

            if adcvalue1 > 10000:
                buzzer.value(1)
                led.value(1)
                time.sleep(0.1)
                buzzer.value(0)
                led.value(0)
                time.sleep(0.1)
            else:   
                buzzer.value(0)
                led.value(0)
             
            if adcvalue2 > 9000:
                led.value(1)
                time.sleep(5)
            else:    
                led.value(0)
            
            if adcvalue3 > 12000:
                lcd.move_to(0, 1)
                lcd.putstr("Smoke!")
                buzzer.value(1)
            else:
                lcd.move_to(0, 1)
                lcd.putstr("None!!")
                buzzer.value(0) 
               
            if val4 == 0:
                buzzer.value(1)
                led.value(1)
                time.sleep(0.1)
                buzzer.value(0)
                led.value(0)
                time.sleep(0.1)         
            else:
                buzzer.value(0)
                led.value(0)
        
    else:
         print("No address found")
except:
    pass