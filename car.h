// car.h
#ifndef CAR_H
#define CAR_H

#include <vector>
#include "coordinates.h"

class Car {
  coors xy;
  int vl;
  std::vector<int> turns;
  int cdir;
  int streetsize;
public:
  Car(int dir, coors c, int s);
  void setcoors(coors c);
  void setcoors(int x, int y);
  void setvelocity(int v);
  void incvelocity(int vi);
  coors getcoors(void);
  int velocity(void);
  void directions(std::vector<int> dirs);
  void update(void);
  void move(int m);
};

#endif
  
