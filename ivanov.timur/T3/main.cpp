#include <iostream>
#include "Polygon.h"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Bad input error\n";
    return 1;
  }

  std::pmr::vector<Polygon> data;

  return 0;
}