#include "hello.h"

int main(int argc, char** argv) {
  hello::Hello* h = new(hello::Hello());
  hello::Hello* b = new(hello::Hello("bye"));

  int xH = h.act();
  int xB = b.act();

  delete(h);
  delete(b);

  return xH + xB;
}
