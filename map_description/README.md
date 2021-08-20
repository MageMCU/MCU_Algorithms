## Map Description

The map() function as described under Arduino Reference - Functions - Math: Re-maps a number from one range to another.

In basic algebra, it is a linear function mapping x to f(x) where f(x) = ax + b.

- (a) The common slope-intercept form for the equation of a line with slope m and y-intercept: 

> y = mx + b 

- (b) The slope m of the line through two points P1(x1, y1) and P2(x2, y2):

> m = (y2 - y1) / (x2 - x1)

- (c) The point-slope form for the equation of a line through P1(x1, y1) with slope m:

> y - y1 = m(x - x1)

- (d) The map() function combines both the slope equation (b) and the point-slope form equation (c) together:

> y = (y2 - y1) * (x - x1) / (x2 - x1) + y1

The problem when using the map() function, is the ordered pair (x, y) values where the values within the two points P1(x1, y1) and P2(x2, y2) are mismatched. A good test for beginners is trying to convert the Fahrenheit to Celsius scales (or Celsius to Fahrenheit) by matching the boiling-points and the freezing-points of water thus creating two points P1 and P2. The mismatching comes about when mixing apples with oranges or precisely, mixing a boiling-point value with a freezing-point value of water as a Point of an order pair P(x, y). The matching of an order pair for example, should be temperature of boiling water as P(212, 100) or as P(100, 212) relative in that water boils at 212 degrees Fahrenheit and 100 degrees Celsius.

Knowing the boiling and freezing-points of water, convert 75 degrees Fahrenheit to Celsius using equation (d). The input for the map(x, x1, x2, y1, y2) function ought to look like the following: y = map(75, 32, 212, 0, 100) where the ordered pairs are (x1, y1) = (32, 0) and (x2, y2) = (212, 100).

The map() function can be used to extrapolate beyond the two points P1 and P2 for example to compute the Celcius temperature from 0 degrees Fahrenheit. On the other hand when using embedded firmware (software), the points P1 and P2 are used as bounds because the data between the points inclusively are of more use for linear transformations.

The map() fuction might be used to center a thumb joystick ADC readings offset back to its midpoint mathematically where it ought to be. The cheap joysticks are far from perfect where the center point is a common problem. Also the map() function can be used to jump-over the ADC readings of the static friction of the whining non-rotating motor. Then move to the start of the ADC readings that just begins the kinetic friction of the rotating motor all the  while under the full weight of the robot. The manipulation of ADC data for the friction example will undoubtedly conserve energy of the robot's main battery not to mention the removing of the joystick's dead-space before the motor actually starts moving.

An alternate way to describe the map() function is based on the relationship between the number-lines. Let's use the Fahrenheit and the Celsius scales as an example simplified by using integers instead of floats.

``Fahrenheit scale``<br>
``|32-----50------77--------100----------------150---------------------212|``<br>
``|P1-------------------------------------------------------------------P2|``<br>
``|0--------------25------------------50-------------------------------100|``<br>
``Celcius scale``<br>

Let's use a number count of integers between points P1 and P2. We can agree qualitatively when comparing the number lines that the integer count for the Fahrenheit scale is larger than the Celcius scale. Considering the two points P1 and P2 as anchors, the map() function is then used to either increase or decrease the number of integers on the dependent number-line (y) relative to the independent number-line (x). This is accomplished by the slope-m of the linear equation. When the slope-m is greater than one (1) then the number of integers on the dependent number-line increases.

Let's use the map() function for calibration or for making adjustments on the joystick. To center the joystick using one of the its axis say the x-axis, the MCU readings using Analog-to-Digital Conversion (ADC) let's say digital readings from 0 to 1023, the ideal center is about 512. If the actual center reading of a thumb joystick is 528 instead of the 512. We could encompass the error conditionally for both the x and y axis. This method causes dead-space to occur before any noticeable event. 

By using the map() function, we could otherwise center the error mathematically. The number-line is split into two number-lines where one is from 0 to 528 and the other is from 528 to 1023. To decide which line to use depends on the ADC digital reading. Finally to obtain the desired-reading from an actual-reading using the map() function assuming the actual-reading is greater than 0 and less than 528 inclusively, then use the map() function as the following: 

> desired-reading = map(actual-reading, 0, 528, 0, 512)

Let's discuss what's happening in further detail. The ideal number-line from 0 to 1023 is used to obtain the desired result. While keeping in mind that the points P1 and P2 are used to anchor the number-lines, so what happens when we split the number-line with the actual readings at the point of the erroneous center? A new point is created between the points P1 and P2 lets's say point Pc where Pc contains the ordered pair (528, 512). Now there are four (4) number-lines but only two (2) sets of order pairs used which are conditionally determined based on the ADC reading. Pictorially, the transformations on either side of the erroneous center becomes obvious as shown.

``Actual ADC Readings (x)``<br>
``|0--------------250-----------------|528|-------------750-----------1023|``<br>
``|P1--------------------------------|Pc|-------------------------------P2|``<br>
``|0---------------250--------------|512|-------------750-------------1023|``<br>
``Desired ADC Readings (y)``<br>

The important observation here is that the entire number-line is transformed. The analogy is like shifting a fixed center point of the spring while both ends are also fixed causing one side of the spring to be compressed and the other side to be stretched. 

The question for an astute reader is which of the two of the four number-lines are changing and which side of the two is compressed and which one is stretched. Hint: the number-line for the actual readings do not change. 

What data type (T) ought be used (int or double) for this transformation to work as described. Why? Test, test, test! Unforunately this does not work properly for Arduino's map() function because the mapping from x to f(x) is not one to one. The reason when processing between the two distinct values (x) and f(x) some information is lost.

As to what information is lost, try interchanging the data type (T) between (int and double) using the Fahrenheit and Celsius scales to observe the precision that is obtained between the data types.

Actually number-lines do not change but the processing or the transformation causes the change. As you're trying to wrap this around your head, the transformation itself between two values plays into this illusion. Thus a single value is mapped into another by (x, f(x)).

The map() function although simple in appearance yet with careful study, the map() function is a powerful tool. This method can be expanded to arrays of points such as Least Squares Fitting (x, f(x)) for example and then protracting the experimetntal (x) values onto F(x). Lidar distance readings never give a set of points to form a perfect line nor a perfect curve. Is this apples and oranges? Maybe! Applied Math is the scientist and engineer's most important tool even though the mathematician might disagree.

A final note on using the scientific method to answer basic questions that would improve the performance of the robot. For example, to determine the kinetic friction ADC values for a differential drive mobile robot, experimentation is necessay using either an engineering log or science lab notebook to answer such questions. The written notes prevents repeating redundant investigations on the same emperical research. The investigative results that answers such questions will always be at arms length away.
