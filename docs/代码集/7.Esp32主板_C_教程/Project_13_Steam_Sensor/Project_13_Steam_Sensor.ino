//**********************************************************************************
/*
 * 名称   : Steam_Sensor
 * 功能   : 读取水滴传感器的值，将其转化为ADC、DAC和电压值
 * 作者   : http://www.keyes-robot.com/  
*/
#define PIN_ANALOG_IN 36   //水滴传感器的模拟引脚定义为GPIO36

void setup() {
  Serial.begin(115200);   //波特率设置为115200
  pinMode(PIN_ANALOG_IN, INPUT);    //将传感器的引脚设置为输入模式
}

void loop() {
  int adcVal = analogRead(PIN_ANALOG_IN);    //使用analogRead()函数获取ADC值
  int dacVal = map(adcVal, 0, 4095, 0, 255);   //使用map()函数将ADC值转换为DAC值
  double voltage = adcVal / 4095.0 * 3.3;  //输出电压
  Serial.print("ADC Val: "); //打印字符串ADC Val:
  Serial.print(adcVal); //打印ADC值, DAC值和电压值
  Serial.print("  DAC Val: ");  //打印字符串DAC Val:
  Serial.print(dacVal);  //打印DAC值
  Serial.print("  Voltage: ");  //打印字符串Voltage:
  Serial.print(voltage);  //打印电压值
  Serial.println(" V");  //打印字符串V
  delay(200); 
}
//**********************************************************************************