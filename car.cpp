// car.cpp
#include "car.h"
#include "coordinates.h"
#include <vector>
#include <iostream>

Car::Car(int dir, coors c, int s) { // initialize with specific parameters
  cdir = 0;
  xy = c;
  streetsize = s;
}

void Car::setcoors(coors c) { // setting the Car's coordinates with a coors datatype
  xy = c;
}

void Car::setcoors(int x, int y) { // just in case we want to pass two ints
  xy.x = x;
  xy.y = y;
}

coors Car::getcoors(void) { // return a coors object with the Car's current coordinates
  coors c;
  c.x = xy.x;
  c.y = xy.y;
  return c;
}

int Car::velocity(void) { // return the Car's current velocity
  return vl;
}

void Car::setvelocity(int v) { // set the Car's velocity to v
  vl = v;
}

void Car::incvelocity(int vi) { // increment the Car's velocity by vi
  vl += vi;
}

void Car::directions(std::vector<int> dirs) { // add directions to the Car's current directions vector
  for(int i=0; i<dirs.size(); i++) {
    turns.push_back(dirs[i]);
  }
  if(cdir == 0) {
    cdir = turns[turns.size()-1];
    turns.pop_back();
  }
}

void Car::update(void) { // move the Car based on it's velocity, coordinates, directions, street size, and speed limit
  if((xy.x%streetsize != 0 || xy.y%streetsize != 0) && ((xy.x%streetsize <= vl && cdir  == 4) || (xy.x%streetsize >= vl && cdir == 2) || (xy.y%streetsize <= vl && cdir == 1) || (xy.y%streetsize >= vl && cdir == 3))) {
    move(vl);
  }
  
  else if(xy.x%streetsize == 0 && xy.y%streetsize == 0) {
    cdir = turns[turns.size()-1];
    turns.pop_back();
    move(vl);
  }

  else if(xy.x%streetsize > 0 && xy.y%streetsize > 0) {
    if(cdir == 1) {
      int i = vl - streetsize - xy.y%streetsize;
      move(streetsize-xy.y%streetsize);
      cdir = turns[turns.size()-1];
      turns.pop_back();
      move(i);
    }
    else if(cdir == 2) {
      int i = vl - streetsize - xy.x%streetsize;
      move(streetsize - xy.x%streetsize);
      cdir = turns[turns.size()-1];
      turns.pop_back();
      move(i);
    }
    else if(cdir == 3) {
      int i = vl - xy.y%streetsize;
      move(xy.y%streetsize);
      cdir = turns[turns.size()-1];
      turns.pop_back();
      move(i);
    }
    else {
      int i = vl - xy.x%streetsize;
      move(xy.x%streetsize);
      cdir = turns[turns.size()-1];
      turns.pop_back();
      move(i);
    }
  }
}

void Car::move(int m) { // move the Car m units based on the current orientation
  if(cdir == 1) {
    xy.y += m;
  }
  else if(cdir == 2) {
    xy.x += m;
  }
  else if(cdir == 3) {
    xy.y -= m;
  }
  else if(cdir == 4) {
    xy.x -= m;
  }
}
