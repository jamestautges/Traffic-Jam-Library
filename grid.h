// grid.h
#ifndef GRID_H
#define GRID_H

#include <vector>
#include "coordinates.h"
#include "car.h"

class Grid {
 private:
  int streetsize;
  coors dimensions;
  int speedlimit;
  std::vector<Car> cars;
 public:
  Grid(coors, int, int);
  Grid();
  void addcar(int, int);
  void move(void);
  int carssize(void);
  coors corrs(int);
  coors size(void);
  int street(void);
  Car* getcar(int);
  void directions(int, std::vector<int>);
};

#endif
