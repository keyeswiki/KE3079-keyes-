from machine import ADC, Pin
import time  

PIN_ANALOG_IN = ADC(Pin(36))
PIN_ANALOG_IN.atten(ADC.ATTN_11DB)
PIN_ANALOG_IN.width(ADC.WIDTH_12BIT)

while True:
    adcvalue1 = PIN_ANALOG_IN.read()
    voltage = adcvalue1 / 4095.0 * 3.3
    print(" ADC Value: ", adcvalue1, " Voltage: ", voltage, " V")
    time.sleep(0.1)