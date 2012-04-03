// coordinates.h
#ifndef COORS_H
#define COORS_H

#include <cmath>

struct coors { // so that we don't have to pass around vector<int> for every coordinate based function
  int x, y;
};

int distance(coors a, coors b);

#endif
