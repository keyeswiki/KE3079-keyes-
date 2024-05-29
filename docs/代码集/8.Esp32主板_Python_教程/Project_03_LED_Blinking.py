from machine import Pin
import time

led = Pin(15, Pin.OUT)   # 创建引脚GPIO15为LED对象，设置引脚GPIO15为输出模式

try:
    while True:
        led.value(1)    # LED点亮
        time.sleep(0.5) # 延时 0.5秒
        led.value(0)    # LED熄灭
        time.sleep(0.5) # 延时 0.5秒
except:
    pass