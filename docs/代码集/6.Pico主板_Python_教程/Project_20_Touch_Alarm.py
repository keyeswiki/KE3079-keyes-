#导入引脚和时间模块
from machine import Pin 
import time 
  
# 定义电容触摸传感器，led和有源蜂鸣器的引脚
sensor_touch = machine.Pin(16, machine.Pin.IN)
buzzer = machine.Pin(17, machine.Pin.OUT)
led = machine.Pin(18, machine.Pin.OUT)
  
while True: 
      value = sensor_touch.value()
      if value == 1:
          print("1  ALARM! Touch detected!")
          buzzer.value(1)
          led.value(1)
          time.sleep(0.2)
          buzzer.value(0)
          led.value(0)
          time.sleep(0.2)         
      else:
          buzzer.value(0)
          led.value(0)