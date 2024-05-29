#导入引脚和时间模块
from machine import Pin 
import time 
 
# 定义避障传感器，led和有源蜂鸣器的引脚
sensor_avoid = machine.Pin(16, machine.Pin.IN)
buzzer = machine.Pin(17, machine.Pin.OUT)
led = machine.Pin(18, machine.Pin.OUT)
  
while True: 
      value = sensor_avoid.value()
      if value == 0:
          print("0  ALARM! Obstacles detected!")
          buzzer.value(1)
          led.value(1)
          time.sleep(0.2)
          buzzer.value(0)
          led.value(0)
          time.sleep(0.2)         
      else:
          buzzer.value(0)
          led.value(0)