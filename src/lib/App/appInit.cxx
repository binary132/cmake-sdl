#include <sstream>

#include "SDL.h"

#include "app.h"
#include "initError.h"

using namespace app;

void App::init() throw (error::InitError)
{
     std::stringstream ss;

     int initOk = SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);

     if (initOk != 0) {
          ss << "SDL_Init failed with code " << initOk
             << ": " << SDL_GetError();

          throw error::InitError(ss.str());
     }

     if (SDL_GetNumVideoDrivers() > 0) {
          if (int v = SDL_VideoInit(NULL) != 0) {
               ss << "SDL_VideoInit failed with code " << v
                  << ": " << SDL_GetError();

               throw error::InitError(ss.str());
          }
     } else {
          ss << "0 drivers found";

          throw error::InitError(ss.str());
     }

     window = SDL_CreateWindow(title.c_str(),
                               SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                               640, 480,
                               SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_OPENGL);
     if (window == NULL) {
          ss << "SDL_CreateWindow failed: " << SDL_GetError();

          throw error::InitError(ss.str());
     }

     SDL_ShowWindow(window);
}
