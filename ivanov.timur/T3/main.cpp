#include <iostream>
#include "Polygon.h"
#include "IO.h"
#include <sstream>

using namespace ivanov;
int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Bad input error\n";
    return 1;
  }

  std::vector<Polygon> data;
  std::string line;

  while (std::getline(std::cin, line)) {
    std::istringstream iss(line);
    Polygon tmp;
    if (iss >> tmp) {
      iss >> std::ws;
      if (iss.eof()) {
        data.push_back(std::move(tmp));
      }
    }
  }

  return 0;
}