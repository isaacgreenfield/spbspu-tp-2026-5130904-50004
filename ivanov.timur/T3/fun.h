#ifndef FUN_H
#define FUN_H
#include "Polygon.h"
#include "IO.h"
#include <numeric>
#include <functional>
using namespace std::placeholders;

inline double addIfParity(double sum, const Polygon& p, bool isEven) {
  return sum + (p.getVertexes() % 2 == isEven ? p.getArea() : 0.0);
}

inline double addIfVertexCount(double sum, const Polygon& p, size_t target) {
  return sum + (p.getVertexes() == target ? p.getArea() : 0.0);
}

namespace ivanov{

inline double area(const std::vector<Polygon>& fts, bool isEven) {
  auto accumulator = std::bind(addIfParity, _1, _2, isEven);
  return std::accumulate(fts.begin(), fts.end(), 0.0, accumulator);
}

inline double area(const std::vector<Polygon>& fts, std::string mean) {
  auto accumulator = std::bind(std::plus<double>(), _1,
                                 std::bind(&Polygon::getArea, _2));
  double sum = std::accumulate(fts.begin(), fts.end(), 0.0, accumulator);
  return fts.empty() ? 0.0 : sum / fts.size();
}

inline double area(const std::vector<Polygon>& fts, size_t vertexes_amn) {
  auto accumulator = std::bind(addIfVertexCount, _1, _2, vertexes_amn);
  return std::accumulate(fts.begin(), fts.end(), 0.0, accumulator);
}



}

#endif
