from machine import Pin
import machine
import time

PIN_ANALOG_IN = machine.ADC(26)
PIN_DIGITAL_IN = Pin(16, Pin.IN)

while True:
    adcvalue1 = PIN_ANALOG_IN.read_u16()
    voltage = adcvalue1 / 65535.0 * 5.0
    value2 = PIN_DIGITAL_IN.value()
    print("D0: ", end = " ")
    print(value2, end = " ")
    if value2 == 0:
        print(" On fire!", end = " ")
        print(" ADC Value: ", adcvalue1, " Voltage: ", voltage, " V")
    else:
        print(" All going well")
    time.sleep(0.1)