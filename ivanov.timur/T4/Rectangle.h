
#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"

class Rectangle : public Shape{
private:
  point_t pos;
  rectangle_t r;

public:
  virtual ~Rectangle() = default;

  Rectangle(const double& x, const double& y, const double& w, const double& h):
    pos(point_t(x, y)), r(rectangle_t(w, h, point_t(x - w/2, y - h/2))) {}

  double getArea() override {
    return r.height*r.width;
  }

  rectangle_t getFrameRect() override {
    return r;
  }

  void move(double delta_x, double delta_y) override {
    pos = point_t(pos.x + delta_x, pos.y + delta_y);
  }

  void move(point_t new_point) override {
    pos = new_point;
  }

  void scale(double k) override {
    r.width *= k;
    r.height *= k;
    pos = point_t(r.pos.x + r.width/2, r.pos.y + r.height/2);
  }

};

#endif
