#ifndef SHAPE_H
#define SHAPE_H
#include "POD.h"

class Shape {
  virtual double getArea();
  virtual rectangle_t getFrameRect();

  virtual void move(const double& delta_x, const double& delta_y);
  virtual void move(const point_t& new_point);

  virtual void scale(const double& k);
  ~Shape()=default;
};

#endif
