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
                               SDL_WINDOW_ALLOW_HIGHDPI);// | SDL_WINDOW_OPENGL);
     if (window == NULL) {
          ss << "SDL_CreateWindow failed: " << SDL_GetError();

          throw error::InitError(ss.str());
     }

     renderer = SDL_CreateRenderer(window, -1, 0);
     if (renderer == NULL) {
          ss << "SDL_CreateRenderer failed: " << SDL_GetError();

          throw error::InitError(ss.str());
     }

     texture = SDL_CreateTexture(renderer,
        SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, 640, 480);
     if (texture == NULL) {
          ss << "SDL_CreateTexture failed: " << SDL_GetError();

          throw error::InitError(ss.str());
     }

     pixels = new Uint32[640 * 480];
     memset(pixels, 255, 640 * 480 * sizeof(Uint32));

     SDL_ShowWindow(window);
}
