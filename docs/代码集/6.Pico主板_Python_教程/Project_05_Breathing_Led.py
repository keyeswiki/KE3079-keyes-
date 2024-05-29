#MicroPython实现Raspberry Pi Pico板控制LED实现呼吸灯的程序示例
import time 
from machine import Pin,PWM
PWM_PulseWidth=0
#利用外接LED，构建PWM对象PWM LED
pwm_LED=PWM(Pin(25))
#设置LED的PWM频率
pwm_LED.freq(500)
while True:
    while PWM_PulseWidth<65535:
        PWM_PulseWidth=PWM_PulseWidth+50
        time.sleep_ms(1)   #延时 1 毫秒 
        pwm_LED.duty_u16(PWM_PulseWidth)
    while PWM_PulseWidth>0:
        PWM_PulseWidth=PWM_PulseWidth-50
        time.sleep_ms(1)
        pwm_LED.duty_u16(PWM_PulseWidth)
