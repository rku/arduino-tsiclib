
# What is it?

This is a library for the Arduino platform providing a clean interface to
TSIC digital temperature sensors like 206, 305 or similar. It is mostly a
cleanup of Rolf W.'s code available at [1] (which is based on code from
[2]). However, it also comes with useful improvements like not dropping 
precision when returning measured temperatures (which the original code
does).

# How to use it?

Just copy the library to your Arduino libraries folder. See the included
example on how to use the library.

# Note:

When calling readTemperature(), the sensor is turned on. After reading data
has been finished, the sensor is turned off again in order to save power.
The downside of this technique is that it takes some time for the code to
return which slows down the main loop(). An option for reading data
periodically without turning the sensor on and off every time is on my TODO
list.

# Connecting the sensor to your Arduino board

This needs to be written, sorry.

    [1]: http://playground.arduino.cc/Code/Tsic
    [2]: http://www.mikrocontroller.net/topic/82087

