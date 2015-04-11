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

     if(int numDisp = SDL_GetNumVideoDisplays() < 1) {
          ss << "SDL_GetNumVideoDisplays returned " << numDisp;

          throw error::InitError(ss.str());
     }

     initOk = SDL_GetCurrentDisplayMode(0, &display);
     if (initOk != 0) {
          ss << "SDL_GetCurrentDisplayMode failed with code " << initOk
             << ": " << SDL_GetError();

          throw error::InitError(ss.str());
     }

     window = SDL_CreateWindow(title.c_str(),
                               SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                               display.w, display.h,
                               SDL_WINDOW_FULLSCREEN |
                               SDL_WINDOW_ALLOW_HIGHDPI |
                               SDL_WINDOW_OPENGL |
                               SDL_WINDOW_INPUT_GRABBED);
     if (window == NULL) {
          ss << "SDL_CreateWindow failed: " << SDL_GetError();

          throw error::InitError(ss.str());
     }

     renderer = SDL_CreateRenderer(window, -1,
                                   SDL_RENDERER_ACCELERATED |
                                   SDL_RENDERER_PRESENTVSYNC);
     if (renderer == NULL) {
          ss << "SDL_CreateRenderer failed: " << SDL_GetError();

          throw error::InitError(ss.str());
     }

     texture = SDL_CreateTexture(
          renderer,
          SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC,
          display.w, display.h);
     if (texture == NULL) {
          ss << "SDL_CreateTexture failed: " << SDL_GetError();

          throw error::InitError(ss.str());
     }

     pixels = new Uint32[display.w * display.h];
     memset(pixels, 255, display.w * display.h * sizeof(Uint32));

     SDL_ShowWindow(window);
}
