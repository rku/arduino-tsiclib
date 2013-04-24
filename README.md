# A library for reading TSIC digital temperature sensors like 206/305 using the Arduino platform

This is a library for the Arduino platform for reading data from digital
temperature sensors TSIC 206, 305 or similar. It is mostly a cleanup of
Rolf W.'s code available at [1] (which is based on code from [2]).

However, it also comes with some useful improvements like providing more
precise sensor data and a cleaner interface.

# How to use it

Just copy the library to your Arduino libraries folder. See the included
example on how to use the library.

When calling readTemperature(), the sensor is turned on. After reading data
has been finished, the sensor is turned off again in order to save power.
The downside of this technique is that it takes some time for the code to
return which slows down the main loop(). An option for reading data
periodically without turning the sensor on and off every time is on my TODO
list.

