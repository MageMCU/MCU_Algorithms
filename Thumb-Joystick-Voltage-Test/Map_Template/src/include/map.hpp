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

#ifndef MAP_HPP
#define MAP_H
 
// <cstddef>, <utilities>,<functional>, and <type_traits> 
// (which do provide building blocks formore complex templates)
// C++ Tamplates - Complete Guide 2nd Ed. p.29

namespace mcu {

  template<typename T>
  class Map {
  private:
  
  public:
  // Constructor
    Map() {}
  // Implementation
    T map (T const& x, T const& x1, T const& x2, T const& y1, T const& y2)
    {
      // Assume linear functions
      // m = (y2 - y1)/(x2 - x1)
      // (y - y1) = m(x - x1)
      return (y2 -y1) * (x - x1) / (x2 - x1) + y1;
    }
  };
}
#endif
