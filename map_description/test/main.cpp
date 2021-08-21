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
#include "include/map.hpp"

int main()
{
  // Test
  mcu::Map<double> dM;

  double delta = 0;
  double lastDesired = 0;
  double desired = 0;

  int start = 300;
  int few = 2;

  std::cout << "\n----- SIDE (0 - 528) ----\n";
  for (int i = start; i < (start * few + 1); i += start)
  {
    for (int actual = i; actual < (i + few + 1); actual++)
    {
      if (actual == start * few)
        std::cout << "\n--- SIDE (528 - 1023) ---\n";
      if (i < (start + few + 1))
      {
        // All we need is a few points for testing the first side
        desired = dM.map(actual, 0, 528, 0, 512);
      }
      else if (i > (start + few + 1))
      {
        // Now the other side
        desired = dM.map(actual, 528, 1023, 512, 1023);
      }
      delta = desired - lastDesired;
      if (actual > i)
      {
        std::cout << "Actual |" << (actual - 1) << " - " << actual << "| = 1\n";
        std::cout << "Desired |" << lastDesired << " - " << desired << "| = "
                  << delta << "\n";
      }
      lastDesired = desired;
    }
  }
  return 0;
}
