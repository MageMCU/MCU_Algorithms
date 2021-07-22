// Typical Map Function
//
// Compiler Flags
// CC = g++
// CXXFLAGS = -std=c++17 -Wall
//
// Learning C++ templates and metaprogramming
// 
// Isuue: How to write template code where the sizeof input 
//        is twice as large as fuction intermediaries.
//        Example: Integer input type where internals uses
//                 a long integer type.
//
//     Specific example after instantiation:
//     int map (int x, long x1, long x2, long y1, long y2)
//     {
//       // Assume linear functionsd
//       // m = (y2 - y1)/(x2 - x1)
//       // (y - y1) = m(x - x1)
//       return (y2 -y1) * (x - x1) / (x2 - x1) + y1;
//     }
//
//     I have seen pre-compiler conditionals that do this...
// 
// GitHub Upload - 20210722 - MIT LICENSE
// by Jesse Carpenter
// 

#include "include/map.hpp"
#include <iostream>

int main()
{
  // Test
  mcu::Map<int> lM;
  mcu::Map<float> dM;
  
  int x = 42;
  int y = lM.map(x, 0, 100, 0, 1000);

  float fX = 2.56;
  int iY = (int)(dM.map(fX, 0.0, 4.95, 0.0, 1023.0));
  
  // control test: output 10 times input (error 10%)
  std::cout << "map(42): " << y  << "\n";
  // voltage 5v Logic -> ADC output (0-1023)
  std::cout << "map(2.56): " << iY << "\n";

  return 0;
}
