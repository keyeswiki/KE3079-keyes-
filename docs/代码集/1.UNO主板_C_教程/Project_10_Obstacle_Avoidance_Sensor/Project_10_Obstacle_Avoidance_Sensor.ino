//**********************************************************************************
/*
 * 名称   : Obstacle Avoidance Sensor
 * 功能   : 读取避障传感器的数值
 * 作者   : http://www.keyes-robot.com/ 
*/
int val = 0;
int AvoidPin = 3;   //避障传感器的引脚定义为D3
void setup() {
  Serial.begin(9600);   //波特率设置为9600
  pinMode(AvoidPin, INPUT);    //将传感器设置为输入模式
}

void loop() {
  val = digitalRead(AvoidPin);    //读取传感器值
  Serial.print(val);    //打印传感器值
  if (val == 0) {    //检测到障碍物，输出低电平
    Serial.print("        ");
    Serial.println("There are obstacles");
    delay(100);
  }
  else {    //未发现障碍物，输出高电平
    Serial.print("        ");
    Serial.println("All going well");
    delay(100);
  }
}
//**********************************************************************************