#导入引脚和时间模块 
from machine import Pin  
import time   
  
# 定义光敏传感器，led的引脚
sensor_photosensor = machine.ADC(26)
led = machine.Pin(18, machine.Pin.OUT)
  
while True: 
      adcvalue = sensor_photosensor.read_u16()
      if adcvalue > 30000:
          led.value(0)
          print(adcvalue, "LED OFF!")
          time.sleep(0.2)
      else:
          led.value(1)
          print(adcvalue, "LED ON!")
          time.sleep(0.2)