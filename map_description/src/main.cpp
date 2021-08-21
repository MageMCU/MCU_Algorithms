// Typical Map Function
//
// Compiler Flags
// CC = g++
// CXXFLAGS = -std=c++11 -Wall
//
// Learning C++ templates and metaprogramming
// 
// GitHub Upload - 20210722 - MIT LICENSE
// by Jesse Carpenter
// 

#include <iostream>
#include "../include/map.hpp"

int main()
{
  // Test Points - Freezing(32, 0), Boiling(212, 100)
  mcu::Map<double> dM;
  
  double fahrenheit = (double) 77;
  double celsius = dM.map(fahrenheit, 
                             (double)32, 
                             (double)212, 
                             (double)0, 
                             (double)100);
  std::cout << "celsius: " << celsius << "\n"; 

  return 0;
}
