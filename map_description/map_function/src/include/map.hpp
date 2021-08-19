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

#ifndef CLASS_MAP_HPP
#define CLASS_MAP_HPP

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
