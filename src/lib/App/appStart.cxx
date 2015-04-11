#include <chrono>
#include <thread>

#include "SDL.h"

#include "app.h"

using namespace app;

void App::mainLoop()
{
     int i = 0;
     bool finished = false;
     bool leftMouseButtonDown = false;

     SDL_Event event = SDL_Event({ 0 });

     std::chrono::system_clock::time_point now, frameEnd;
     std::chrono::microseconds frameTime =
          std::chrono::microseconds((long)(1000000.0/60.0));

     while (!finished) {
          now = std::chrono::system_clock::now();
          frameEnd = now + std::chrono::microseconds(frameTime);

          SDL_UpdateTexture(texture, NULL, pixels, 640 * sizeof(Uint32));

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
               case SDL_MOUSEBUTTONUP:
                    if (event.button.button == SDL_BUTTON_LEFT)
                         leftMouseButtonDown = false;
                    break;
               case SDL_MOUSEBUTTONDOWN:
                    if (event.button.button == SDL_BUTTON_LEFT)
                         leftMouseButtonDown = true;
               case SDL_MOUSEMOTION:
                    if (leftMouseButtonDown)
                    {
                         int mouseX = event.motion.x;
                         int mouseY = event.motion.y;
                         pixels[mouseY * 640 + mouseX] = 0;
                    }
                    break;
               }
          }

          SDL_RenderClear(renderer);
          SDL_RenderCopy(renderer, texture, NULL, NULL);
          SDL_RenderPresent(renderer);

          std::this_thread::sleep_until(frameEnd);
     }
}
