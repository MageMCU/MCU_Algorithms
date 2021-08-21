## Index

- [About - MCU Algorithms](#about-mcu-algorithms)
  - [MCU Chip](#mcu-chip)
- [Joystick](#joystick)
  - [Functions](#joystick-functions)
    - [Map()](#map-function)
    - [More Functions to Come](#more-to-come)
- [Motor Driver L298N](#L298N)
  - [Functions](#L298N-functions)
    - [PINS()](#pins-function)

</hr>

## About MCU-Algorithms <a name="about-mcu-algorithms"></a>

The MCU-Algorithms is a collection of small C++ snippets yet they're complete as stand-alone code.

## MCU chip  <a name="mcu-chip"></a>

This MCU chip **Atmega328P** is well known and the price is affordable as well as most of the robotic hardware that is used here. The **cheaper** ... the **better**... Knowledge for those who are **starving** to learn.

</hr>

## Joystick <a name="joystick"></a>

The analog 2-axis thumb joystick with button by Makerfabs (China). The joystick has two analog(10k potentiometers), you'll need two analog (ADC) reading pins on your microcontroller to determine X and Y.

### Joystick Functions <a name="joystick-functions"></a>

The list of functions used to support the analog joystick.

 - **Map()** <a name="map-function"></a> <br/> (T) namespace::class-name::map(T-parameters) - The function maps the domain of (x) onto the range of f(x) such that f(x) is a linear function where f(x) = ax + b. The T-parameters uses a known value (x) and two known points P1(x1, y1) and P2(x2, y2) where the parameters are map(x, x1, x2, y1, y2). The return type (T) is the unknown value f(x) = y. The template type (T) defines the template data type such as int or float.

   - For more comprehensive details, see map_description.

 - More Functions to Come <a name="more-to-come"></a>

</hr>

## L298N Motor Driver <a name="L298N"></a>

The double H bridge motor drive module (uses ST company's L298N as the main driver chip) by Album (China). The module is featuring strong driving capability, low heat generation and strong anti-interference ability. This module can use the built-in 78M05 to take power through the drive power supply part, but in order to avoid the damage of the voltage regulator chip, when using **the drive voltage greater than 12V**, please use the **external** 5V logic power supply. This module uses a large-capacity filter capacitor and a freewheeling protection diode to improve reliability. You'll need two PWM pins for ENA and ENB and four digital pins for IN1, IN2, IN3 and IN4.

**Warning:** *Never use any combination of input pins on **HIGH** at any one time or something may begin to smell or worse **smoke**. Always setup the input pins to **LOW**. When changing a pair of input pins from **LOW** to **HIGH** always set the top input pin to **LOW** first then the next input pin the **HIGH**.*

### L298N Functions <a name="L298N-functions"></a>

 - **PINS()** <a name="pins-function"></a><br/> pending ...

*Work in Process...organizing and that darn github text syntax stuff!*
