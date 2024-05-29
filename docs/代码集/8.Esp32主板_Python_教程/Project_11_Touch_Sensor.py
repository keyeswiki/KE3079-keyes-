from machine import Pin
import time
  
Touch = Pin(15, Pin.IN)
while True:
    value = Touch.value()
    print(value, end = " ")
    if value == 1:
        print("Touch the button")
    else:
        print("Loosen the button")
    time.sleep(0.1)