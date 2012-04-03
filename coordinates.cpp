// coordinates.cpp
#include "coordinates.h"

int distance(coors a, coors b)  { // distance formula
  return sqrt((b.x-a.x)+(b.y-a.y));
}
