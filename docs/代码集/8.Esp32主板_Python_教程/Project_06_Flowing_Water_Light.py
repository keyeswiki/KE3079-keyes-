from machine import Pin
import time 

# 使用阵列定义3个连接led的GPIO端口，便于操作。
pins = [0, 2, 15]
# 使用两个for循环,分别从左到右打开led，然后从右到左返回.
def showLed():
    for pin in pins:
        print(pin) 
        led = Pin(pin, Pin.OUT)
        led.value(1)
        time.sleep_ms(100)
        led.value(0)
        time.sleep_ms(100)        
    for pin in reversed(pins):
        print(pin)
        led = Pin(pin, Pin.OUT)
        led.value(1)
        time.sleep_ms(100)
        led.value(0)
        time.sleep_ms(100)
          
while True:
    showLed()