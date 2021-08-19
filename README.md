## Index

- [About - MCU Algorithms](#about-mcu-algorithms)
- [Pupose](#purpose)
- [Joystick](#joystick)
- [Functions](#functions)
    - [Map()](#map-function)

</hr>

## About MCU-Algorithms <a name="about-mcu-algorithms"></a>

<p>The MCU-Algorithms is a collection of small C++ snippets yet they're complete as stand-alone code. </p>

</hr>

## Joystick <a name="joystick"></a>

<p>
The analog 2-axis thumb joystick with button by Makerfabs (China). The joystick has two analog(10k potentiometers), you'll need two analog (ADC) reading pins on your microcontroller to determine X and Y.
<p/>

## Functions <a name="functions"></a>

<p>
The list of functions are used to support the analog joystick.
<p/>

<p>
 - <strong>(T) class-name::map(T-parameters)<strong/> <a name="map-function"></a> The function maps the domain of (x) onto the range of f(x) such that f(x) is a linear function where f(x) = ax + b. The T-parameters uses a known value (x) and two known points P1(x1, y1) and P2(x2, y2) where the parameters are map(x, x1, x2, y1, y2). The return type (T) is the unknown value f(x) = y. The template type (T) defines the template data type such as int or float.
  </p>

  <p>Work in Process ~ LIBRARY<p/>
