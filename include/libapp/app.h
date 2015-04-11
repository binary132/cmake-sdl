#ifndef APP_H
#define APP_H

#include "SDL.h"

#include "initError.h"

namespace app {
     class App {
     public:
          App(std::string title = "SDL-App");
          ~App();

          void init() throw (error::InitError);

          void mainLoop();

     private:
          std::string title;

          SDL_DisplayMode display;
          SDL_Window* window;
          SDL_Renderer* renderer;
          SDL_Texture* texture;
          Uint32* pixels;
     };
}

#endif
