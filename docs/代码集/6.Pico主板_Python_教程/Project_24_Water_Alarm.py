#导入引脚和时间模块
from machine import Pin 
import time  
 
# 定义水滴传感器，led和有源蜂鸣器的引脚
sensor_steam = machine.ADC(26)
buzzer = machine.Pin(17, machine.Pin.OUT)
led = machine.Pin(18, machine.Pin.OUT)
  
while True:  
      adcvalue = sensor_steam.read_u16()
      if adcvalue > 30000:
          print(adcvalue, "Buzzer sounds and led blinking!")
          buzzer.value(1)
          led.value(1)
          time.sleep(0.5)
          buzzer.value(0)
          led.value(0)
          time.sleep(0.5)         
      else:
          print(adcvalue, "Buzzer won't sound and led off!")
          buzzer.value(0)
          led.value(0)
          time.sleep(0.5)