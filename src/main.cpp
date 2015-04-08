#include "SDL.h"

#include "hello.h"

int main(int argc, char** argv) {
  hello::Hello h = hello::Hello();
  hello::Hello b = hello::Hello("bye");

  int xH = h.act();
  int xB = b.act();

  if (SDL_Init(SDL_INIT_VIDEO) < 0) printf("FAILURE\n");
  else printf("SUCCESS\n");
  SDL_Quit();

  return xH + xB;
}
