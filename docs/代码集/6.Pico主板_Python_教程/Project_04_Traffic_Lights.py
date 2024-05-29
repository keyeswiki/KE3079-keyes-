from machine import Pin
import time

led_red = machine.Pin(16, machine.Pin.OUT)  # 从引脚GPIO16创建红色led对象，设置引脚GPIO16为输出模式
led_yellow = machine.Pin(17, machine.Pin.OUT) # 从引脚GPIO17创建黄色led对象，设置引脚GPIO17为输出模式
led_green = machine.Pin(18, machine.Pin.OUT) # 从引脚GPIO18创建绿色led对象，设置引脚18输出模式

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