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

  class IOGuard {
  public:
    explicit IOGuard(std::basic_ios<char>& s):
      s_(s), width_(s.width()), fill_(s.fill()), prc_(s.precision()), fmt_(s.flags()) {}

    ~IOGuard() {
      s_.width(width_);
      s_.fill(fill_);
      s_.precision(prc_);
      s_.flags()
    }

  private:
    std::basic_ios<char>& s_;
    std::streamsize width_;
    std::streamsize prc_;
    std::basic_ios<char>::fmtflags fmt_;
    char fill_;
  };
}

int main() {
  return 0;
}