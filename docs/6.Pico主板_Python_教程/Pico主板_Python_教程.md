# Pico主板_Python_教程

## 1. 树莓派Pico主板：

---

### 1. 简介：

![Img](./media/W0.png)

在我们开始学习keyes 模拟智能家居综合套件之前，首先介绍树莓派Pico主板，它是所有项目的核心。

2021年1月底的时候，树莓派基金会发布了一个重磅消息，推出了进军微控制器领域的树莓派Pico。功能强劲，价格便宜的特性让树莓派Pico受到了全世界创客们的关注，下面就来给大家介绍一下树莓派Pico这个小玩意儿。

树莓派Pico主板是一块小小的板子，大小和Arduino Nano 主板差不多，为21mm × 51mm。

![Img](./media/W1.png)

树莓派Pico是具有灵活数字接口的低成本高性能微控制器板。它集成了树莓派自己的RP2040微控制器芯片，运行速度高达133 MHz的双核Arm Cortex M0 +处理器，嵌入式264KB SRAM和2MB板载闪存以及26个多功能GPIO引脚。对于软件开发，可以使用树莓派的C/C++SDK或MicroPython。

![Img](./media/W2.png)

裸板不带针脚，需要自己焊。这是一块做工精良的电路板，也可以作为SMD元件，直接焊接到印刷电路板上。

![Img](./media/W3.png)

主板上最主要的功能是一端的microUSB连接器。它既用于通信，也用于给Raspberry Pi Pico供电。

在microUSB连接器旁边安装了一个板载LED，它内部连接到GPIO针脚25，这是整个树莓派Pico主板上唯一的LED。开机按钮安装在离LED稍低一点的地方，它可以让你改变树莓派Pico的启动模式，这样你就可以在上面加载MicroPython，进行拖拽式编程。
在板子的底部，你会看到三个连接点，这些连接点是用于串行Debug选项的，我们今天是入门，暂时不探讨这个问题，高级开发者会比较感兴趣。

在板子的中央是整个板子的“大脑”——RP2040 MCU，RP2040能够支持高达16MB的片外闪存，不过在Raspberry Pi Pico中只有4MB。

- 双核32位ARM Cortex-M0+处理器。
- 运行在48MHz，但可以超频到133MHz。
- 30个GPIO引脚(26个暴露)。
- 可支持USB主机或设备模式。
- 8个可编程I/O（PIO）状态机。
 
![Img](./media/W4.png)

树莓派Pico主板是一个3.3V的逻辑器件，但由于内置了电压转换器和稳压器，它可以用一系列电源供电。

GND–––地线，8个地线加上3针Debug连接器上的一个附加地线，是方形的，而不是像其他连接的圆形。

VBUS–––这是来自microUSB总线的电源(5V)。如果树莓派Pico主板不是由microUSB连接器供电，那么这里将没有输出。

VSYS–––这是输入电压，范围为2V至5V。板载电压转换器将为树莓派Pico主板将其改为3.3V。

3V3–––这是树莓派Pico主板内部调节器的3.3V输出。只要将负载保持在300MA以下，它就可用于为其他组件供电。

3V3_EN–––你可以使用此输入禁用树莓派Pico主板的内部电压调节器，从而关闭 树莓派Pico主板和由其供电的任何组件。

RUN–––可以启用或禁用RP2040微控制器，也可以将其复位。

![Img](./media/W5.png)

树莓派Pico主板上有26个裸露的GPIO连接，它们的排列顺序很好，在GP22和GP26之间有“空隙”（这些“缺失”的引脚在内部使用）。这些引脚都有多种功能，你可以为PWM配置多达16个引脚。有两个I2C总线，两个UART和两个SPI总线，这些可以配置使用多种GPIO引脚。

树莓派Pico主板有三个模数转换器分别为ADC0-GP26、ADC1-GP27、ADC2-GP28还有一个内部用于板载温度传感器的转换器ADC-VREF。<span style="color: rgb(255, 76, 65);">注意：ADC的分辨率为12位。但MicroPython把范围映射到16位，也就是从0到65535，微处理器的工作电压是3.3V，也就是说0对应着0V，65535对应着3.3V。</span>

你也可以在ADC_VREF引脚上提供一个外部精密电压参考。其中一个接地点，即33脚上的ADC_GND被用作该参考点的接地点。

| 树莓派Pico主板的配置|
| :--: |
| 双核 Arm Cortex-M0 + @ 133MHz|
| 2 个 UART、2 个 SPI 控制器和 2 个 I2C 控制器|
| 芯片内置 264KB SRAM 和 2MB 的板载闪存|
| 16 个 PWM 通道1|
| 通过专用 QSPI 总线支持最高 16MB 的片外闪存|
| USB 1.1 主机和设备支持|
| DMA 控制器|
| 8 个树莓派可编程 I/O（PIO）状态机，用于自定义外围设备支持|
| 30 个 GPIO 引脚，其中 4 个可用作模拟输入|
| 支持 UF2 的 USB 大容量存储启动模式，用于拖放式编程|

---

### 2. 原理图：

![Img](./media/W6.png)

![Img](./media/W6-1.png)

---

### 3. 完整引脚图：

![Img](./media/W7.png)

树莓派也在官网发布了一大堆技术文档，还有一本名为《Get Started with MicroPython on Raspberry Pi Pico》的说明书。它有纸质版，也有PDF版下载。

**更多详情请了解树莓派官方网站：**

