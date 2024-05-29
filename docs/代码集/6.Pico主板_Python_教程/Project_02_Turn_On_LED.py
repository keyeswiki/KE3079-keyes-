from machine import Pin
import time

led = Pin(16, Pin.OUT)   # 从引脚GPIO16创建LED对象，设置引脚GPIO16为输出模式

try:
    while True:
        led.value(1)    # 设置led开启
except:
    pass