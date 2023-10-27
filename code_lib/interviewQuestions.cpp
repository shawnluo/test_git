

// zox


/*
Steering Problem
  
A controls engineer has collected test data for a black box steering system to
determine the amount of voltage that needs to be applied to hold the vehicle at a
given steering angle. The data below shows that the voltage (V)
required is a function of the steering angle (a).
  
Test Data:
a = -22,  -11, 0, 10,  20 degrees
V = -1.5, -1,  0, 1.2, 1.8 volts
  
The controls engineer would like to use this data as a feed forward term for the
steering controller. Your job is to write a function to determine
the best estimate for voltage (V) given a steering angle (a). aka. V = f(a).
 
Example output:
For a = 10; V = 1.2
For a = 5; V = 0.6
For a = 15; V = 1.5

This problem uses a unit test framework called Catch. Use the example tests at the
bottom of the file to test voltageEstimate, and feel free to add your own as well.
*/

// Unit testing framework
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

// Standard includes
#include <iostream>
#include <stdint.h>

// y1 = m * x1 + c
// y2 = m * x2 + c
// m = (y1 - y2) / (x1 - x2)

float voltageEstimate(const float a, const float *a_data, float *v_data, size_t size /* TODO */) {
  // TODO

    float ratio;
    // float c = 0;
    for(int i = 0; i < size - 1; i++) {
        if(a >= a_data[i] && a <= a_data[i + 1]) {
            ratio = (v_data[i + 1] - v_data[i]) / (a_data[i + 1] - a_data[i]);
            // c = v_data[i]; 
            break;
        }
    }
    // return a * ratio + c;
    return a * ratio;
}


TEST_CASE( "Steering Problem Test" ) {
  const float a_data[]  =  {-22,  -11, 0, 10,  20}; // x-axis data
  const float v_data[] =   {-1.5, -1,  0, 1.2, 1.8}; // y-axis data
  const int size = 5;
  float a, v_expected, v_test;

  SECTION( "Example 1" ) {
    // input angle
    a = 10.0;
    // expected output voltage
    v_expected = 1.2;
    // call function under test
    v_test = voltageEstimate(a, a_data, v_data, size);
    
    // check that our result is correct (within floating point error)
    REQUIRE(v_expected == Approx(v_test));
  }
  
  SECTION( "Example 2" ) {
    // input angle
    a = 15.0;
    // expected output voltage
    v_expected = 1.5;
    // call function under test
    v_test = voltageEstimate(a, a_data, v_data, size);
    
    // check that our result is correct (within floating point error)
    REQUIRE(v_expected == Approx(v_test));
  }
  
  // TODO: Add any new test sections here
}










S
Convert Temperature Sensor Data



Shawn Luo


Convert Temperature Sensor Data
Description
We have a temperature sensor connected to an MCU via an I2C bus. The temperature sensor provides data in one of two measurement modes - standard mode or extended mode. In standard mode, the sensor can measure temperature in the range from 0°C to 127°C, and in the extended mode, it can measure temperature in the range from -64°C to 191°C.

In any mode, the MCU receives 24-bits of data.  A description of the data is given below:

 

 

 

 

 

 

 



 

 

 

 

 

 

The high byte, bits 15 to 8, contains the integer portion of the temperature in °C, and the low byte, bits 7 to 0, contains the decimal fraction of the temperature in °C.

In standard mode, temperatures lower than 0°C are reported as 0°C by the sensor; similarly, temperatures higher than 127°C are reported as 127°C. In extended mode, the sensor reports temperatures from -64°C to 191°C.

 

 



 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 



 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

Function Description

The goal of this question is to populate the function convert_to_temp. This function takes in one argument input_val and returns the converted temperature value in degrees centigrade.

 

Constraints

The input decimal value will be within the conversion range of the sensor.
 

Input Format For Custom Testing
Sample Case 0
Sample Case 1
C
119202122232425262728333435363738394041424344454647484950515253545556575859606162636465666768697071727374293031327576
        res = input_val >> 8;
        res &= (~((1 << 16) - 1));
        FracPart = calFract(input_val);
    } else {
        res = input_val >> 8;
        res &= (~((1 << 15) - 1));
        uint32_t low = (1 << 8) - 1;
        uint32_t high = (1 << 16) - 1;
        uint32_t mask = high - low;
        int intPart = (input_val & mask) >> 15;

Line: 65 Col: 26

Run Code

Run Tests

Input / Output

Test Cases


Input
29552
Run Code to see your output here.

double __y, hint