// coordinates.cpp
#include "math.h"
#include <cmath>

float distance(coors a, coors b)  { // distance formula
  return sqrt((b.x-a.x)+(b.y-a.y));
}

float mod(float a, int b) {
  return (a - floor(a/b)*b);
}
  
