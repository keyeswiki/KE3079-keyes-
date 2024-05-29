from machine import Pin
import time

PIR = Pin(15, Pin.IN)
while True:
    value = PIR.value()
    print(value, end = " ")
    if value == 1:
        print("Somebody is in this area!")
    else:
        print("No one!")
    time.sleep(0.1)