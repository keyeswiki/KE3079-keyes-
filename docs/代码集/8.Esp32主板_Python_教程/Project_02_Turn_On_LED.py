from machine import Pin
import time

led = Pin(15, Pin.OUT)   # 创建引脚GPIO15为LED对象，设置引脚GPIO15为输出模式

while True:

    led.value(1)    # led点亮