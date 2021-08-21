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
  // Test
  mcu::Map<double> dM;
  mcu::Map<long>lM;

  // Precision
  double delta = 0;
  double lastDesired = 0;
  double desired = 0;

  // Integers
  int iDesired = 0;
  long lMapped = 0;

  int start = 300;
  int addPoints = 2;
  int two = 2;

  std::cout << "\n----- SIDE (0 - 528) ----\n";
  for (int i = start; i < (start * two + 1); i += start)
  {
    for (int actual = i; actual < (i + addPoints + 1); actual++)
    {
      if (actual == start * two)
        std::cout << "\n--- SIDE (528 - 1023) ---\n";
      if (i < (start + addPoints + 1))
      {
        // All we need is to add points for testing the first side
        desired = dM.map(actual, 0, 528, 0, 512);
        lMapped = lM.map(actual, 0, 528, 0, 512);
      }
      else if (i > (start + addPoints + 1))
      {
        // Now the other side
        desired = dM.map(actual, 528, 1023, 512, 1023);
        lMapped = lM.map(actual, 528, 1023, 512, 1023);
      }
      iDesired = (int) desired;
      delta = desired - lastDesired;
      if (actual > i)
      {
        std::cout << "Actual |" << (actual - 1) << " - " << actual << "| = 1\n";
        std::cout << "Desired |" << lastDesired << " - " << desired << "| = "
                  << delta << " iDesired: " << iDesired << " lMapped: " 
                  << lMapped <<"\n";
      }
      lastDesired = desired;
    }
  }
  return 0;
}
