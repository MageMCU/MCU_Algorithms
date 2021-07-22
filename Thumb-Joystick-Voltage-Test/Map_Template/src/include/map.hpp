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
// GitHub Upload - 20210722
// by Jesse Carpenter
// 

#ifndef MAP_HPP
#define MAP_HPP

namespace mcu {

  template<typename T>
  class Map {
  private:
  
  public:
  // Constructor
    Map() {}
  // Implementation
    T map (T x, T x1, T x2, T y1, T y2)
    {
      // Assume linear functionsd
      // m = (y2 - y1)/(x2 - x1)
      // (y - y1) = m(x - x1)
      return (y2 -y1) * (x - x1) / (x2 - x1) + y1;
    }
  };
}
#endif
