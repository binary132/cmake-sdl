#include <string>

namespace hello {
  class Hello {
    Hello(std::string);
    Hello();

    int act();

  private:
    std::string message;

    int printHello();
  };
}
