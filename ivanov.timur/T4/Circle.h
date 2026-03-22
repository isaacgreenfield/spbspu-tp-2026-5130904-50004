#ifndef CIRCLE_H
#define CIRCLE_H
#include <cmath>
#include "Shape.h"
#include "POD.h"

class Circle : public Shape{
private:
  point_t centre;
  double radius;

public:
  Circle(const double& x, const double& y, const double& r):
    centre(point_t(x, y)), radius(r) {}
  virtual ~Circle() = default;

  double getArea() override {
    return M_PI*radius*radius;
  }
  rectangle_t getFrameRect() override {
    return rectangle_t(2*radius, 2*radius, point_t(centre.x - radius, centre.y - radius));
  }

  void move(const double& delta_x, const double& delta_y) override {
    centre.x += delta_x;
    centre.y += delta_y;
  }
  void move(const point_t& new_point) override {
    move(new_point.x - centre.x, new_point.y - centre.y);
  }

  void scale(const double& k) override {
    double nr = radius*k;
    centre = point_t(centre.x + (nr - radius)/sqrt(2), centre.y + (nr - radius)/sqrt(2));
    radius = nr;
  }
};

#endif
