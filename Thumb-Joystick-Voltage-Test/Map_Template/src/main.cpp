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
//     I have seen pre-compiler conditionals that do this...,
//     but until then, I just use a larger type to ensure
//     maximum values come out correctly. jc
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
  // x1-x2 = 0-100
  // y1-y2 = (0-1000)
  int y = lM.map(x, 0, 100, 0, 1000);

  float fX = 2.56;
  // x1-x2 = 0-4.95
  // y1-y2 = 0-1023
  int iY = (int)(dM.map(fX, 0.0, 4.95, 0.0, 1023.0));
  
  // TYPE INTEGERS
  std::cout << "INT16_MAX Value: " << INT16_MAX << std::endl;
  std::cout << "int16_t Size: " << sizeof(int16_t) << std::endl;
  std::cout << "INT32_MAX Value: " << INT32_MAX << std::endl;
  std::cout << "int32_t Size: " << sizeof(int32_t) << std::endl;
  std::cout << "INT64_MAX Value: " << INT64_MAX << std::endl;
  std::cout << "int64_t Size: " << sizeof(int64_t) << std::endl;
  std::cout << "intmax_t Value: " << "?" << std::endl;

  // Do Not Trust int type
  std::cout << "Iintnt Size: " << sizeof(int) << std::endl;
  std::cout << "int test -1023 * 1023: " << (int)((int) -1023 * (int) 1023) << std::endl;
  std::cout << "int16_t test -1023 * 1023: " << (int16_t)((int16_t) -1023 * (int16_t) 1023) << " FAILED..." << std::endl;
  std::cout << "int32_t test -1023 * 1023: " << (int32_t)((int32_t) -1023 * (int32_t) 1023) << std::endl;
  std::cout << std::endl;

  // Map Examples
  std::cout << "map(42): " << y  << "\n";
  std::cout << "map(2.56): " << iY << "\n";
  // y-intervals between 0.01 x-increments....
  fX = 0.0;
  iY = (int)(dM.map(fX, 0.0, 5.01, 0.0, 1023.0));
  std::cout << "map(0.0): " << iY << "\n";
  fX = 0.01;
  iY = (int)(dM.map(fX, 0.0, 5.01, 0.0, 1023.0));
  std::cout << "map(0.01): " << iY << "\n";
  fX = 5.00;
  iY = (int)(dM.map(fX, 0.0, 5.01, 0.0, 1023.0));
  std::cout << "map(5.00): " << iY << "\n";
  fX = 5.01;
  iY = (int)(dM.map(fX, 0.0, 5.01, 0.0, 1023.0));
  std::cout << "map(5.01): " << iY << "\n"; 

  return 0;
}
