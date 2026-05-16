#ifndef IO_H
#define IO_H
#include "Polygon.h"
#include <ios>

using namespace ivanov;
namespace ivanov {

struct DelimiterIO {
  char exp;
};

struct PointIO {
  Point& ref;
};

class IOGuard {
public:
  explicit IOGuard(std::basic_ios<char>& s)
      : s_(s), width_(s.width()), prc_(s.precision()),
        fmt_(s.flags()), fill_(s.fill()) {}

  ~IOGuard() {
    s_.width(width_);
    s_.fill(fill_);
    s_.precision(prc_);
    s_.flags(fmt_);
  }

private:
  std::basic_ios<char>& s_;
  std::streamsize width_;
  std::streamsize prc_;
  std::basic_ios<char>::fmtflags fmt_;
  char fill_;
};



}

#endif
