# 导入 Pin，ADC 和 time 库.
from machine import ADC, Pin
import time

# 定义光敏传感器和led的引脚.  
sensor_photosensor = ADC(Pin(36))
sensor_photosensor.atten(ADC.ATTN_11DB)
sensor_photosensor.width(ADC.WIDTH_12BIT)
led = Pin(2, Pin.OUT)
 
while True: 
      adcvalue = sensor_photosensor.read()
      if adcvalue > 1000:
         led.value(0)
         print(adcvalue, "LED OFF!")
         time.sleep(0.2)         
      else:
         led.value(1)
         print(adcvalue, "LED ON!") 
         time.sleep(0.2)