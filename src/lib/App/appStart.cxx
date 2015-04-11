#include <chrono>
#include <thread>

#include "SDL.h"

#include "app.h"

using namespace app;

void App::mainLoop()
{
     bool finished = false;
     SDL_Event event = SDL_Event({ 0 });

     std::chrono::system_clock::time_point now, frameEnd;
     std::chrono::microseconds frameTime =
          std::chrono::microseconds((long)(1000000.0d/60.0d));

     while (!finished) {
          now = std::chrono::system_clock::now();
          frameEnd = now + std::chrono::microseconds(frameTime);

          while (SDL_PollEvent(&event)) {
               switch(event.type) {
               case SDL_QUIT:
                    finished = true;
                    break;
               case SDL_KEYDOWN:
                    switch(event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                         finished = true;
                         break;
                    }
               }
          }

          std::this_thread::sleep_until(frameEnd);
     }
}
