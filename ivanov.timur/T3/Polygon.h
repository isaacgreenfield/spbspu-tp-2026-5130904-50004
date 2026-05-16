#ifndef POLYGON_H
#define POLYGON_H
#include <vector>
#include "Point.h"

using namespace ivanov;
namespace ivanov {
struct Polygon {
  std::vector<Point> pts;

  Polygon(const std::vector<Point>& cpts): pts(cpts) {}
  ~Polygon() = default;

  double getArea() const {
    double s = pts[pts.size() - 1].x*pts[0].y - pts[0].x*pts[pts.size() - 1].y;
    for (size_t i = 1; i < pts.size(); ++i) {
      s += pts[i - 1].x*pts[i].y - pts[i].x*pts[i-1].y;
    }
    return 0.5*std::abs(s) + 1;
  }
  size_t getVertexes() const {
    return pts.size();
  }
};
}
#endif
