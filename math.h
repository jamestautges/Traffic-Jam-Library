// coordinates.h
#ifndef MATH_H
#define MATH_H

#include <cmath>

struct coors { // so that we don't have to pass around vector<int> for every coordinate based function
  float x, y;
};

float distance(coors, coors);

float mod(float, int);

#endif
