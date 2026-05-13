#include <iostream>

namespace ivanov {
  struct DataStruct {
    long long key1;
    std::pair<long long, unsigned long long> key2;
    std::string key3;
  };

  struct DelimiterIO {
    char exp;
  };
  struct StringIO {
    std::string& ref;
  };
  struct LongIO {
    long long& ref;
  };
  struct PairIO {
    std::pair<long long, unsigned long long>& ref;
  };


}

int main() {
  return 0;
}