[https://www.raspberrypi.com/products/raspberry-pi-pico](https://www.raspberrypi.com/products/raspberry-pi-pico)

---

## 2. Thonny IDE 的下载、安装和使用方法

参考链接：[https://www.keyesrobot.cn/projects/Thonny/zh-cn/latest/](https://www.keyesrobot.cn/projects/Thonny/zh-cn/latest/)

<span style="color: rgb(255, 76, 65);">注意：</span><span style="background:#ff0;color:#000">Pico主板_Python_教程使用的是Pico-Thonny IDE 的下载、安装和使用方法。</span>

---

## 3. 课程

---

### 项目01 Hello World

#### 1. 项目介绍：

对于树莓派Pico初学者，我们将从一些简单的东西开始。在这个项目中，您只需要一个树莓派Pico板和MicroUSB线来完成“Hello World!”项目。它不仅是树莓派Pico板和计算机的通信测试，也是树莓派Pico板的初级项目。

#### 2. 项目元件：

| ![Img](./media/1.png)| ![Img](./media/2.png) |
| :--: | :--: |
|树莓派Pico主板*1 | MicroUSB线*1 |

#### 3. 项目接线：

①连接microUSB线一端到你的电脑USB口。

②长按“树莓派Pico主板”上的白色按钮（BOOTSEL）。然后，通过microUSB线另一端将树莓派Pico板与电脑连接。

![Img](./media/3.png)

#### 4. 在线运行代码：

要在线运行树莓派Pico，你需要把树莓派Pico主板连接到电脑上。这样就可以使用Thonny软件编译或调试程序。

**优点：** 1. 你们可以使用Thonny软件编译或调试程序。

2. 通过“Shell”窗口，你们可以查看程序运行过程中产生的错误信息和输出结果，并可以在线查询相关功能信息，帮助改进程序。

**缺点：** 1.要在线运行树莓派Pico，你必须将树莓派Pico主板连接到一台电脑上并和Thonny软件一起运行。

2.如果树莓派Pico主板与电脑断开连接，当它们重新连接时，程序将无法再次运行。


**<span style="color: rgb(255, 76, 65); font-size: 24px;">特别注意：</span>本教程中使用的代码保存的路径为：“...\代码集\6.Pico主板_Python_教程”中。**

<br>

<span style="color: rgb(255, 169, 0);">**基本操作：**</span>
<br>

1.打开Thonny软件，并且单击![Img](./media/48.png)“**打开...**”。

![Img](./media/49.png)

2.在新弹出的窗口中，点击“**此电脑**”。

![Img](./media/50.png)

3.在新的对话框中，选中“Project_01_HelloWorld.py”,单击“**打开**”。

![Img](./media/51.png)


```Python
print("Hello World!")
print("Welcome to Keyestudio")
```

#### 5. 项目现象：
 
利用MicroUSB线连接到计算机上电，单击![Img](./media/52.png)来执行程序代码。代码开始执行，你会看到的现象是：“Shell”窗口打印出“Hello World!”、“Welcome to Keyestudio”。

![Img](./media/53.png)

当在线运行时，单击![Img](./media/54.png)或按Ctrl+C退出程序。

---

### 项目02 点亮LED

#### 1. 项目介绍：

在这个项目中，我们将向你展示点亮LED。我们是使用树莓派Pico主板的数字引脚来打开LED，使LED被点亮。

#### 2. 项目元件：

|![Img](./media/1.png)|![Img](./media/6.png)|![Img](./media/7.png)|
| :--: | :--: | :--: |
|树莓派Pico主板*1|面包板*1|红色LED*1|
|![Img](./media/8.png)| ![Img](./media/9.png)|![Img](./media/2.png)|
|220Ω电阻*1|面包板连接线*2|MicroUSB线*1|

#### 3. 元件知识：

**（1）LED**

![Img](./media/7.png)

LED是一种被称为“发光二极管”的半导体，是一种由半导体材料(硅、硒、锗等)制成的电子器件。它有正极和负极。短腿为负极，接GND，长腿为正极，接3.3V或5V。

![Img](./media/10.png)

**（2）五色环电阻**

电阻是电路中限制或调节电流流动的电子元件。左边是电阻器的外观，右边是电阻在电路中表示的符号。电阻(R)的单位为欧姆(Ω)，1 mΩ= 1000 kΩ，1kΩ= 1000Ω。

![Img](./media/abcdefg.png)

我们可以使用电阻来保护敏感组件，如LED。电阻的强度（以Ω为单位）用小色环标记在电阻器的主体上。每种颜色代表一个数字，你可以用电阻对照卡查找。

![Img](./media/11.png)

在这个套件中，我们提供了2个具有不同电阻值的五色环电阻。这里以2个五色环电阻为例：

220Ω电阻×10

![Img](./media/12.png)

1KΩ电阻×10

![Img](./media/13.png)

在相同的电压下，会有更小的电流和更大的电阻。电流、电压、电阻之间的联系可以用公式表示：I=U/R。在下图中，目前通过R1的电流: I = U / R = 3 V / 10 KΩ= 0.0003A= 0.3mA。

![Img](./media/14.png)

不要把电阻值很低的电阻直接连接在电源两极，这样会使电流过高而损坏电子元件。电阻是没有正负极之分。

**（3）面包板**

面包板是实验室中用于搭接电路的重要工具。面包板上有许多孔，可以插入集成电路和电阻等电路元件。熟练掌握面包板的使用方法是提高实验效率，减少实验故障出现几率的重要基础之一。下面就面包板的结构和使用方法做简单介绍。一个典型的面包板如下所示：

![Img](./media/15.png)

面包板的外观和内部结构如上图所示，常见的最小单元面包板分上、中、下三部分，上面和下面部分一般是由一行或两行的插孔构成的窄条，中间部分是由中间一条隔离凹槽和上下各5 行的插孔构成的条。

![Img](./media/15.png)

在面包板的两个窄条分别有两行插孔，两行之间是不连通的，一般是作为电源引入的通路。上方第一行标有“+”的一行有10组插孔（内部都是连通），均为正极；上方第二行标有“-”的一行有10组插孔，（内部都是连通），均为接地。面包板下方的第一行与第二行结构同上。如需用到整个面包板，通常将“+”与“+”用导线连接起来，“-”与“-”用导线连接起来。

中间部分宽条是由中间一条隔离凹槽和上下各5 行的插孔构成。在同一列中的5 个插孔是互相连通的，列和列之间以及凹槽上下部分则是不连通的。外观及结构如下图：

![Img](./media/17.png)

中间部分宽条的连接孔分为上下两部分，是面包板的主工作区，用来插接原件和面包板连接线。在同一列中的5个插孔（即a-b-c-d-e，f-g-h-i-j）是互相连通的；列和列之间以及凹槽上下部分是不连通的。在做实验的时候，通常是使用两窄一宽组成的小单元，在宽条部分搭接电路的主体部分，上面的窄条取一行做电源，下面的窄条取一行做接地。中间宽条用于连接电路，由于凹槽上下是不连通的，所以集成块一般跨插在凹槽上。

**(4)电源**

树莓派Pico主板需要3.3V-5V电源，在本项目中，我们通过用MicroUSB线将树莓派Pico主板和电脑连起来。

![Img](./media/3.png)

#### 4. 项目接线图：

![Img](./media/40.png)

#### 5. 在线运行代码：

**<span style="color: rgb(255, 76, 65); font-size: 24px;">特别注意：</span>本教程中使用的代码保存的路径为：“...\代码集\6.Pico主板_Python_教程”中。**

<br>

1.打开Thonny软件，并且单击![Img](./media/48.png)“**打开...**”。

![Img](./media/49.png)

2.在新弹出的窗口中，点击“**此电脑**”。

![Img](./media/50.png)

在新的对话框中，选中“Project_02_Turn_On_LED.py”,单击“**打开**”。

![Img](./media/55.png)

```Python

from machine import Pin
import time

led = Pin(16, Pin.OUT)   # 从引脚GPIO16创建LED对象，设置引脚GPIO16为输出模式

try:
    while True:
        led.value(1)    # 设置led开启
except:
    pass
```

#### 6. 项目现象：

按照接线图正确接好模块，利用MicroUSB线连接到计算机上电，单击![Img](./media/52.png)来执行程序代码。代码开始执行，你会看到的现象是：LED被点亮。

![Img](./media/19.png)

当在线运行时，单击![Img](./media/54.png)或按Ctrl+C退出程序。


#### 7. 代码说明:

| 代码                    | 说明                                                         |
| ----------------------- | ------------------------------------------------------------ |
| from machine import Pin | machine模块里对树莓派Pico主板的一些配置等已经设置好了，我们需导入它，然后调用。 |
| led = Pin(16, Pin.OUT)   | 构建一个引脚类实例，我们将其命名为led，16表示我们连接的引脚为GPIO16，Pin.OUT表示引脚16为输出模式，即可以使用value()方法输出高电平(3.3V) ：led.value(1)，或者低电平(0V) ：led.value(0)。 |
| while True:             | 循环函数，在此函数下面的语句循环执行，除非True变False。      |

---

### 项目03 LED闪烁

#### 1. 项目介绍：

在这个项目中，我们将向你展示LED闪烁效果。我们是使用树莓派Pico主板的数字引脚来打开LED，让它闪烁。

#### 2. 项目元件：

|![Img](./media/1.png)|![Img](./media/6.png)|![Img](./media/7.png)|
| :--: | :--: | :--: |
|树莓派Pico主板*1|面包板*1|红色LED*1|
|![Img](./media/8.png)| ![Img](./media/9.png)|![Img](./media/2.png)|
|220Ω电阻*1|面包板连接线*2|MicroUSB线*1|

#### 3. 项目接线图：

![Img](./media/40.png)

#### 4. 在线运行代码：

**<span style="color: rgb(255, 76, 65); font-size: 24px;">特别注意：</span>本教程中使用的代码保存的路径为：“...\代码集\6.Pico主板_Python_教程”中。**

<br>

1.打开Thonny软件，并且单击![Img](./media/48.png)“**打开...**”。

![Img](./media/49.png)

2.在新弹出的窗口中，点击“**此电脑**”。

![Img](./media/50.png)

在新的对话框中，选中“Project_03_LED_Blinking.py”,单击“**打开**”。

![Img](./media/56.png)

```Python
from machine import Pin
import time

led = Pin(16, Pin.OUT)   # 从引脚GPIO16创建LED对象，设置引脚GPIO16为输出模式

try:
    while True:
        led.value(1)    # 设置led开启
        time.sleep(0.5) # 延时 0.5秒
        led.value(0)    # 设置led关闭
        time.sleep(0.5) # 延时 0.5秒
except:
    pass
```

#### 5. 项目现象：

按照接线图正确接好各元器件，利用USB线连接到计算机上电，单击![Img](./media/52.png)来执行程序代码。代码开始执行，你会看到的现象是：LED闪烁。

![Img](./media/21.png)

当在线运行时，单击![Img](./media/54.png)或按Ctrl+C退出程序。


#### 6. 代码说明:

| 代码                    | 说明                                                         |
| ----------------------- | ------------------------------------------------------------ |
| from machine import Pin | machine模块里对树莓派Pico主板的一些配置等已经设置好了，我们需导入它，然后调用。 |
| led = Pin(16, Pin.OUT)   | 构建一个引脚类实例，我们将其命名为led，16表示我们连接的引脚为GPIO16，Pin.OUT表示引脚16为输出模式，即可以使用value()方法输出高电平(3.3V) ：led.value(1)，或者低电平(0V) ：led.value(0)。 |
| while True:             | 循环函数，在此函数下面的语句循环执行，除非True变False。      |
| time.sleep(0.5)           | time模块主要是用于时间延迟设置。括号里是0.5，延时0.5秒。         |

---

### 项目04 交通灯

#### 1. 项目介绍：

交通灯在我们的日常生活中很普遍。根据一定的时间规律，交通灯是由红、黄、绿三种颜色组成的。每个人都应该遵守交通规则，这可以避免许多交通事故。在这个项目中，我们将使用树莓派Pico主板和一些led(红，黄，绿)来模拟交通灯。

#### 2. 项目元件：

|![Img](./media/1.png)|![Img](./media/6.png)|![Img](./media/7.png)|![Img](./media/22.png)|
| :--: | :--: | :--: |:--: |
|树莓派Pico主板*1|面包板*1|红色LED*1|黄色LED*1|
|![Img](./media/23.png)|![Img](./media/8.png)| ![Img](./media/9.png)|![Img](./media/2.png)|
|绿色LED*1|220Ω电阻*3|面包板连接线若干|MicroUSB线*1|

#### 3. 项目接线图： 

![Img](./media/41.png)

#### 4. 在线运行代码：

**<span style="color: rgb(255, 76, 65); font-size: 24px;">特别注意：</span>本教程中使用的代码保存的路径为：“...\代码集\6.Pico主板_Python_教程”中。**

<br>

1.打开Thonny软件，并且单击![Img](./media/48.png)“**打开...**”。

![Img](./media/49.png)

2.在新弹出的窗口中，点击“**此电脑**”。

![Img](./media/50.png)

在新的对话框中，选中“Project_04_Traffic_Lights.py”,单击“**打开**”。

![Img](./media/57.png)

```Python
from machine import Pin
import time

led_red = machine.Pin(16, machine.Pin.OUT)  # 从引脚GPIO16创建红色led对象，设置引脚GPIO16为输出模式
led_yellow = machine.Pin(17, machine.Pin.OUT) # 从引脚GPIO17创建黄色led对象，设置引脚GPIO17为输出模式
led_green = machine.Pin(18, machine.Pin.OUT) # 从引脚GPIO18创建绿色led对象，设置引脚18输出模式

while True:
    led_green.value(1)  # 设置绿色led灯亮
    time.sleep(5)   # 延时 5秒
    led_green.value(0) # 设置绿色led关闭 
    led_yellow.value(1)
    time.sleep(0.5)
    led_yellow.value(0)
    time.sleep(0.5)
    led_yellow.value(1)
    time.sleep(0.5)
    led_yellow.value(0)
    time.sleep(0.5)
    led_yellow.value(1)
    time.sleep(0.5)
    led_yellow.value(0)
    time.sleep(0.5)
    led_red.value(1)
    time.sleep(5) 
    led_red.value(0) 
```
#### 5. 项目现象：

按照接线图正确接好各元器件，利用MicroUSB线连接到计算机上电，单击![Img](./media/52.png)来执行程序代码。代码开始执行，你会看到的现象是：1.首先，绿灯会亮5秒，然后熄灭；2.其次，黄灯会闪烁3次，然后熄灭；3.然后，红灯会亮5秒，然后熄灭；4.继续运行上述1-3个步骤。

![Img](./media/ABC20.jpg)

当在线运行时，单击![Img](./media/54.png)或按Ctrl+C退出程序。

#### 6. 代码说明:

可以参照项目03的代码说明，这里就不多做介绍了。

---

### 项目05 呼吸灯

#### 1. 项目介绍：

在之前的研究中，我们知道LED有亮/灭状态，那么如何进入中间状态呢?如何输出一个中间状态让LED“半亮”?这就是我们将要学习的。呼吸灯，即LED由灭到亮，再由亮到灭，就像“呼吸”一样。那么，如何控制LED的亮度呢? 我们将使用树莓派Pico主板的PWM来实现这个目标。

#### 2. 项目元件：

|![Img](./media/1.png)|![Img](./media/6.png)|![Img](./media/7.png)|
| :--: | :--: | :--: |
|树莓派Pico主板*1|面包板*1|红色LED*1|
|![Img](./media/8.png)| ![Img](./media/9.png)|![Img](./media/2.png)|
|220Ω电阻*1|面包板连接线*2|MicroUSB线*1|

#### 3. 元件知识：

![Img](./media/24.png)

**模拟信号 & 数字信号** 

模拟信号在时间和数值上都是连续的信号。相反，数字信号或离散时间信号是由一系列数字组成的时间序列。生活中的大多数信号都是模拟信号，一个熟悉的模拟信号的例子是：全天的温度是连续不断变化的，而不是突然从0到10的瞬间变化。然而，数字信号的值可以瞬间改变。这个变化用数字表示为1和0(二进制代码的基础)。如下图所示，我们可以更容易地看出它们的差异。

![Img](./media/25.png)

在实际应用中，我们经常使用二进制作为数字信号，即一系列的0和1。由于二进制信号只有两个值(0或1)，因此具有很大的稳定性和可靠性。最后，可以将模拟信号和数字信号相互转换。

**PWM：**

脉宽调制(PWM)是一种利用数字信号控制模拟电路的有效方法。普通处理器不能直接输出模拟信号。PWM技术使这种转换(将数字信号转换为模拟信号)非常方便。PWM技术利用数字引脚发送一定频率的方波，即高电平和低电平的输出，交替持续一段时间。每一组高电平和低电平的总时间一般是固定的，称为周期(注:周期的倒数是频率)。高电平输出的时间通常称为脉宽，占空比是脉宽(PW)与波形总周期(T)之比的百分比。高电平输出持续时间越长，占空比越长，模拟信号中相应的电压也就越高。下图显示了对应于脉冲宽度0%-100%的模拟信号电压在0V-3.3V(高电平为3.3V)之间的变化情况.

![Img](./media/26.png)

PWM占空比越长，输出功率越高。既然我们了解了这种关系，我们就可以用PWM来控制LED的亮度或直流电机的速度等等。从上面可以看出，PWM并不是真实的模拟信号，电压的有效值等于相应的模拟信号。因此，我们可以控制LED和其他输出模块的输出功率，以达到不同的效果。

**树莓派Pico主板与PWM**

树莓派Pico主板有16个PWM通道，每个PWM通道可以独立控制频率和占空比，时钟频率范围为7Hz到125MHz。树莓派Pico主板上的16个PWM通道都可以配置为PWM输出。

#### 4. 项目接线图： 

![Img](./media/40.png)

#### 5. 在线运行代码：

**<span style="color: rgb(255, 76, 65); font-size: 24px;">特别注意：</span>本教程中使用的代码保存的路径为：“...\代码集\6.Pico主板_Python_教程”中。**

<br>

1.打开Thonny软件，并且单击![Img](./media/48.png)“**打开...**”。

![Img](./media/49.png)

2.在新弹出的窗口中，点击“**此电脑**”。

![Img](./media/50.png)

在新的对话框中，选中“Project_05_Breathing_Led.py”,单击“**打开**”。

![Img](./media/58.png)

```Python
#MicroPython实现Raspberry Pi Pico板控制LED实现呼吸灯的程序示例
import time 
from machine import Pin,PWM
PWM_PulseWidth=0
#利用外接LED，构建PWM对象PWM LED
pwm_LED=PWM(Pin(16))
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
```

#### 6. 项目现象：

按照接线图正确接好各元器件，利用MicroUSB线连接到计算机上电，单击![Img](./media/52.png)来执行程序代码。代码开始执行，你会看到的现象是：电路中的LED从暗逐渐变亮，再从亮逐渐变暗，就像呼吸一样。

![Img](./media/28.png)

当在线运行时，单击![Img](./media/54.png)或按Ctrl+C退出程序。


#### 7. 代码说明:

| 代码                    | 说明                                                         |
| ----------------------- | ------------------------------------------------------------ |
| PWM_PulseWidth=0 | 设置PWM初始值为0 | 
|pwm_LED=PWM(Pin(16))|LED的PWM引脚为GPIO16|
|pwm_LED.freq(500)|设置LED频率为500|

---

### 项目06 流水灯

#### 1. 项目介绍：

在日常生活中，我们可以看到许多由不同颜色的led组成的广告牌。他们不断地改变灯光(像流水一样)来吸引顾客的注意。在这个项目中，我们将使用树莓派Pico主板控制3个LED灯实现流水的效果。

#### 2. 项目元件：

|![Img](./media/1.png)|![Img](./media/6.png)|![Img](./media/7.png)|
| :--: | :--: | :--: |
|树莓派Pico主板*1|面包板*1|红色LED*3|
|![Img](./media/8.png)| ![Img](./media/9.png)|![Img](./media/2.png)|
|220Ω电阻*3|面包板连接线若干|MicroUSB线*1|

#### 3. 项目接线图:

![Img](./media/42.png)

#### 4. 在线运行代码：

**<span style="color: rgb(255, 76, 65); font-size: 24px;">特别注意：</span>本教程中使用的代码保存的路径为：“...\代码集\6.Pico主板_Python_教程”中。**

<br>

1.打开Thonny软件，并且单击![Img](./media/48.png)“**打开...**”。

![Img](./media/49.png)

2.在新弹出的窗口中，点击“**此电脑**”。

![Img](./media/50.png)

在新的对话框中，选中“Project_06_Flowing_Water_Light.py”,单击“**打开**”。

![Img](./media/59.png)

```Python
from machine import Pin
import time

#使用阵列定义3个连接到LED的GPIO端口，方便操作.
pins = [16, 17, 18]
#使用两个for循环，分别从左到右打开led，然后从右到左返回.
def showLed():
    for pin in pins:
        print(pin)
        led = Pin(pin, Pin.OUT)
        led.value(1)
        time.sleep_ms(100)
        led.value(0)
        time.sleep_ms(100)        
    for pin in reversed(pins):
        print(pin)
        led = Pin(pin, Pin.OUT)
        led.value(1)
        time.sleep_ms(100)
        led.value(0)
        time.sleep_ms(100)
          
while True:
    showLed()
```

#### 5. 项目现象：

按照接线图正确接好各元器件，利用MicroUSB线连接到计算机上电，单击![Img](./media/52.png)来执行程序代码。代码开始执行，你会看到的现象是：电路中的3个LED分别从左到右闪烁，然后从右到左闪烁，循环进行。

![Img](./media/ABC19.jpg)

当在线运行时，单击![Img](./media/54.png)或按Ctrl+C退出程序。


#### 6. 代码说明:

| 代码                    | 说明                                                         |
| ----------------------- | ------------------------------------------------------------ |
|for pin in pins| 表示变量pin从16开始，每次自加1，到小于19的最大整数，也就是18。即第一次i为16，第二次i为17，第三次i为18，此时跳出for循环，所以for循环下面的语句执行三次，每一次都是led亮0.1秒，灭0.1秒。 | 
|def showLed():|定义一种函数showLed()|
|print(pin)|打印引脚|

---

### 项目07 有源蜂鸣器

#### 1. 项目介绍：

有源蜂鸣器模块上有一个发声元件----有源蜂鸣器。它被广泛用作电脑、打印机、报警器、电子玩具、电话、计时器等的发声元件。它有一个内在的振动源，需连接3.3V~5V电源，即可持续发出嗡嗡声。在这个项目中，我们将使用树莓派Pico主板控制有源蜂鸣器发出“滴滴”声。

#### 2. 项目元件：

|![Img](./media/1.png)|![Img](./media/6.png)|![Img](./media/29.png)|![Img](./media/30.jpg)|![Img](./media/2.png)|
| :--: | :--: | :--: | :--: |:--: |
|树莓派Pico主板*1|面包板*1|有源蜂鸣器模块*1|公对母杜邦线若干|MicroUSB线*1|

#### 3. 元件知识：

<span style="color: rgb(255, 76, 65);">注意：本教程使用的是有源蜂鸣器。</span>

![Img](./media/29.png)

有源蜂鸣器和无源蜂鸣器的“源”不是指电源，而是指震荡源。

**有源蜂鸣器**：内部自带震荡源，所以一触发就能发声，发声频率固定。有源蜂鸣器的优点是程序控制方便，声压高。有源自激型蜂鸣器工作发声原理如下：直流电源输入经过振荡系统的放大和取样电路在谐振装置作用下产生声音信号。

**模块参数：**

工作电压: DC 3.3 ~ 5V 

工作温度：-10°C ~ +50°C

控制信号：数字信号

尺寸：32 mm x 23.8 mm x 12.3 mm

定位孔大小：直径为 4.8 mm

**无源蜂鸣器**: 内部不带震荡源，如果直接通直流电信号无源蜂鸣器是没有声音的，因为磁路恒定，振动膜片一直处在吸附状态，不能振动发音。根据不同需求，一般我们通过方波去驱动，然后通过更换方波的频率来实现不同音效。

**总结：有源蜂鸣器内部带震荡源，发声频率固定。无源内部不带震荡源，通过方波去驱动，发音频率可改变。**


#### 4. 项目接线图：

![Img](./media/43.png)

#### 5. 在线运行代码：

**<span style="color: rgb(255, 76, 65); font-size: 24px;">特别注意：</span>本教程中使用的代码保存的路径为：“...\代码集\6.Pico主板_Python_教程”中。**

<br>

1.打开Thonny软件，并且单击![Img](./media/48.png)“**打开...**”。

![Img](./media/49.png)

2.在新弹出的窗口中，点击“**此电脑**”。

![Img](./media/50.png)

在新的对话框中，选中“Project_07_Active_Buzzer.py”,单击“**打开**”。

![Img](./media/60.png)

```Python
from machine import Pin
import time

buzzer = Pin(16, Pin.OUT)   # 从引脚GPIO16创建蜂鸣器对象，设置引脚GPIO16为输出模式
 
try:
    while True:
        buzzer.value(1)  # 设置蜂鸣器开启
        time.sleep(0.5)  # 延时 0.5秒
        buzzer.value(0)  # 设置蜂鸣器关闭
        time.sleep(0.5)  # 延时 0.5秒
except:
    pass
```

#### 6. 项目现象：

按照接线图正确接好模块，利用MicroUSB线连接到计算机上电，单击![Img](./media/52.png)来执行程序代码。代码开始执行，你会看到的现象是：有源蜂鸣器发出“滴滴”声。

![Img](./media/ABC18.jpg)

当在线运行时，单击![Img](./media/54.png)或按Ctrl+C退出程序。

#### 7. 代码说明:

可以参照项目03的代码说明，这里就不多做介绍了。

---

### 项目08 继电器控制LED

#### 1. 项目介绍：

在日常生活中，我们一般使用交流来驱动电气设备，有时我们会用开关来控制电器。如果将开关直接连接到交流电路上，一旦发生漏电，人就有危险。从安全的角度考虑，我们特别设计了这款具有NO(常开)端和NC(常闭)端的继电器模块。在这节课我们将学习一个比较特殊、好用的开关，就是继电器模块，使用继电器模块控制LED灯亮灭。

#### 2. 项目元件：

|![Img](./media/1.png)|![Img](./media/6.png)|![Img](./media/32.png)|![Img](./media/7.png)|![Img](./media/A25.png)|
| :--: | :--: | :--: |:--: |:--: |
|树莓派Pico主板*1|面包板*1|继电器模块*1|红色LED*1|一字螺丝刀*1|
|![Img](./media/30.jpg)|![Img](./media/2.png)|![Img](./media/8.png)| ![Img](./media/9.png)| |
|公对母杜邦线若干|MicroUSB线*1|220Ω电阻*1|面包板连接线若干| |

#### 3. 元件知识：

![Img](./media/32.png)

**继电器：** 继电器能兼容多种单片机控制板，是用小电流去控制大电流运作的一种“自动开关”。它可以让单片机控制板驱动3A以下负载，如LED灯带、直流马达、微型水泵、电磁阀可插拔式接口设计，方便使用。继电器有3个接线柱用于外接电路，分别为NO、COM和NC端（背后丝印）。

![Img](./media/33.png)

**模块参数:**

工作电压: DC 5V 

工作电流: 50 mA

最大功率: 0.25 W

控制信号: 数字信号

触电电流: 小于 3 A

工作温度：-10°C ~ +50°C

尺寸：47.6mm x 23.8mm x 19mm

定位孔大小：直径为4.8mm

**模块原理图:**

![Img](./media/34.png)

一个继电器拥有一个动触点以及两个静触点A和B。

当开关K断开时，继电器线路无电流通过，此时动触点与静触点B相接触，上半部分的电路导通。静触点B被称为常闭触点（NC）。常闭——NC（normal close）通常情况下是关合状态，即线圈未得电的情况下闭合的。

当开关K闭合时，继电器电路通过电流产生磁力，此时动触点与静触点A相接触，下半部分电路导通。静触点A被称为常开触点（NO）。常开——NO（normal open）通常情况下是断开状态，即线圈未得电的情况下断开的。

而动触点也被称为公共触点（COM）。

继电器简单来说就是一个开关，VCC表示电源正极、GND表示电源负极、IN表示信号输入脚，COM表示公共端，NC（normal close）表示常闭端，NO(normal open)表示常开端。

![Img](./media/35.png)


#### 4. 项目接线图：

<br>
<span style="color: rgb(61, 167, 66);"> **特别注意：** 接线前，需要用一字螺丝刀将继电器模块的NO端口和COM端口处的螺丝扭松，将面包板连接线的一端插入NO端口和COM端口处；接好线后，再用一字螺丝刀将NO端口和COM端口处的螺丝扭紧。</span>
<br>

![Img](./media/44.png)

#### 5. 在线运行代码：

**<span style="color: rgb(255, 76, 65); font-size: 24px;">特别注意：</span>本教程中使用的代码保存的路径为：“...\代码集\6.Pico主板_Python_教程”中。**

<br>

1.打开Thonny软件，并且单击![Img](./media/48.png)“**打开...**”。

![Img](./media/49.png)

2.在新弹出的窗口中，点击“**此电脑**”。

![Img](./media/50.png)

在新的对话框中，选中“Project_08_Relay_Control_LED.py”,单击“**打开**”。

![Img](./media/61.png)

```Python
from machine import Pin
import time

# 从引脚GPIO16创建继电器，设置引脚GPIO16为输出模式 
relay = Pin(16, Pin.OUT)
 
# 继电器断开，继电器上COM、NO连接，COM、NC断开.
def relay_on():
    relay(1)
 
# 继电器闭合，继电器上的COM和NO断开，COM和NC连接.
def relay_off():
    relay(0)
 
# 循环，继电器开启1秒，关闭1秒
while True:
    relay_on()
    time.sleep(1)
    relay_off()
    time.sleep(1)
```
#### 6. 项目现象：

按照接线图正确接好模块和各元器件，利用MicroUSB线连接到计算机上电，单击![Img](./media/52.png)来执行程序代码。代码开始执行，你会看到的现象是：继电器将循环开与关，开启1秒LED点亮1秒，关闭1秒LED熄灭1秒。同时可以听到继电器开与关的声音，还可以看到继电器上的指示灯指示状态的变化。

![Img](./media/ABC17.jpg)

当在线运行时，单击![Img](./media/54.png)或按Ctrl+C退出程序。

#### 7. 代码说明:

可以参照项目03和项目06的代码说明，这里就不多做介绍了。

---

### 项目09 人体红外热释传感器

#### 1. 项目介绍：

在本项目中，通过读取人体红外热释传感器模块上S端高低电平，判断附近是否有人在运动；并且在Shell窗口中显示测试结果。

#### 2. 项目元件：

|![Img](./media/1.png)|![Img](./media/6.png)|![Img](./media/C1.png)|![Img](./media/30.jpg)|![Img](./media/2.png)|
| :--: | :--: | :--: |:--: |:--: |
|树莓派Pico主板*1|面包板*1|人体红外热释传感器模块*1|公对母杜邦线若干|MicroUSB线*1|

#### 3. 元件知识：

![Img](./media/C1.png)

**人体红外热释传感器:** 它主要由一个RE200B-P传感器元件组成。它是一款基于热释电效应的人体热释运动传感器，能检测到人体或动物身上发出的红外线，配合菲涅尔透镜能使传感器探测范围更远更广。

**模块参数:**

工作电压: DC 3.3V ~ 5V 

工作电流: 3.6MA

最大功率: 0.018W

输出信号: 数字信号

触发方式: L 不可重复触发/H 重复触发

探测距离: ≤5m

视野角度: Y = 90°，X = 110°（视野角度为理论数值）

工作温度：-10°C ~ +50°C

尺寸：32mm x 23.8mm x 7.4mm

定位孔大小：直径为4.8mm

**模块原理图:**

![](media/C8.jpg)

这个模块的原理图可能较前面的模块稍复杂，我们一部分一部分来看。先看电压转换部分，作用是将5V输入电压转换为3.3V输入电压。因为我们模块上用到的人体热释电红外传感器的工作电压是3.3V，不能直接用5V电压供电使用。有了这个电压转换部分，3.3V输入电压和5V输入电压都适用于此热释电红外传感器。

当红外热释传感器没有检测到红外信号时，红外热释传感器的1脚输出低电平，此时模块上的LED两端有电压差，有电流流过，LED被点亮，MOS管Q1导通（Q1是NPN MOS管，型号为2N7002。由于红外热释传感器的1脚输出低电平，所以Q1的源极Vs=0，而Q1的栅极Vg=3.3V，于是Q1的栅极G和Q1的源极S之间的电压 Vgs = 3.3V 大于Q1的阈值电压 2.5V，Q1导通。），信号端S检测到低电平。

当红外热释传感器检测到红外信号时，红外热释传感器模块的1脚输出高电平，此时模块上的LED熄灭，MOS管Q1不导通，则信号端S检测到被10K上拉电阻R5拉高的高电平。

#### 4. 项目接线图：

![Img](./media/B1.png)
#### 5. 在线运行代码：

**<span style="color: rgb(255, 76, 65); font-size: 24px;">特别注意：</span>本教程中使用的代码保存的路径为：“...\代码集\6.Pico主板_Python_教程”中。**

<br>

1.打开Thonny软件，并且单击![Img](./media/48.png)“**打开...**”。

![Img](./media/49.png)

2.在新弹出的窗口中，点击“**此电脑**”。

![Img](./media/50.png)

在新的对话框中，选中“Project_09_PIR_Motion_sensor.py”,单击“**打开**”。

![Img](./media/62.png)

```Python
from machine import Pin
import time

PIR = Pin(16, Pin.IN)
while True:
    value = PIR.value()
    print(value, end = " ")
    if value == 1:
        print("Somebody is in this area!")
    else:
        print("No one!")
    time.sleep(0.1)
```

#### 6. 项目现象：

按照接线图正确接好模块，利用MicroUSB线连接到计算机上电，单击![Img](./media/52.png)来执行程序代码。代码开始执行，你会看到的现象是：当传感器检测到附近有人在运动时，value值为1，模块上LED熄灭，Shell窗口中显示“**1   Somebody is in this area!**”；没有检测到附近有人在运动时，value值为0，模块上LED点亮，Shell窗口中显示“**0   No one!**”。

![Img](./media/ABC16.jpg)

![Img](./media/C9.png)

当在线运行时，单击![Img](./media/54.png)或按Ctrl+C退出程序。

#### 7. 代码说明:

| 代码                                 | 说明                                                         |
| ------------------------------------ | ------------------------------------------------------------ |
| PIR = Pin(16, Pin\.IN) | 定义人体红外热释传感器模块的管脚为GPIO16，设置为“Pin\.IN”模式而不使用输入上拉，此时引脚处于高阻抗状态，会导致不可预测的电平结果。为了确保开关断开时的读数正确，推荐使用上拉或下拉电阻。但是，我们的模块已经使用上拉电阻R3和R5，可以不设置输入上拉，该电阻的目的是在开关断开时将引脚拉至已知状态。通常选择一个4.7KΩ/10KΩ的电阻，因为它的阻值足够低，可以可靠地防止输入悬空，同时，该阻值也要足够高，以使开关闭合时不会消耗太多电流。如果使用下拉电阻，则当开关断开时，输入引脚将为低电平；当开关闭合时，输入引脚将为高电平。如果使用上拉电阻，则当开关断开时，输入引脚将为高电平；当开关闭合时，输入引脚将为低电平。 |
|PIR.value()                       | 读取人体红外热释传感器的数字电平，函数返回高(HIGH)或者低(LOW)。            |
| if... else：...                        | 当if后面的逻辑判断为True时，执行if下缩进的代码；否则执行else下缩进的代码。python代码是严格使用缩进的。 |

---

### 项目10 避障传感器

#### 1. 项目介绍：

在本项目中，通过读取避障传感器模块上S端高低电平，判断是否存在障碍物，并且在Shell窗口中显示测试结果。

#### 2. 项目元件：

|![Img](./media/1.png)|![Img](./media/6.png)|![Img](./media/C2.png)|
| :--: | :--: | :--: |
|树莓派Pico主板*1|面包板*1|避障传感器模块*1|
|![Img](./media/30.jpg)|![Img](./media/2.png)|![Img](./media/A25.png)|
|公对母杜邦线若干|MicroUSB线*1|一字螺丝刀*1|

#### 3. 元件知识：

![Img](./media/C2.png)

**避障传感器:** 它主要由一对红外线发射管与接收管元件组成。当传感器感应到物体时信号端S输出0，未感应到时信号端S输出1。它可通过调节电位器用来调节感应灵敏度，它感应速度快，适合智能小车避障、防跌落，产品计数器，流水线切割，液位检测等。

**模块参数:**

工作电压: DC 3.3 ~ 5V 

工作电流: 6.8MA

最大功率: 0.034W

静态电流: <50 uA

最大检测距离: 173mm

工作温度：-10°C ~ +50°C

输出信号: 数字信号

感应距离: 2 ~ 40 cm

尺寸：32mm x 23.8mm x 11mm

定位孔大小：直径为4.8mm

**模块原理图:**

![](media/C10.jpg)

NE555时基电路提供给发射管TX发射出一定频率的红外信号，红外信号会随着传送距离的加大逐渐衰减，如果遇到障碍物，就会形成红外反射。当检测方向RX遇到反射回来的信号比较弱时，接收检测引脚输出高电平，说明障碍物比较远；当反射回来的信号比较强，接收检测引脚输出低电平，说明障碍物比较近，此时指示灯亮起。传感器上有两个电位器，一个用于调节发送功率，一个用于调节接收频率，通过调节两个电位器，我们可以调节它的有效距离。

#### 4. 项目接线图：

![Img](./media/B2.png)

#### 5. 在线运行代码：

**<span style="color: rgb(255, 76, 65); font-size: 24px;">特别注意：</span>本教程中使用的代码保存的路径为：“...\代码集\6.Pico主板_Python_教程”中。**

<br>

1.打开Thonny软件，并且单击![Img](./media/48.png)“**打开...**”。

![Img](./media/49.png)

2.在新弹出的窗口中，点击“**此电脑**”。

![Img](./media/50.png)

在新的对话框中，选中“Project_10_Obstacle_Avoidance_Sensor.py”,单击“**打开**”。

![Img](./media/F1.png)

```Python
from machine import Pin
import time

Avoid = Pin(16, Pin.IN)
while True:
    value = Avoid.value()
    print(value, end = " ")
    if value == 0:
        print("There are obstacles")
    else:
        print("All going well")
    time.sleep(0.1)
```

#### 6. 项目现象：

按照接线图正确接好模块，利用MicroUSB线连接到计算机上电，接着开始调节传感器模块上的两个电位器感应距离。避障传感器上有两个电位器，分别是接收频率调节电位器和发射功率调节电位器，如下图所示。

![img](media/C12.jpg)

先使用一字螺丝刀调节发射功率调节电位器，先将电位器顺时针拧到尽头，然后逆时针慢慢往回调，当调节到SLED灯亮起时，微调使传感器上SLED灯介于亮与不亮之间的**不亮**状态。

接着设置接收频率调节电位器，同样将电位器顺时针拧到尽头，然后逆时针慢慢往回调，当SLED灯亮起时，微调使传感器上SLED灯介于亮与不亮之间的**不亮**状态，此时能检测障碍物的距离最长。

单击![Img](./media/52.png)来执行程序代码。代码开始执行，你会看到的现象是：当传感器检测到障碍物时，value 值为 **0**，SLED 灯亮，Shell窗口中打印出 “**0    There are obstacles**” ；没有检测到障碍物时，value 值为 **1**，SLED 灯灭，Shell窗口中打印出 “**1    All going well**” 。

![Img](./media/ABC15.jpg)

![Img](./media/C11.png)

当在线运行时，单击![Img](./media/54.png)或按Ctrl+C退出程序。

#### 7. 代码说明:

可以参照项目09的代码说明，这里就不多做介绍了。

---

### 项目11 电容触摸传感器

#### 1. 项目介绍：

在本项目中，通过读取电容触摸传感器模块上S端高低电平，判断是否触摸传感器的感应区，并且在Shell窗口中显示测试结果。

#### 2. 项目元件：

|![Img](./media/1.png)|![Img](./media/6.png)|![Img](./media/C4.png)|![Img](./media/30.jpg)|![Img](./media/2.png)|
| :--: | :--: | :--: |:--: |:--: |
|树莓派Pico主板*1|面包板*1|电容触摸传感器模块*1|公对母杜邦线若干|MicroUSB线*1|

#### 3. 元件知识：

![Img](./media/C4.png)

**电容触摸传感器:** 它主要由1个触摸检测芯片 TTP223-BA6 构成。模块上提供一个触摸按键，功能是用可变面积的按键取代传统按键。当我们上电之后，传感器需要约0.5秒的稳定时间，此时间段内不要触摸按键，此时所有功能都被禁止，始终进行自校准，校准周期约为4秒。

**模块参数:**

工作电压：DC 3.3 ~ 5V

工作电流：3MA

最大功率：0.015W

工作温度：-10°C ~ +50°C

输出信号：数字信号

尺寸：32 mm x 23.8 mm x 9 mm

定位孔大小：直径为 4.8 mm

**模块原理图:**

![](media/C13.png)

TTP223N-BA6 的输出通过 AHLB（4）引脚选择高电平或低电平有效。通过 TOG（6）引脚选择直接模式或触发模式。

| TOG  | AHLB | 引脚Q的功能           |
| ---- | ---- | --------------------- |
| 0    | 0    | 直接模式，高电平有效  |
| 0    | 1    | 直接模式，低电平有效  |
| 1    | 0    | 触发模式，上电状态为0 |
| 1    | 1    | 触发模式，上电状态为1 |

从原理图我们可以知道 TOG 脚和 AHLB 脚是悬空的，此时输出为直接模式，高电平有效。

当我们用手指触摸电容触摸传感器模块上的感应区时，信号端 S 输出高电平，板载红色LED点亮。我们通过读取模块上 S 端的高低电平，来判断电容触摸模块上的感应区是否感应到触摸。

![img](media/C15.png)

#### 4. 项目接线图：

![Img](./media/B3.png)

#### 5. 在线运行代码：

**<span style="color: rgb(255, 76, 65); font-size: 24px;">特别注意：</span>本教程中使用的代码保存的路径为：“...\代码集\6.Pico主板_Python_教程”中。**

<br>

1.打开Thonny软件，并且单击![Img](./media/48.png)“**打开...**”。

![Img](./media/49.png)

2.在新弹出的窗口中，点击“**此电脑**”。

![Img](./media/50.png)

在新的对话框中，选中“Project_11_Touch_Sensor.py”,单击“**打开**”。

![Img](./media/F2.png)

```Python
from machine import Pin
import time

Touch = Pin(16, Pin.IN)
while True:
    value = Touch.value()
    print(value, end = " ")
    if value == 1:
        print("Touch the button")
    else:
        print("Loosen the button")
    time.sleep(0.1)
```

#### 6. 项目现象：

按照接线图正确接好模块，利用MicroUSB线连接到计算机上电，单击![Img](./media/52.png)来执行程序代码。代码开始执行，你会看到的现象是：当电容触摸传感器模块上的感应区感应到触摸时，板载红色LED灯点亮，value 值为 1，Shell窗口中打印出“**1  Touch the button**”。否则，当没有感应到触摸时，板载红色LED灯熄灭，value 值为 0，Shell窗口中打印出“**0  Loosen the button**”。

![Img](./media/ABC14.jpg)

![](./media/C14.png)


当在线运行时，单击![Img](./media/54.png)或按Ctrl+C退出程序。

#### 7. 代码说明:

可以参照项目09的代码说明，这里就不多做介绍了。

---

### 项目12 光敏传感器

#### 1. 项目介绍：

光敏传感器模块有个信号输出端，可以输出光照强度的模拟信号。在本项目中，我们将读取传感器的ADC值和电压值，并将测试结果在Shell窗口中打印显示出来。

#### 2. 项目元件：

|![Img](./media/1.png)|![Img](./media/6.png)|![Img](./media/C5.png)|![Img](./media/30.jpg)|![Img](./media/2.png)|
| :--: | :--: | :--: |:--: |:--: |
|树莓派Pico主板*1|面包板*1|光敏传感器模块*1|公对母杜邦线若干|MicroUSB线*1|

#### 3. 元件知识：

![Img](./media/C5.png)

**光敏传感器:** 是一个常用的光敏电阻传感器，它主要由一个光敏电阻元件组成。光敏电阻元件的阻值随着光照强度的变化而变化，此传感器就是利用光敏电阻元件这一特性，设计电路将阻值变化转换为电压变化。光敏电阻传感器可以模拟人对环境光线的强度的判断，方便做出与人友好互动的应用。

**模块参数:**

工作电压: DC 3.3 ~ 5V 

工作电流: 0.2MA

最大功率: 0.001W

光谱峰值: 540nm

亮电阻: 5~10千欧

暗电阻: 0.5兆欧

工作温度：-10°C ~ +50°C

输出信号: 模拟信号

尺寸：32 mm x 23.8 mm x 7.4 mm

定位孔大小：直径为 4.8 mm

**模块原理图:**

![](media/C16.png)

当没有光照射时，电阻大小为0.2 MΩ，光敏电阻的信号端（2脚）检测的电压接近0。随着光照强度增大，光敏传感器的电阻值越来越小，所以信号端能检测到的电压越来越大，模拟值也越来越大。

#### 4. 项目接线图：

![Img](./media/B4.png)

#### 5. 在线运行代码：

**<span style="color: rgb(255, 76, 65); font-size: 24px;">特别注意：</span>本教程中使用的代码保存的路径为：“...\代码集\6.Pico主板_Python_教程”中。**

<br>

1.打开Thonny软件，并且单击![Img](./media/48.png)“**打开...**”。

![Img](./media/49.png)

2.在新弹出的窗口中，点击“**此电脑**”。

![Img](./media/50.png)

在新的对话框中，选中“Project_12_Photosensor.py”,单击“**打开**”。

![Img](./media/F3.png)

```Python
from machine import Pin 
import time

PIN_ANALOG_IN = machine.ADC(26)

while True:
    adcvalue1 = PIN_ANALOG_IN.read_u16()
    voltage = adcvalue1 / 65535.0 * 3.3
    print(" ADC Value: ", adcvalue1, " Voltage: ", voltage, " V")
    time.sleep(0.2)
```

#### 6. 项目现象：

按照接线图正确接好模块，利用MicroUSB线连接到计算机上电，利用MicroUSB线连接到计算机上电，单击![Img](./media/52.png)来执行程序代码。代码开始执行，你会看到的现象是：Shell窗口中打印出光敏传感器读取的ADC值和电压值。光照越强，可以看到ADC值和电压值越大。

![Img](./media/ABC13.jpg)

![](./media/C17.png)

当在线运行时，单击![Img](./media/54.png)或按Ctrl+C退出程序。

#### 7. 代码说明:

| 代码                                 | 说明                                                         |
| ------------------------------------ | ------------------------------------------------------------ |
|PIN_ANALOG_IN = machine.ADC(26)|光敏传感器模块的模拟管脚为GPIO26，也是0通道即ADC(0)。|
|PIN_ANALOG_IN.read_u16()|读取光敏传感器的ADC值，范围为0~65535，那么PIN_ANALOG_IN.read_u16()即读取ADC(26)引脚输入的ADC值，然后赋给名为adcvalue1的变量|
|voltage = adcvalue1 / 65535.0 * 3.3  | 将光敏传感器读取的光照强度ADC值转化成电压值。            |
|print()|Shell窗口打印|

---

### 项目13 水滴传感器

#### 1. 项目介绍：

水滴传感器模块有个信号输出端，可以输出水量大小的模拟信号。在本项目中，我们将读取传感器的ADC值和电压值，并将测试结果在Shell窗口中打印显示出来。

#### 2. 项目元件：

|![Img](./media/1.png)|![Img](./media/6.png)|![Img](./media/C6.png)|![Img](./media/30.jpg)|![Img](./media/2.png)|
| :--: | :--: | :--: |:--: |:--: |
|树莓派Pico主板*1|面包板*1|水滴传感器模块*1|公对母杜邦线若干|MicroUSB线*1|

#### 3. 元件知识：

![Img](./media/C6.png)

**水滴传感器:** 是一个模拟（数字）输入模块，也叫雨水、雨量传感器。可用于各种天气状况的监测，检测是否下雨及雨量的大小，转成模拟信号（AO）输出，并广泛应用于各种天气状况的监测，也可用于汽车自动刮水系统、智能灯光系统和智能天窗系统等。

**模块参数:**

工作电压: DC 3.3 ~ 5V 

工作电流: 1.5MA

最大功率: 0.0075W

工作温度：-10°C ~ +50°C

输出信号: 模拟信号

尺寸：32 mm x 23.8 mm x 9.3 mm

定位孔大小：直径为 4.8 mm

**模块原理图:**

![](media/C18.jpg)

水滴传感器通过电路板上裸露的印刷平行线检测水量的大小。水量越多，就会有更多的导线被联通，随着导电的接触面积增大，雨滴感应区 2 脚输出的电压就会逐步上升。信号端 S 检测到的模拟值就越大。除了可以检测水量的大小，它还可以检测空气中的水蒸气。

#### 4. 项目接线图：

![Img](./media/B5.png)

#### 5. 在线运行代码：

**<span style="color: rgb(255, 76, 65); font-size: 24px;">特别注意：</span>本教程中使用的代码保存的路径为：“...\代码集\6.Pico主板_Python_教程”中。**

<br>

1.打开Thonny软件，并且单击![Img](./media/48.png)“**打开...**”。

![Img](./media/49.png)

2.在新弹出的窗口中，点击“**此电脑**”。

![Img](./media/50.png)

在新的对话框中，选中“Project_13_Steam_Sensor.py”,单击“**打开**”。

![Img](./media/F4.png)

```Python
from machine import Pin 
import time

PIN_ANALOG_IN = machine.ADC(26)

while True:
    adcvalue1 = PIN_ANALOG_IN.read_u16()
    voltage = adcvalue1 / 65535.0 * 3.3
    print(" ADC Value: ", adcvalue1, " Voltage: ", voltage, " V")
    time.sleep(0.2)
```

#### 6. 项目现象：

按照接线图正确接好模块，利用MicroUSB线连接到计算机上电，利用MicroUSB线连接到计算机上电，。

![](./media/C20.png)

单击![Img](./media/52.png)来执行程序代码，代码开始执行，在水滴传感器的感应区滴一两滴水（**小心用水，注意不要滴到感应区以外的其他任何地方，包括树莓派Pico主板**），你会看到的现象是：Shell窗口中打印出此时水滴传感器的ADC值和电压值。水量变化，ADC值和电压值也会发生变化。水量越多，输出的ADC值和电压值越大。

![Img](./media/ABC12.jpg)

![](./media/C19.png)

当在线运行时，单击![Img](./media/54.png)或按Ctrl+C退出程序。

#### 7. 代码说明:

可以参照项目12的代码说明，这里就不多做介绍了。

---

### 项目14 声音传感器

#### 1. 项目介绍：

声音传感器将外界声音的大小转换成对应的模拟信号，然后通过模块上的信号输出端输出。在本项目中，我们将读取传感器的ADC值和电压值，并将测试结果在Shell窗口中打印显示出来。

#### 2. 项目元件：

|![Img](./media/1.png)|![Img](./media/6.png)|![Img](./media/C7.png)|
| :--: | :--: | :--: |
|树莓派Pico主板*1|面包板*1|声音传感器模块*1|
|![Img](./media/30.jpg)|![Img](./media/2.png)|![Img](./media/A25.png)|
|公对母杜邦线若干|MicroUSB线*1|一字螺丝刀*1|

#### 3. 元件知识：

![Img](./media/C7.png)

**声音传感器:** 声音传感器通常用于检测周围环境中的声音响度。微型控制板可以通过模拟输入接口采集其输出信号。S引脚是模拟输出，是麦克风电压信号的实时输出。传感器附带一个电位器，这样你就可以调整信号强度。你可以使用它来制作一些交互式作品，如语音操作的开关等。

**模块参数:**

工作电压: DC 3.3 ~ 5V 

工作电流: 1.5MA

最大功率: 0.075W

工作温度：-10°C ~ +50°C

输出信号: 模拟信号

尺寸：32 mm x 23.8 mm x 10.3 mm

定位孔大小：直径为 4.8 mm

**模块原理图:**

![](media/C21.png)

声音传感器主要由一个高感度麦克风元件和LM386音频功率放大器芯片组成。高感度麦克风元件用于检测外界的声音。利用LM386音频功率放大器芯片设计对高感度麦克风检测到的声音进行放大的电路，最大倍数为200倍。使用时我们可以通过旋转传感器上电位器，调节声音的放大倍数。顺时针调节电位器到尽头，放大倍数最大。

#### 4. 项目接线图：

![Img](./media/B6.png)

#### 5. 在线运行代码：

**<span style="color: rgb(255, 76, 65); font-size: 24px;">特别注意：</span>本教程中使用的代码保存的路径为：“...\代码集\6.Pico主板_Python_教程”中。**

<br>

1.打开Thonny软件，并且单击![Img](./media/48.png)“**打开...**”。

![Img](./media/49.png)

2.在新弹出的窗口中，点击“**此电脑**”。

![Img](./media/50.png)

在新的对话框中，选中“Project_14_Sound_Sensor.py”,单击“**打开**”。

![Img](./media/F5.png)

```Python
from machine import Pin 
import time

PIN_ANALOG_IN = machine.ADC(26)

while True:
    adcvalue1 = PIN_ANALOG_IN.read_u16()
    voltage = adcvalue1 / 65535.0 * 3.3
    print(" ADC Value: ", adcvalue1, " Voltage: ", voltage, " V")
    time.sleep(0.2)
```

#### 6. 项目现象：

按照接线图正确接好模块，利用MicroUSB线连接到计算机上电，利用MicroUSB线连接到计算机上电，此时声音传感器上的电源指示灯点亮。

![](./media/C23.png)

单击![Img](./media/52.png)来执行程序代码，代码开始执行，你会看到的现象是：Shell窗口中打印出声音传感器接收到的声音对应的ADC值和电压值。对准模块上的MIC头大声说话（或大呼气）时，可以看到接收到的声音对应的ADC值和电压值变大。（**注意：如果声音变化对应的模拟值没有变化并且一直都是数字0，需要用一字螺丝刀顺时针旋转电位器来调节。**）

![Img](./media/ABC11.jpg)

![](./media/C22.png)


当在线运行时，单击![Img](./media/54.png)或按Ctrl+C退出程序。

#### 7. 代码说明:

可以参照项目12的代码说明，这里就不多做介绍了。

---

### 项目15 火焰传感器

#### 1. 项目介绍：

火焰传感器模块有两个信号输出端，分别可输出数字信号与模拟信号。在本项目中，我们分别读取传感器的数字信号、ADC值和电压值，并将测试结果在Shell窗口中打印显示出来。

#### 2. 项目元件：

|![Img](./media/1.png)|![Img](./media/6.png)|![Img](./media/C3.png)|
| :--: | :--: | :--: |
|树莓派Pico主板*1|面包板*1|火焰传感器模块*1|
|![Img](./media/30.jpg)|![Img](./media/2.png)|![Img](./media/A25.png)|
|公对母杜邦线若干|MicroUSB线*1|一字螺丝刀*1|

#### 3. 元件知识：

![Img](./media/C3.png)

**火焰传感器:** 它对火焰光谱特别灵敏，且灵敏度可调。性能稳定，是救火机器人的必备部件。火焰传感器上有一个远红外火焰探头，起着非常重要的作用，它可以用作机器人的眼睛来寻找火源或足球。利用它可以制作灭火机器人、足球机器人等。

**模块参数:**

工作电压: DC 3.3 ~ 5V

工作电流: 1.2MA

最大功率: 0.006W

感应距离: 0~60mm

输出信号：模拟信号和数字信号

工作温度：-10°C ~ +50°C

尺寸：32 mm x 23.8 mm x 9.2 mm

定位孔大小：直径为 4.8 mm

**模块原理图:**

![](media/C24.png)

红外火焰传感器能够探测到波长在700纳米～1000纳米范围内的红外光，探测角度为60，其中红外光波长在880纳米附近时，其灵敏度达到最大。从电路原理图我们可以看到，上电后红色LED2先点亮，红色LED1处于熄灭状态，检测到火焰时，数字信号端D0输出低电平，红色LED1将点亮。红外火焰探头将外界红外光的强弱变化转化为电流的变化，通过A/D转换器反映为0～255范围内数值的变化。外界红外光越强，数值越小；红外光越弱，数值越大。

#### 4. 项目接线图：

![Img](./media/B7.png)

#### 5. 在线运行代码：

**<span style="color: rgb(255, 76, 65); font-size: 24px;">特别注意：</span>本教程中使用的代码保存的路径为：“...\代码集\6.Pico主板_Python_教程”中。**

<br>

1.打开Thonny软件，并且单击![Img](./media/48.png)“**打开...**”。

![Img](./media/49.png)

2.在新弹出的窗口中，点击“**此电脑**”。

![Img](./media/50.png)

在新的对话框中，选中“Project_15_Flame_Sensor.py”,单击“**打开**”。

![Img](./media/F6.png)

```Python
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
```

#### 6. 项目现象：

按照接线图正确接好模块，利用MicroUSB线连接到计算机上电，利用MicroUSB线连接到计算机上电，此时火焰传感器上的红色LED2点亮。使用一字螺丝刀旋转火焰传感器上的电位器，微调使传感器上红色LED1灯介于亮与不亮之间的**不亮**状态。如下图所示。

![img](media/C26.png)

单击![Img](./media/52.png)来执行程序代码。代码开始执行，你会看到的现象是：Shell窗口中打印出火焰传感器的D0值“1”和字符串“All going well”。当传感器检测到火焰时，红色LED1点亮，可以看到D0值由“1”变为“0”，字符串“All going well”变为“on fire!”，还打印出ADC值和电压值，同时传感器检测到的火焰越大，ADC值和电压值反而越小。

![Img](./media/ABC10.jpg)

![](./media/C25.png)


当在线运行时，单击![Img](./media/54.png)或按Ctrl+C退出程序。

#### 7. 代码说明:

可以参照项目09和项目12的代码说明，这里就不多做介绍了。

---

### 项目16 模拟气体(MQ-2)传感器

#### 1. 项目介绍：

模拟气体(MQ-2)传感器模块有两个信号输出端，分别可输出数字信号与模拟信号。在本项目中，我们分别读取传感器的数字信号、ADC值和电压值，并将测试结果在Shell窗口中打印显示出来。

#### 2. 项目元件：

|![Img](./media/1.png)|![Img](./media/6.png)|![Img](./media/37.png)|
| :--: | :--: | :--: |
|树莓派Pico主板*1|面包板*1|模拟气体(MQ-2)传感器模块*1|
|![Img](./media/30.jpg)|![Img](./media/2.png)|![Img](./media/A25.png)|
|公对母杜邦线若干|MicroUSB线*1|一字螺丝刀*1|

#### 3. 元件知识：

![Img](./media/37.png)

**模拟气体(MQ-2)传感器:** 它主要用到了MQ-2 可燃气体、烟雾传感器元件。该元件所使用的气敏材料是在清新空气中电导率较低的二氧化锡(SnO2)。当传感器所处环境中存在可燃气体时，传感器的电导率随空气中可燃气体浓度的增加而增大。该传感器对液化气、丙烷、氢气的灵敏度高，对天然气和其它可燃蒸汽的检测也很理想。它可检测多种可燃性气体，是一款适合多种应用的低成本传感器。

**模块参数:**

工作电压 : DC 3.3 ~ 5V

工作电流 : 100 mA

最大功率 : 0.5 W

输出信号 ：模拟信号和数字信号

工作温度 ：-10°C ~ +50°C

尺寸 ：47.6 mm x 23.8 mm x 17.9 mm

定位孔大小：直径为 4.8 mm

**模块原理图:**

![](media/38.png)

模拟气体(MQ-2)传感器与烟雾接触时，晶粒间界处的势垒受到烟雾的浓度变化而变化，就会引起表面导电率的变化。利用这一点就可以获得这种烟雾存在的信息，烟雾的浓度越大，导电率越大，输出电阻越低，则输出的模拟信号就越大。

使用时，A 端读取对应气体的模拟值；D 端连接一个LM393芯片（电压比较器），我们可以通过电位器调节测量气体报警临界点，在 D 端输出数字值。当测量气体含量超过临界点时，D 端输出低电平；测量气体含量没超过临界点时，D 端输出高电平。

#### 4. 项目接线图：

![Img](./media/45.png)

#### 5. 在线运行代码：

**<span style="color: rgb(255, 76, 65); font-size: 24px;">特别注意：</span>本教程中使用的代码保存的路径为：“...\代码集\6.Pico主板_Python_教程”中。**

<br>

1.打开Thonny软件，并且单击![Img](./media/48.png)“**打开...**”。

![Img](./media/49.png)

2.在新弹出的窗口中，点击“**此电脑**”。

![Img](./media/50.png)

在新的对话框中，选中“Project_16_MQ-2_Sensor.py”,单击“**打开**”。

![Img](./media/F7.png)

```Python
from machine import Pin
import machine
import time

PIN_ANALOG_IN = machine.ADC(26)
PIN_DIGITAL_IN = Pin(16, Pin.IN)

while True:
    adcvalue1 = PIN_ANALOG_IN.read_u16()
    voltage = adcvalue1 / 65535.0 * 5.0
    value2 = PIN_DIGITAL_IN.value()
    print("D0:", end = " ")
    print(value2, end = " ") 
    if value2 == 0:
        print(" smoke or flammable gas!", end = " ")
        print(" ADC Value:", adcvalue1, " Voltage:", voltage, "V")
    else:
        print(" All going well")
    time.sleep(0.1)
```

#### 6. 项目现象：

按照接线图正确接好模块，利用MicroUSB线连接到计算机上电，利用MicroUSB线连接到计算机上电，此时模拟气体(MQ-2)传感器上的电源指示灯点亮。使用一字螺丝刀旋转模拟气体(MQ-2)传感器上的电位器，微调使传感器上红色LED灯介于亮与不亮之间的**不亮**状态。如下图所示：

![img](media/66.png)

单击![Img](./media/52.png)来执行程序代码。代码开始执行，你会看到的现象是：Shell窗口中打印出模拟气体(MQ-2)传感器的D0值“1”和字符串“All going well”。当传感器检测到烟雾或可燃性气体时，红色LED点亮，在串口监视器中可以看到D0值由“1”变为“0”，字符串“All going well”变为“smoke or flammable gas!”，还打印出ADC值和电压值，同时传感器检测到的烟雾或可燃性气体浓度越大，ADC值和电压值也越大。

![Img](./media/ABC9.jpg)

![](./media/63.png)


当在线运行时，单击![Img](./media/54.png)或按Ctrl+C退出程序。

#### 7. 代码说明:

可以参照项目09和项目12的代码说明，这里就不多做介绍了。

---

### 项目17 LCD 1602 显示屏

#### 1. 项目介绍：

LCD1602液晶显示屏是广泛使用的一种字符型液晶显示模块。LCD1602液晶显示屏采用标准的14脚（无背光）或16脚（带背光）接口，通过显示屏驱动IC，实现I2C控制，节省了单片机引脚。这一项目中我们将使用LCD1602液晶显示屏显示字符串和计数。

#### 2. 项目元件：

|![Img](./media/1.png)|![Img](./media/C27.png)|![Img](./media/30.jpg)|
| :--: | :--: | :--: |
|树莓派Pico主板*1|LCD1602显示屏模块*1|公对母杜邦线若干|
|![Img](./media/2.png)|![Img](./media/A25.png)| ![Img](./media/6.png)|
|MicroUSB线*1|一字螺丝刀*1|面包板*1|

#### 3. 元件知识：

**I2C串行通信：**

I2C通信协议是Inter-Integrated Circuit（IIC）的缩写，也叫作两线制或TWI（Two-Wire Interface），是一种通用的主从式的两线总线通信协议，它是由Philips Semiconductor公司开发的（现在被美国NXP半导体公司收购）。

其最大的优点是只需要两根线就可以完成数据的传输，对于系统线路的繁琐也减少了很多，这种总线可以并行联结127个节点，并且支持多主机，从机一般不需要外接电源，因为I2C总线可以把电源传输到从机。如下图。

![img](./media/C28.png)

I2C总线的数据传输采用8位数据传输的方式，通常一个字节的数据传输是由9个时钟信号组成，8个时钟信号传输数据，最后一个时钟信号用于传输结束的标志。同时，I2C总线也支持多字节的数据传输，不断重复上述过程，即可完成多字节的数据传输。

I2C协议的基本组成部分包括以下内容：

- 起始信号：在发送数据之前，发送方必须发送起始信号，以告知接收方，要发送数据了。

- 地址码：地址码用于告知接收方，要发送的数据是给谁的。

- 数据：数据按照位传输，每次传输一个字节的数据。 

- 停止信号：发送完数据后，发送方必须发送停止信号，以告知接收方，数据发送完毕。

**串口协议时序如下：**

具体通信协议请移步官网：[https://www.nxp.com/](https://www.nxp.com/)

![img](./media/C29.png)

![img](./media/C30.png)

Arduino提供了一个名为Wire.h的I2C协议集成库，可以通过调用其函数实现I2C通信，从而实现与I2C/TWI设备的通信。

具体库介绍参考官网链接：

[https://www.arduino.cc/reference/en/language/functions/communication/wire/](https://www.arduino.cc/reference/en/language/functions/communication/wire/)


**LCD 1602显示屏：**（1602 Liquid Crystal Display）是一种常见的字符液晶显示器，它是一种专门用来显示字母、数字、符号等的点阵型液晶模块。

字符型液晶，能够同时显示16x02即32个字符。它由若干个点阵字符位组成，每个点阵字符位都可以显示一个字符，每两个点阵字符位之间有一个点距的间隔，每行之间也有间隔，起到了字符间距和行间距的作用，正因为如此所以它不能很好地显示图形。

LCD1602显示屏模块，简化了LCD1602接线 ，使用IIC/I2C接口，不仅方便接线，还更加节省GPIO口。它能兼容Arduino的库文件，方便快速开发。

![Img](./media/C31.png)

可以通过IIC扩展板上的电位器，调节对比度，使用一字螺丝刀旋转电位器。

![Img](./media/E1.png)

**模块参数：**

工作电压 : DC 5V 

工作电流 :  < 130 mA

工作温度 : -10°C ~ +50°C

温度范围 : 0 ~ 50°C (± 2℃) 

IIC地址 : 0x27

尺寸 ：80 mm x 36 mm x 17.2 mm

定位孔大小：直径为 3 mm

**模块原理图：**

![Img](./media/C32.png)

LCD1602 显示屏采用标准的16脚接口，其中：

| 引脚   | 符号     | 引脚说明                                                     |
| ------ | -------- | ------------------------------------------------------------ |
| 1      | VSS      | GND负电源。       |
| 2      | VDD      | 5V正电源。           |
| 3      | V0       | V0为液晶显示器对比度调整端，接正电源时对比度最弱，接地电源时对比度最高。<br>（对比度过高时会 产生“鬼影”，使用时可以通过一个10K的电位器调整对比度。） |
| 4      | RS       | RS为寄存器选择，高电平1时选择数据寄存器、低电平0时选择指令寄存器。 |
| 5      | RW       | RW为读写信号线，高电平(1)时进行读操作，低电平(0)时进行写操作。 |
| 6      | E        | E(或EN)端为使能(enable)端,高电平（1）时读取信息，负跳变时执行指令。 |
| 7 ~ 14 | D0 ~ D14 | D0～D7为8位双向数据端。第15～16脚：空脚或背灯电源。          |
| 15     | BLA      | 背光正极。                                                   |
| 16     | BLK      | 背光负极。                                                   |

LCD1602 显示屏使用时需要至少7个IO口才能驱动起来，占用的IO口太多了，其他传感器就不够用了。IIC LCD1602显示屏模块使用了I2C接口的转接板，使用IIC接口，简化了LCD1602接线 。不仅方便接线，还更加节省IO口。

#### 4. 项目接线图：

![Img](./media/C33.png)

#### 5. 添加库文件：

**<span style="color: rgb(255, 76, 65); font-size: 24px;">特别注意：</span>本教程中使用的代码保存的路径为：“...\代码集\6.Pico主板_Python_教程”中。**

<br>

将文件夹“Project_17_I2C_LCD_1602”复制粘贴(或拖入)到电脑D盘。

![Img](./media/C47.png)

![Img](./media/C48.png)

打开Thonny软件，先单击“**此电脑**”，再双击“Software (D:)”找到文件夹“Project_17_I2C_LCD_1602”。

![Img](./media/C49.png)

![Img](./media/C50.png)

![Img](./media/C51.png)

双击文件夹“Project_17_I2C_LCD_1602”，分别右键点击“I2C_LCD.py”和“LCD_API.py”，选择“上传到/”。

![Img](./media/C51.png)

![Img](./media/C52.png)

![Img](./media/C53.png)

这样，库文件添加好了。

![Img](./media/C54.png)

#### 6. 在线运行代码：

双击“Project_17_I2C_LCD_1602.py”打开文件。

![Img](./media/D55.png)

```Python
import time
from machine import I2C, Pin
from I2C_LCD import I2CLcd

i2c = I2C(1, sda=Pin(14), scl=Pin(15), freq=400000)
devices = i2c.scan()

try:
    if devices != []:
        lcd = I2CLcd(i2c, devices[0], 2, 16)
        lcd.move_to(0, 0)
        lcd.putstr("Hello, world!")
        count = 0
        while True:
            lcd.move_to(0, 1)
            lcd.putstr("Counter:%d" %(count))
            time.sleep(1)
            count += 1
    else:
        print("No address found")
except:
    pass
```

#### 7. 项目现象：

按照接线图正确接好模块，利用MicroUSB线连接到计算机上电。单击![Img](./media/52.png)来执行程序代码，代码开始执行，你会看到的现象是：LCD1602显示屏第一行打印出“ **Hello, world!** ” ，第二行打印出 “**Counter:**”和“**数字**（从数字0逐渐加1）” 。

![Img](./media/C35.png)

当在线运行时，单击![Img](./media/54.png)或按Ctrl+C退出程序。

<span style="color: rgb(255, 76, 65);">注意:</span> 如果你看不见屏幕上的任何东西或显示不清楚，请尝试缓慢旋转LCD1602背面的白色旋钮，以调节对比度，直到屏幕可以清晰显示。

![Img](./media/E1.png)

#### 8. 代码说明：

在每次使用I2CLcd对象之前，请确保已将I2C_LCD.py和LCD_API.py上传到树莓派Pico的“/”目录，然后在python文件的顶部添加语句“from I2C_LCD import I2CLcd”。

| 代码                              | 说明                                               |
| --------------------------------- | -------------------------------------------------- |
| clear(): | 清空显示屏。    |
|show_cursor():| 显示LCD1602的光标。                            |
|hide_cursor():  |隐藏LCD1602的光标。          |
|blink_cursor_on(): |打开光标闪烁 |
|blink_cursor_off(): | 关闭光标闪烁 |
|display_on():  |打开LCD1602的显示功能 |
| display_off(): |关闭LCD1602的显示功能|
|backlight_on():  |打开LCD1602的背光|
|backlight_off():  |关闭LCD1602的背光|
| move_to(cursor_x, cursor_y): |移动光标到指定位置。|
|putchar(char): |打印LCD1602上括号中的字符|
|putstr(string): |打印LCD1602上括号中的字符串。|

---

### 项目18 入侵检测报警器

#### 1. 项目介绍：

前面的项目中我们已经学习了人体红外热释传感器的工作原理，那么，在本项目中，我们将结合人体红外热释传感器、有源蜂鸣器和LED灯来模拟入侵检测报警器。实现人体红外热释传感器检测到附近有人经过时有源蜂鸣器响起，LED灯快速闪烁的效果。

#### 2. 项目元件：

|![Img](./media/1.png)|![Img](./media/6.png)|![Img](./media/C1.png)|![Img](./media/29.png)|![Img](./media/7.png)|
| :--: | :--: | :--: |:--: |:--: |
|树莓派Pico主板*1|面包板*1|人体红外热释传感器模块*1|有源蜂鸣器模块*1|红色LED*1|
|![Img](./media/30.jpg)|![Img](./media/2.png)|![Img](./media/8.png)| ![Img](./media/9.png)| |
|公对母杜邦线若干|MicroUSB线*1|220Ω电阻*1|面包板连接线若干| |

#### 3. 项目接线图：

![Img](./media/C36.png)

#### 4. 在线运行代码：

**<span style="color: rgb(255, 76, 65); font-size: 24px;">特别注意：</span>本教程中使用的代码保存的路径为：“...\代码集\6.Pico主板_Python_教程”中。**

<br>

1.打开Thonny软件，并且单击![Img](./media/48.png)“**打开...**”。

![Img](./media/49.png)

2.在新弹出的窗口中，点击“**此电脑**”。

![Img](./media/50.png)

在新的对话框中，选中“Project_18_PIR_Motion_Alarm.py”,单击“**打开**”。

![Img](./media/F8.png)

```Python
#导入引脚和时间模块
from machine import Pin 
import time 
 
# 定义人体红外传感器，led和主动蜂鸣器的引脚
sensor_pir = machine.Pin(16, machine.Pin.IN)
buzzer = machine.Pin(17, machine.Pin.OUT)
led = machine.Pin(18, machine.Pin.OUT)
 
while True: 
      if sensor_pir.value():
          print("1  ALARM! Motion detected!")
          buzzer.value(1)
          led.value(1)
          time.sleep(0.2)
          buzzer.value(0)
          led.value(0)
          time.sleep(0.2)         
      else:
          buzzer.value(0)
          led.value(0)
```

#### 5. 项目现象：

按照接线图正确接好模块和各元器件，利用MicroUSB线连接到计算机上电，单击![Img](./media/52.png)来执行程序代码。代码开始执行，你会看到的现象是：当人体红外热释传感器检测到附近有人经过时，人体红外热释传感器模块上的红灯灭，有源蜂鸣器发出警报，LED灯快速闪烁，实现入侵检测报警的效果。

![Img](./media/ABC8.jpg)

当在线运行时，单击![Img](./media/54.png)或按Ctrl+C退出程序。

#### 6. 代码说明:

| 代码                   | 说明                                     |
| ---------------------- | ---------------------------------------- |
|sensor_pir.value() | 人体红外热释传感器读取数字电平信号输出。 运动检测，检测到有人经过。 |
| buzzer.value(1) | 有源蜂鸣器响起发出警报。                 |
| led.value(1)  | LED灯点亮。                      |

---

### 项目19 障碍物检测报警器

#### 1. 项目介绍：

上一项目中我们学习了使用人体红外热释传感器检测附近有人经过时进行报警提醒。在这一本项目中，我们将结合避障传感器、有源蜂鸣器和LED灯来模拟障碍物检测报警器。

#### 2. 项目元件：

|![Img](./media/1.png)|![Img](./media/6.png)|![Img](./media/C2.png)|![Img](./media/29.png)|![Img](./media/7.png)|
| :--: | :--: | :--: |:--: |:--: |
|树莓派Pico主板*1|面包板*1|避障传感器模块*1|有源蜂鸣器模块*1|红色LED*1|
|![Img](./media/30.jpg)|![Img](./media/2.png)|![Img](./media/8.png)| ![Img](./media/9.png)| |
|公对母杜邦线若干|MicroUSB线*1|220Ω电阻*1|面包板连接线若干| |

#### 3. 项目接线图：

![Img](./media/C37.png)

#### 4. 在线运行代码：

**<span style="color: rgb(255, 76, 65); font-size: 24px;">特别注意：</span>本教程中使用的代码保存的路径为：“...\代码集\6.Pico主板_Python_教程”中。**

<br>

1.打开Thonny软件，并且单击![Img](./media/48.png)“**打开...**”。

![Img](./media/49.png)

2.在新弹出的窗口中，点击“**此电脑**”。

![Img](./media/50.png)

在新的对话框中，选中“Project_19_Obstacle_Detection_Alarm.py”,单击“**打开**”。

![Img](./media/F9.png)

```Python
#导入引脚和时间模块
from machine import Pin 
import time 
 
# 定义避障传感器，led和有源蜂鸣器的引脚
sensor_avoid = machine.Pin(16, machine.Pin.IN)
buzzer = machine.Pin(17, machine.Pin.OUT)
led = machine.Pin(18, machine.Pin.OUT)
  
while True: 
      value = sensor_avoid.value()
      if value == 0:
          print("0  ALARM! Obstacles detected!")
          buzzer.value(1)
          led.value(1)
          time.sleep(0.2)
          buzzer.value(0)
          led.value(0)
          time.sleep(0.2)         
      else:
          buzzer.value(0)
          led.value(0)
```

#### 5. 项目现象：

按照接线图正确接好模块和各元器件，利用MicroUSB线连接到计算机上电，单击![Img](./media/52.png)来执行程序代码。代码开始执行，你会看到的现象是：当避障传感器检测到障碍物时，避障传感器模块上的SLED灯亮，有源蜂鸣器发出警报，外接LED灯快速闪烁，实现障碍物检测报警的效果。

![Img](./media/ABC7.jpg)

当在线运行时，单击![Img](./media/54.png)或按Ctrl+C退出程序。

#### 6. 代码说明:

可以参照项目18的代码说明，这里就不多做介绍了。

---

### 项目20 触摸报警

#### 1. 项目介绍：

前面的项目中我们已经学习了电容触摸传感器的工作原理。那么，在本项目中，我们将结合电容触摸传感器、有源蜂鸣器和LED灯来模拟触摸报警。

#### 2. 项目元件：

|![Img](./media/1.png)|![Img](./media/6.png)|![Img](./media/C4.png)|![Img](./media/29.png)|![Img](./media/7.png)|
| :--: | :--: | :--: |:--: |:--: |
|树莓派Pico主板*1|面包板*1|电容触摸传感器模块*1|有源蜂鸣器模块*1|红色LED*1|
|![Img](./media/30.jpg)|![Img](./media/2.png)|![Img](./media/8.png)| ![Img](./media/9.png)| |
|公对母杜邦线若干|MicroUSB线*1|220Ω电阻*1|面包板连接线若干| |

#### 3. 项目接线图：

![Img](./media/C38.png)

#### 4. 在线运行代码：

**<span style="color: rgb(255, 76, 65); font-size: 24px;">特别注意：</span>本教程中使用的代码保存的路径为：“...\代码集\6.Pico主板_Python_教程”中。**

<br>

1.打开Thonny软件，并且单击![Img](./media/48.png)“**打开...**”。

![Img](./media/49.png)

2.在新弹出的窗口中，点击“**此电脑**”。

![Img](./media/50.png)

在新的对话框中，选中“Project_20_Touch_Alarm.py”,单击“**打开**”。

![Img](./media/F10.png)

```Python
#导入引脚和时间模块
from machine import Pin 
import time 
  
# 定义电容触摸传感器，led和有源蜂鸣器的引脚
sensor_touch = machine.Pin(16, machine.Pin.IN)
buzzer = machine.Pin(17, machine.Pin.OUT)
led = machine.Pin(18, machine.Pin.OUT)
  
while True: 
      value = sensor_touch.value()
      if value == 1:
          print("1  ALARM! Touch detected!")
          buzzer.value(1)
          led.value(1)
          time.sleep(0.2)
          buzzer.value(0)
          led.value(0)
          time.sleep(0.2)         
      else:
          buzzer.value(0)
          led.value(0)
```

#### 5. 项目现象：

按照接线图正确接好模块和各元器件，利用MicroUSB线连接到计算机上电，单击![Img](./media/52.png)来执行程序代码。代码开始执行，你会看到的现象是：用手指触摸电容触摸传感器模块上的感应区时，模块上的板载红色LED灯点亮，有源蜂鸣器发出警报，外接LED灯快速闪烁，实现触摸检测报警的效果。

![Img](./media/ABC6.jpg)

当在线运行时，单击![Img](./media/54.png)或按Ctrl+C退出程序。

#### 6. 代码说明:

可以参照项目18的代码说明，这里就不多做介绍了。

---

### 项目21 火焰报警

#### 1. 项目介绍：

生活中，火灾的危害是相当大的。这一课我们来学习制作一个火灾报警系统，它虽然简单，但却是非常具有意义的。原理很简单，利用火焰传感器检测，检测的结果控制一个有源蜂鸣器响起，LED闪烁，实现火焰报警的效果。

#### 2. 项目元件：

|![Img](./media/1.png)|![Img](./media/6.png)|![Img](./media/C3.png)|![Img](./media/29.png)|![Img](./media/7.png)|
| :--: | :--: | :--: |:--: |:--: |
|树莓派Pico主板*1|面包板*1|火焰传感器模块*1|有源蜂鸣器模块*1|红色LED*1|
|![Img](./media/30.jpg)|![Img](./media/2.png)|![Img](./media/8.png)| ![Img](./media/9.png)| |
|公对母杜邦线若干|MicroUSB线*1|220Ω电阻*1|面包板连接线若干| |

#### 3. 项目接线图：

![Img](./media/C42.png)

#### 4. 在线运行代码：

**<span style="color: rgb(255, 76, 65); font-size: 24px;">特别注意：</span>本教程中使用的代码保存的路径为：“...\代码集\6.Pico主板_Python_教程”中。**

<br>

1.打开Thonny软件，并且单击![Img](./media/48.png)“**打开...**”。

![Img](./media/49.png)

2.在新弹出的窗口中，点击“**此电脑**”。

![Img](./media/50.png)

在新的对话框中，选中“Project_21_Flame_Alarm.py”,单击“**打开**”。

![Img](./media/F11.png)

```Python
#导入引脚和时间模块
from machine import Pin 
import time  
 
# 定义火焰传感器，led和有源蜂鸣器的引脚
sensor_flame = machine.Pin(16, machine.Pin.IN)
buzzer = machine.Pin(17, machine.Pin.OUT)
led = machine.Pin(18, machine.Pin.OUT)
  
while True: 
      value = sensor_flame.value()
      if value == 0:
          print("ALARM! Fire detected!")
          buzzer.value(1)
          led.value(1)
          time.sleep(0.2)
          buzzer.value(0)
          led.value(0)
          time.sleep(0.2)         
      else:
          buzzer.value(0)
          led.value(0)
```

#### 5. 项目现象：

按照接线图正确接好模块和各元器件，利用MicroUSB线连接到计算机上电，单击![Img](./media/52.png)来执行程序代码。代码开始执行，你会看到的现象是：当火焰传感器检测到火焰时，有源蜂鸣器发出警报，LED灯快速闪烁，实现火焰检测报警的效果。

![Img](./media/ABC5.jpg)

当在线运行时，单击![Img](./media/54.png)或按Ctrl+C退出程序。

#### 6. 代码说明:

可以参照项目18的代码说明，这里就不多做介绍了。

---

### 项目22 夜光灯

#### 1. 项目介绍：

前面我们已经学习了光敏传感器的工作原理，在这一项目中，我们将光敏传感器和LED灯组合实验，实现光敏传感器检测到光照强度模拟值高于设定值时LED灯熄灭，低于设定值时LED灯点亮的效果。

#### 2. 项目元件：

|![Img](./media/1.png)|![Img](./media/6.png)|![Img](./media/C5.png)|![Img](./media/7.png)|
| :--: | :--: | :--: |:--: |
|树莓派Pico主板*1|面包板*1|光敏传感器模块*1|红色LED*1|
|![Img](./media/30.jpg)|![Img](./media/2.png)|![Img](./media/8.png)| ![Img](./media/9.png)|
|公对母杜邦线若干|MicroUSB线*1|220Ω电阻*1|面包板连接线若干|

#### 3. 项目接线图：

![Img](./media/C39.png)

#### 4. 在线运行代码：

**<span style="color: rgb(255, 76, 65); font-size: 24px;">特别注意：</span>本教程中使用的代码保存的路径为：“...\代码集\6.Pico主板_Python_教程”中。**

<br>

1.打开Thonny软件，并且单击![Img](./media/48.png)“**打开...**”。

![Img](./media/49.png)

2.在新弹出的窗口中，点击“**此电脑**”。

![Img](./media/50.png)

在新的对话框中，选中“Project_22_Night_Lamp.py”,单击“**打开**”。

![Img](./media/F12.png)

<span style="color: rgb(255, 76, 65);">注意：</span>代码中的阈值30000可以根据环境中实际的光照强度更改。

```Python
#导入引脚和时间模块 
from machine import Pin  
import time   
  
# 定义光敏传感器，led的引脚
sensor_photosensor = machine.ADC(26)
led = machine.Pin(18, machine.Pin.OUT)
  
while True: 
      adcvalue = sensor_photosensor.read_u16()
      if adcvalue > 30000:
          led.value(0)
          print(adcvalue, "LED OFF!")
          time.sleep(0.2)
      else:
          led.value(1)
          print(adcvalue, "LED ON!")
          time.sleep(0.2)
```

#### 5. 项目现象：

按照接线图正确接好模块和各元器件，利用MicroUSB线连接到计算机上电，单击![Img](./media/52.png)来执行程序代码。代码开始执行，你会看到的现象是：使用手机的照明灯对着光敏传感器模块上的光敏电阻照射，当光敏传感器检测到光照强度的ADC值大于30000时，LED灯熄灭；否则，低于设定值时，LED灯点亮，实现了夜光灯的效果。

![Img](./media/ABC4.jpg)

当在线运行时，单击![Img](./media/54.png)或按Ctrl+C退出程序。

#### 6. 代码说明:

| 代码                                 | 说明                                                         |
| ------------------------------------ | ------------------------------------------------------------ |
| if... else：...                        | 当if后面的逻辑判断为True时，执行if下缩进的代码；否则执行else下缩进的代码。python代码是严格使用缩进的。 |
|adcvalue > 30000:|光照强度检测，检测到光照强度的ADC值大于30000。|
| led.value(1)  | LED灯点亮。                      |
|led.value(0) | LED灯熄灭。                      |

---

### 项目23 声控灯

#### 1. 项目介绍：

如今智能家居发展迅速，你使用过智能家居当中的智能声控灯吗？当我们跺跺脚或者拍拍手时，智能声控灯自动亮起；当没有声音时，智能声控灯处于熄灭状态。智能声控灯上安装有声音探测传感器，这些传感器将外界声音的大小，转换成对应数值。智能声控灯设置一个临界点，当声音转换后对应的数值超过该临界点时，灯光亮起一段时间。 

在这一实验课程中，我们将声音传感器和LED灯组合实验，学习制作一个最简单的智能声控灯。


#### 2. 项目元件：

|![Img](./media/1.png)|![Img](./media/6.png)|![Img](./media/C7.png)|![Img](./media/7.png)|
| :--: | :--: | :--: |:--: |
|树莓派Pico主板*1|面包板*1|声音传感器模块*1|红色LED*1|
|![Img](./media/30.jpg)|![Img](./media/2.png)|![Img](./media/8.png)| ![Img](./media/9.png)|
|公对母杜邦线若干|MicroUSB线*1|220Ω电阻*1|面包板连接线若干|

#### 3. 项目接线图：

![Img](./media/C40.png)

#### 4. 在线运行代码：

**<span style="color: rgb(255, 76, 65); font-size: 24px;">特别注意：</span>本教程中使用的代码保存的路径为：“...\代码集\6.Pico主板_Python_教程”中。**

<br>

1.打开Thonny软件，并且单击![Img](./media/48.png)“**打开...**”。

![Img](./media/49.png)

2.在新弹出的窗口中，点击“**此电脑**”。

![Img](./media/50.png)

在新的对话框中，选中“Project_23_Sound_Controlled_Lamp.py”,单击“**打开**”。

![Img](./media/F13.png)

<span style="color: rgb(255, 76, 65);">注意：</span>代码中的阈值10000可以根据实际情况更改的。

```Python
#导入引脚和时间模块 
from machine import Pin  
import time   
   
# 定义声音传感器，led的引脚
sensor_sound = machine.ADC(26)
led = machine.Pin(18, machine.Pin.OUT)
  
while True: 
      adcvalue = sensor_sound.read_u16()
      if adcvalue > 10000:
          print(adcvalue, "LED ON!")
          led.value(1)
          time.sleep(5)         
      else:
          led.value(0)
          print(adcvalue, "LED OFF!")
          time.sleep(0.2)
```

#### 5. 项目现象：

按照接线图正确接好模块和各元器件，利用MicroUSB线连接到计算机上电，单击![Img](./media/52.png)来执行程序代码。代码开始执行，你会看到的现象是：对准模块上的MIC头大声说话（或大呼气），当声音传感器接收到的声音对应的ADC值大于10000时，LED灯亮起5秒，然后熄灭，实现声控灯的效果。

![Img](./media/ABCD3.jpg)

当在线运行时，单击![Img](./media/54.png)或按Ctrl+C退出程序。

#### 6. 代码说明:

可以参照项目22的代码说明，这里就不多做介绍了。

---

### 项目24 雨水警报

#### 1. 项目介绍：

前面的项目中我们已经学习了水滴传感器的工作原理，那么，在本项目中，我们将结合水滴传感器、有源蜂鸣器和LED灯来模拟雨水警报。

#### 2. 项目元件：

|![Img](./media/1.png)|![Img](./media/6.png)|![Img](./media/C6.png)|![Img](./media/29.png)|![Img](./media/7.png)|
| :--: | :--: | :--: |:--: |:--: |
|树莓派Pico主板*1|面包板*1|水滴传感器模块*1|有源蜂鸣器模块*1|红色LED*1|
|![Img](./media/30.jpg)|![Img](./media/2.png)|![Img](./media/8.png)| ![Img](./media/9.png)| |
|公对母杜邦线若干|MicroUSB线*1|220Ω电阻*1|面包板连接线若干| |

#### 3. 项目接线图：

![Img](./media/C41.png)

#### 4. 在线运行代码：

**<span style="color: rgb(255, 76, 65); font-size: 24px;">特别注意：</span>本教程中使用的代码保存的路径为：“...\代码集\6.Pico主板_Python_教程”中。**

<br>

1.打开Thonny软件，并且单击![Img](./media/48.png)“**打开...**”。

![Img](./media/49.png)

2.在新弹出的窗口中，点击“**此电脑**”。

![Img](./media/50.png)

在新的对话框中，选中“Project_24_Water_Alarm.py”,单击“**打开**”。

![Img](./media/F14.png)

<span style="color: rgb(255, 76, 65);">注意：</span>代码中的阈值30000可以根据实际情况更改的。

```Python
#导入引脚和时间模块
from machine import Pin 
import time  
 
# 定义水滴传感器，led和有源蜂鸣器的引脚
sensor_steam = machine.ADC(26)
buzzer = machine.Pin(17, machine.Pin.OUT)
led = machine.Pin(18, machine.Pin.OUT)
  
while True:  
      adcvalue = sensor_steam.read_u16()
      if adcvalue > 30000:
          print(adcvalue, "Buzzer sounds and led blinking!")
          buzzer.value(1)
          led.value(1)
          time.sleep(0.5)
          buzzer.value(0)
          led.value(0)
          time.sleep(0.5)         
      else:
          print(adcvalue, "Buzzer won't sound and led off!")
          buzzer.value(0)
          led.value(0)
          time.sleep(0.5)
```

#### 5. 项目现象：

按照接线图正确接好模块和各元器件，利用MicroUSB线连接到计算机上电，单击![Img](./media/52.png)来执行程序代码。代码开始执行，你会看到的现象是：在水滴传感器模块上的感应区滴一两滴水，当水滴传感器检测水量大小输出的ADC值大于30000时，有源蜂鸣器发出警报，外接LED灯快速闪烁，实现雨水警报的效果。

![Img](./media/ABC3.jpg)

当在线运行时，单击![Img](./media/54.png)或按Ctrl+C退出程序。

#### 6. 代码说明:

可以参照项目22的代码说明，这里就不多做介绍了。

---

### 项目25 烟雾报警器

#### 1. 项目介绍：

在前面课程中，我们学习了如何使用有源蜂鸣器模块、学习了如何使用MQ-2 烟雾传感器检测可燃气体、还学会了如何控制LCD 1602显示屏显示数字或字符。这一课程，我们尝试着将这三个实验结合在一起，制作一个烟雾报警器。制作思路是通过烟雾传感器测试出可燃气体的浓度，然后利用检测结果控制有源蜂鸣器报警、LCD 1602显示屏显示检测到的值。

#### 2. 项目元件：

|![Img](./media/1.png)|![Img](./media/6.png)|![Img](./media/37.png)|![Img](./media/29.png)|![Img](./media/A25.png)|
| :--: | :--: | :--: |:--: |:--: |
|树莓派Pico主板*1|面包板*1|模拟气体(MQ-2)传感器模块*1|有源蜂鸣器模块*1|一字螺丝刀*1|
|![Img](./media/C27.png)|![Img](./media/30.jpg)|![Img](./media/2.png)| ![Img](./media/9.png)| |
|LCD1602显示屏模块*1|公对母杜邦线若干|MicroUSB线*1|面包板连接线若干| |

#### 3. 项目接线图：

![Img](./media/C43.jpg)

#### 4. 添加库文件：

**<span style="color: rgb(255, 76, 65); font-size: 24px;">特别注意：</span>本教程中使用的代码保存的路径为：“...\代码集\6.Pico主板_Python_教程”中。**

<br>

将文件夹“Project_25_Smoke_Alarm”复制粘贴(或拖入)到电脑D盘。

![Img](./media/D56.png)

![Img](./media/D57.png)

打开Thonny软件，先单击“**此电脑**”，再双击“Software (D:)”找到文件夹“Project_25_Smoke_Alarm”。

![Img](./media/C49.png)

![Img](./media/C50.png)

![Img](./media/D58.png)

双击文件夹“Project_25_Smoke_Alarm”，分别右键点击“I2C_LCD.py”和“LCD_API.py”，选择“上传到/”。

![Img](./media/D58.png)

![Img](./media/D59.png)

![Img](./media/D60.png)

这样，库文件添加好了。

![Img](./media/D61.png)

#### 5. 在线运行代码：

双击“Project_25_Smoke_Alarm.py”打开文件。

![Img](./media/D62.png)

<span style="color: rgb(255, 76, 65);">注意：</span>代码中的阈值35000可以根据实际情况更改的。

```Python
#导入I2C_LCD,引脚和时间模块 
import time
from machine import I2C, Pin
from I2C_LCD import I2CLcd 
  
# 定义模拟气体(MQ-2)传感器，LCD和有源蜂鸣器的引脚
sensor_smoke = machine.ADC(26)
buzzer = machine.Pin(17, machine.Pin.OUT)
i2c = I2C(1, sda=Pin(14), scl=Pin(15), freq=400000)
devices = i2c.scan()
adcvalue = 0

try:
    if devices != []:
        lcd = I2CLcd(i2c, devices[0], 2, 16)
        while True:
            adcvalue = sensor_smoke.read_u16()
            lcd.move_to(0, 0)
            lcd.putstr("Val:%d" %(adcvalue))
            time.sleep(0.5)
            lcd.clear()
             
            if adcvalue > 35000:
               lcd.move_to(0, 1)
               lcd.putstr("Smoke!")
               buzzer.value(1)
               
            else:
               lcd.move_to(0, 1)
               lcd.putstr("None!!") 
               buzzer.value(0) 
    else:
         print("No address found")
except:
    pass
```

#### 6. 项目现象：

按照接线图正确接好模块和各元器件，利用MicroUSB线连接到计算机上电，单击![Img](./media/52.png)来执行程序代码。代码开始执行，你会看到的现象是：1602LCD显示屏显示烟雾或可燃性气体相应的ADC值，当模拟气体(MQ-2)传感器检测到烟雾或可燃性气体的ADC值大于35000时，有源蜂鸣器发出警报。

![Img](./media/AB2.jpg)

当在线运行时，单击![Img](./media/54.png)或按Ctrl+C退出程序。

#### 6. 代码说明:

可以参照项目17和参照项目22的代码说明，这里就不多做介绍了。

---

### 项目26 模拟生活场景

#### 1. 项目介绍：

在前面我们做了很多项目实验，我们已经学习了所有的模块和传感器的使用方法，也学习了将它们搭配在一起组合实验。在这一项目实验中我们将搭配更多的模块和传感器组合在一起来模拟生活场景。

#### 2. 项目元件：

|![Img](./media/1.png)|![Img](./media/6.png)|![Img](./media/37.png)|![Img](./media/29.png)|![Img](./media/7.png)|
| :--: | :--: | :--: |:--: |:--: |
|树莓派Pico主板*1|面包板*1|模拟气体(MQ-2)传感器模块*1|有源蜂鸣器模块*1|红色LED*1|
|![Img](./media/C6.png)|![Img](./media/C7.png)|![Img](./media/C27.png)|![Img](./media/C3.png)|![Img](./media/8.png)|
|水滴传感器模块*1|声音传感器模块*1|LCD1602显示屏模块*1|火焰传感器模块*1|220Ω电阻*1|
|![Img](./media/30.jpg)|![Img](./media/2.png)| ![Img](./media/9.png)| ![Img](./media/A25.png)| |
|公对母杜邦线若干|MicroUSB线*1|面包板连接线若干|一字螺丝刀*1 | |

#### 3. 项目接线图：

![Img](./media/C46.png)

#### 4. 添加库文件：

添加库文件的方法请参照**项目17**或**项目25**，这里就不重复讲解。

#### 5. 在线运行代码：

**<span style="color: rgb(255, 76, 65); font-size: 24px;">特别注意：</span>本教程中使用的代码保存的路径为：“...\代码集\6.Pico主板_Python_教程”中。**

<br>

1.打开Thonny软件，并且单击![Img](./media/48.png)“**打开...**”。

![Img](./media/49.png)

2.在新弹出的窗口中，点击“**此电脑**”。

![Img](./media/50.png)

在新的对话框中，选中“Project_26_Simulate_Smart_Home.py”,单击“**打开**”。

![Img](./media/F15.png)

<span style="color: rgb(255, 76, 65);">注意：</span>代码中的阈值可以根据实际情况更改的。

```Python
#导入I2C_LCD,引脚和时间模块 
import time
from machine import I2C, Pin
from I2C_LCD import I2CLcd
  
# 定义水滴传感器，声音传感器，模拟气体(MQ-2)传感器，火焰传感器，LED，LCD和有源蜂鸣器的引脚
sensor_steam = machine.ADC(26)
sensor_sound = machine.ADC(27)
sensor_smoke = machine.ADC(28)
sensor_flame = machine.Pin(16, machine.Pin.IN)
buzzer = machine.Pin(14, machine.Pin.OUT)
led = machine.Pin(15, machine.Pin.OUT)
i2c = I2C(0, sda=Pin(20), scl=Pin(21), freq=400000)
devices = i2c.scan()

adcvalue1 = 0
adcvalue2 = 0
adcvalue3 = 0
val4 = 0

try:
    if devices != []:
        lcd = I2CLcd(i2c, devices[0], 2, 16)

        while True:
            adcvalue1 = sensor_steam.read_u16()
            adcvalue2 = sensor_sound.read_u16()
            adcvalue3 = sensor_smoke.read_u16()
            val4 = sensor_flame.value()

            lcd.move_to(0, 0)
            lcd.putstr("Val:%d" %(adcvalue3))
            time.sleep(0.2)
            lcd.clear()
            
            print("water_volume: ", adcvalue1, " sound_volume: ", adcvalue2)

            if adcvalue1 > 10000:
                buzzer.value(1)
                led.value(1)
                time.sleep(0.1)
                buzzer.value(0)
                led.value(0)
                time.sleep(0.1)
            else:   
                buzzer.value(0)
                led.value(0)
             
            if adcvalue2 > 9000:
                led.value(1)
                time.sleep(5)
            else:    
                led.value(0)
            
            if adcvalue3 > 12000:
                lcd.move_to(0, 1)
                lcd.putstr("Smoke!")
                buzzer.value(1)
            else:
                lcd.move_to(0, 1)
                lcd.putstr("None!!")
                buzzer.value(0) 
               
            if val4 == 0:
                buzzer.value(1)
                led.value(1)
                time.sleep(0.1)
                buzzer.value(0)
                led.value(0)
                time.sleep(0.1)         
            else:
                buzzer.value(0)
                led.value(0)
        
    else:
         print("No address found")
except:
    pass
```

#### 6. 项目现象：

按照接线图正确接好模块和各元器件，利用MicroUSB线连接到计算机上电，单击![Img](./media/52.png)来执行程序代码。代码开始执行，你会看到的现象及功能如下：

（1）下雨警报：当水滴滴传感器检测数据大于10000时，蜂鸣器警报，LED灯闪烁，否则蜂鸣器不响，LED灯不亮。

（2）智能声控灯：我们跺跺脚或者拍拍手，当声音传感器检测到外界声音大小大于9000时，智能声控灯自动亮起5秒钟；当没有声音时，智能声控灯处于熄灭状态。

（3）煤气警报：1602LCD显示屏显示烟雾或可燃性气体相应的模拟值，当模拟气体(MQ-2)传感器检测到烟雾或可燃性气体时（ADC值>12000，这里可以用打火机气体测试），模块上的板载红色LED灯点亮，同时蜂鸣器发声警报，否则，蜂鸣器不响。

（4）火灾警报：当火焰传感器检测到火焰时，模块上的板载红色LED灯点亮，同时有源蜂鸣器发出警报，LED灯快速闪烁；否则蜂鸣器不响，LED灯不亮。

![Img](./media/AB1.jpg)

当在线运行时，单击![Img](./media/54.png)或按Ctrl+C退出程序。

#### 7. 代码说明:

可以参照前面的项目实验的代码说明，这里就不多做介绍了。

---







