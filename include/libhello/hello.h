#include <string>

namespace hello {
  class Hello {
    std::string message;

    int printHello();

  public:
    Hello(std::string);
    Hello();

    int act();
  };
}
