#导入引脚和时间模块 
from machine import Pin  
import time   
   
# 定义声音传感器，led的引脚
sensor_sound = machine.ADC(26)
led = machine.Pin(18, machine.Pin.OUT)
  
while True: 
      adcvalue = sensor_sound.read_u16()
      if adcvalue > 10000:
          print(adcvalue, "LED ON!")
          led.value(1)
          time.sleep(5)         
      else:
          led.value(0)
          print(adcvalue, "LED OFF!")
          time.sleep(0.2)