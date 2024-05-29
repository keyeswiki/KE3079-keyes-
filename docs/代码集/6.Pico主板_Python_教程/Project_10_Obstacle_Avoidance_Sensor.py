from machine import Pin
import time

Avoid = Pin(16, Pin.IN)
while True:
    value = Avoid.value()
    print(value, end = " ")
    if value == 0:
        print("There are obstacles")
    else:
        print("All going well")
    time.sleep(0.1)