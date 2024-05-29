from machine import ADC, Pin
import time 

PIN_ANALOG_IN = ADC(Pin(36))
PIN_DIGITAL_IN = Pin(15, Pin.IN)
PIN_ANALOG_IN.atten(ADC.ATTN_11DB)
PIN_ANALOG_IN.width(ADC.WIDTH_12BIT)

while True:
    adcvalue1 = PIN_ANALOG_IN.read()
    voltage = adcvalue1 / 4095.0 * 5.0
    value2 = PIN_DIGITAL_IN.value()
    print("D0: ", end = " ")
    print(value2, end = " ")
    if value2 == 0:
        print(" On fire!", end = " ")
        print(" ADC Value: ", adcvalue1, " Voltage: ", voltage, " V")
    else:
        print(" All going well")
    time.sleep(0.1)