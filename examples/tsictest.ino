
/**
 *  test ard-tsiclib by reading the sensor every five seconds and printing the
 *  measured data to a serial port
 */

#include "TSIC.h"       // include the library

#define TSICPIN     12  // connected to the sensor's signal pin
#define TSICVCCPIN  11  // connected to the sensor's vcc pin

// declare a library object representing the sensor
TSIC tsic(TSICVCCPIN, TSICPIN);

void setup() {
    Serial.begin(9600);
}

void loop() {

    // read the temperature from the sensor
    float temperature = tsic.readTemperature();;

    // check if there was an error and inform the user 
    if(isnan(temperature)) {
        Serial.println("There was an error reading the sensor!");
    } else {
        // seems ok - print the measured temperature
        Serial.print("Temperature: ");
        Serial.print(temperature);
        Serial.println(" °C");
    }

    delay(5000);    // wait 5 seconds
}

