from machine import Pin
import time 

PIN_ANALOG_IN = machine.ADC(26)

while True:
    adcvalue1 = PIN_ANALOG_IN.read_u16()
    voltage = adcvalue1 / 65535.0 * 3.3
    print(" ADC Value: ", adcvalue1, " Voltage: ", voltage, " V")
    time.sleep(0.2) 