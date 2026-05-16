#include <iostream>
#include "Polygon.h"
#include "fun.h"
#include "IO.h"
#include <fstream>
#include <sstream>

using namespace ivanov;
int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Bad input error\n";
    return 1;
  }

  std::ifstream file(argv[1]);
  if (!file) {
    std::cerr << "Bad input error\n";
    return 1;
  }

  std::vector<Polygon> data;
  std::string line;

  while (std::getline(file, line)) {
    std::istringstream iss(line);
    Polygon tmp;
    if (iss >> tmp) {
      iss >> std::ws;
      if (iss.eof()) {
        data.push_back(std::move(tmp));
      }
    }
  }

  while (std::getline(std::cin, line)) {
    if (line.empty()) continue;
    std::istringstream iss(line);
    std::string cmd;
    iss >> cmd;
    if (cmd == "AREA") {
      std::string param;
      iss >> param;
      if (param == "EVEN" || param == "ODD" || param == "MEAN") {
        std::cout << area(data, param) << "\n";
      } else {
        size_t n;
        std::istringstream p(param);
        if (p >> n && p.eof()) {
          std::cout << area(data, n) << "\n";
        }
      }
    }
    else if (cmd == "MAX") {
      std::string param;
      iss >> param;
      std::cout << max(data, param) << "\n";
    }
    else if (cmd == "MIN") {
      std::string param;
      iss >> param;
      std::cout << min(data, param) << "\n";
    }
    else if (cmd == "COUNT") {
      std::string param;
      iss >> param;
      if (param == "EVEN" || param == "ODD") {
        std::cout << count(data, param) << "\n";
      } else {
        size_t n;
        std::istringstream p(param);
        if (p >> n && p.eof()) {
          std::cout << count(data, n) << "\n";
        }
      }
    }
    else if (cmd == "SAME") {
      Polygon target;
      iss >> target;
      std::cout << same(data, target) << "\n";
    }
    else if (cmd == "RIGHTSHAPES") {
      std::cout << rightshapes(data) << "\n";
    }
  }

  return 0;
}
