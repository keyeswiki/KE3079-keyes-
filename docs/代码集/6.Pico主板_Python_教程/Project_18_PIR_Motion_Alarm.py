#导入引脚和时间模块
from machine import Pin 
import time 
 
# 定义人体红外传感器，led和主动蜂鸣器的引脚
sensor_pir = machine.Pin(16, machine.Pin.IN)
buzzer = machine.Pin(17, machine.Pin.OUT)
led = machine.Pin(18, machine.Pin.OUT)
 
while True: 
      if sensor_pir.value():
          print("1  ALARM! Motion detected!")
          buzzer.value(1)
          led.value(1)
          time.sleep(0.2)
          buzzer.value(0)
          led.value(0)
          time.sleep(0.2)         
      else:
          buzzer.value(0)
          led.value(0)