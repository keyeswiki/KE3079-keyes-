# 导入 Pin 和 time 库.
from machine import Pin
import time

# 定义人体红外传感器，led和有源蜂鸣器的引脚. 
sensor_pir = Pin(15, Pin.IN)
led = Pin(2, Pin.OUT)
buzzer = Pin(0, Pin.OUT)

while True: 
      if sensor_pir.value():
          buzzer.value(1)
          led.value(1)
          time.sleep(0.5)
          buzzer.value(0)
          led.value(0)
          time.sleep(0.5)         
      else:
          buzzer.value(0)
          led.value(0)