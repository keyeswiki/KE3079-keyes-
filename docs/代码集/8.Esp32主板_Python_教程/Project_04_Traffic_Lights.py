from machine import Pin
import time

led_red = Pin(0, Pin.OUT)  # 创建引脚GPIO0为红色led对象，设置引脚GPIO0为输出模式
led_yellow = Pin(2, Pin.OUT)  # 创建引脚GPIO2为黄色led对象，设置引脚GPIO2为输出模式
led_green = Pin(15, Pin.OUT) # 创建引脚GPIO15为绿色led对象，设置引脚GPIO15为输出模式
while True:
    led_green.value(1)  # 设置绿色led灯亮
    time.sleep(5)   # 延时 5秒
    led_green.value(0) # 设置绿色led关闭 
    led_yellow.value(1)
    time.sleep(0.5)
    led_yellow.value(0)
    time.sleep(0.5)
    led_yellow.value(1)
    time.sleep(0.5)
    led_yellow.value(0)
    time.sleep(0.5)
    led_yellow.value(1)
    time.sleep(0.5)
    led_yellow.value(0)
    time.sleep(0.5)
    led_red.value(1)
    time.sleep(5) 
    led_red.value(0) 