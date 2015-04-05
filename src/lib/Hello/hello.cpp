#include <iostream>
#include "hello.h"

using namespace hello;

Hello::Hello(std::string m) {
  message = m;
}

Hello::Hello() : Hello("Hello world!"){}

int Hello::printHello() {
  std::cout << message << std::endl;
  return 0;
}

int Hello::act() {
  return printHello();
}
