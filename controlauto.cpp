// controlauto.cpp
#include <vector>
#include <iostream>
#include "car.h"
#include "grid.h"
#include "coordinates.h"

int main() {
  Grid::Grid g; // make the grid
  g.addcar(100, 5); // add a car
  std::vector<int> d;
  for(int i=0; i<20; i++) {
    d.push_back(4);
    d.push_back(3);
  }
  g.directions(0, d);
  Car* car = g.getcar(0);
  for(int i=0; i<40; i++) {
    g.move(); // update all the cars
    std::cout << car->getcoors().x << ", "<< car->getcoors().y << std::endl;
  }
  coors a;
  a.x = 1;
  a.y = 1;
  Car::Car c (1,a,10);
  return 0;
}
