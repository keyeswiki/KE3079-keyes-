//**********************************************************************************
/*
 * 名称   : Breathing_LED
 * 功能   : 使用PWM让led灯像呼吸一样忽明忽暗。
 * 作者   : http://www.keyes-robot.com/
*/
#define PIN_LED   15   //定义LED的引脚为GPIO15
#define CHN       0   //定义PWM通道
#define FRQ       1000  //定义PWM频率
#define PWM_BIT   8     //定义PWM精确度
void setup() {
  ledcSetup(CHN, FRQ, PWM_BIT); //初始化PWM通道
  ledcAttachPin(PIN_LED, CHN);  //将led引脚连接到pwm通道
}

void loop() {
  for (int i = 0; i < 255; i++) { //使光线逐渐变亮
    ledcWrite(CHN, i);
    delay(10);
  }
  for (int i = 255; i > -1; i--) {  //使光线逐渐变暗
    ledcWrite(CHN, i);
    delay(10);
  }
}      
//**********************************************************************************
