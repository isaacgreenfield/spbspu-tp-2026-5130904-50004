#ifndef SHAPE_H
#define SHAPE_H
#include "POD.h"

class Shape {
  virtual double getArea();
  virtual rectangle_t getFrameRect();

  virtual void move(double delta_x, double delta_y);
  virtual void move(point_t new_point);

  virtual void scale(double k);
  ~Shape()=default;
};

#endif
