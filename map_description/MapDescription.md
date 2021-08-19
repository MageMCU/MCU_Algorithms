## Map Description

<p>
The map() function as described under Arduino Reference - Functions - Math: Re-maps a number from one range to another.
</p>

<p>
In basic algebra, it is a linear function mapping x to f(x) where f(x) = ax + b.
<p/>

<p>
(a) The common slope-intercept form for the equation of a line with slope m and y-intercept: 
<p/>

<p align="center">
<strong>y= mx + b<strong/>
<p/>

<p>
(b) The slope m of the line through two points P1(x1, y1) and P2(x2, y2):
<p/>

<p align="center">
<strong>m = (y2 - y1) / (x2 - x1)<strong/>
<p/>

<p>
(c) The point-slope form for the equation of a line through P1(x1, y1) with slope m:
<p/>

<p align="center">
<strong>y - y1 = m(x - x1)<strong/>
<p/>

<p>
(d) The map() function combines both the slope equation (b) and the point-slope form equation (c) together:
<p/>

<p align="center">
<strong>y = (y2 - y1) * (x - x1) / (x2 - x1) + y1<strong/>
<p/>

<p>
The problem when using the map() function, is the ordered pair (x, y) values where the values within the two points P1(x1, y1) and P2(x2, y2) are mismatched. A good test for beginners is trying to convert the Fahrenheit to Celsius scales (or Celsius to Fahrenheit) by matching the boiling points and the freezing points of water thus creating two points P1 and P2. The mismatching comes about when mixing apples with oranges or precisely, mixing a boilin point with a freezing point of water as a Point of an order pair P(x, y). The correct way of matching an order pair for example, temperature of boiling water as P(212, 100) or as P(100, 212) is relative in that water boils at 212 degrees Fahrenheit and 100 degrees Celsius.
<p/>

<p>
Knowing the boiling and freezing points of water, convert 75 degrees Fahrenheit to Celsius using equation (d).
<p/>

<p>
The input for the <strong>map(x, x1, x2, y1, y2)<strong/> function ought to look like the following:
<p/>

<p>
<strong>y = map(75, 32, 212, 0, 100)<strong/> where the ordered pairs are (x1, y1) = (32, 0) and (x2, y2) = (212, 100).
<p/>

<p>
The map() fuction might be used to center a thumb joystick ADC readings offset back to its midpoint mathematically where it ought to be. The cheap joysticks are far from perfect where the center point is a common problem. Also the map() function can be used to jump-over the ADC readings of the static friction (whining not rotating) to the start of the ADC readings of the kinetic friction (rotating) of the wheeled motors while under the load of the robot. The manipulation of ADC data for the friction example will conserve energy of the robot's main battery not to mention the removing of the joystick's dead-space before the motor actually starts moving.
<p/>

<p>
A final note on the scientific method used to answer basic questions to improve the performance of the robot. For example, to determine the kinetic friction ADC values for a differential drive mobile robot, experimentation is necessay using either an engineering log or science lab notebook to answer such questions. The investigative results that answers such questions will always be an arms length away.
<p/>

<p>
The map() function although simple in appearance yet with careful study, the map() function is a powerful tool. This method can be expanded to arrays of points such as Least Squares Fitting (x, f(x)) for example and then protracting the experimetntal (x) values onto F(x). Lidar distance readings never give a set of points to form a perfect line nor a perfect curve. Is this apples and oranges? Maybe! Applied Math is the scientist and engineer's most important tool even though the mathematician might disagree.
<p/>
