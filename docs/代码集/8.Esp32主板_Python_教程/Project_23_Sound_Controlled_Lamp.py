# 导入 Pin，ADC 和 time 库.
from machine import ADC, Pin
import time  

# 定义声音传感器和led的引脚. 
sensor_sound = ADC(Pin(36))
sensor_sound.atten(ADC.ATTN_11DB)
sensor_sound.width(ADC.WIDTH_12BIT)
led = Pin(2, Pin.OUT)
 
while True:  
      adcvalue = sensor_sound.read()
      if adcvalue > 500:
          print(adcvalue, "LED ON!") 
          led.value(1)
          time.sleep(5)         
      else:
          led.value(0)
          print(adcvalue, "LED OFF!")
          time.sleep(0.2)