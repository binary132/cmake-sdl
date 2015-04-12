#include <chrono>
#include <cmath>

#include "SDL.h"

#include "app.h"

using namespace app;

void App::mainLoop()
{
     int i = 0;
     bool finished = false;
     bool leftMouseButtonDown = false;
     int prevX = 0, prevY = 0;
     int currX = 0, currY = 0;
     int dx = 0, dy = 0, d2 = 0;
     float d = 0.0, stepX = 0.0, stepY = 0.0;

     SDL_Event event = SDL_Event{ 0 };

     while (!finished) {
          SDL_UpdateTexture(texture, NULL, pixels, display.w * sizeof(Uint32));

          while (SDL_PollEvent(&event)) {
               switch(event.type) {
               case SDL_QUIT:
                    finished = true;
                    break;
               case SDL_KEYDOWN:
                    switch(event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                         finished = true;
                    }
                    break;
               case SDL_MOUSEBUTTONUP:
                    if (event.button.button == SDL_BUTTON_LEFT)
                         leftMouseButtonDown = false;
                    break;
               case SDL_MOUSEBUTTONDOWN:
                    if (event.button.button == SDL_BUTTON_LEFT) {
                         leftMouseButtonDown = true;
                         prevX = currX = event.button.x, prevY = currY = event.button.y;
                         pixels[currY * display.w + currX] = 0;
                    }
                    break;
               case SDL_MOUSEMOTION:
                    if (leftMouseButtonDown)
                    {
                         currX = event.motion.x, currY = event.motion.y;
                         dx = currX - prevX;
                         dy = currY - prevY;
                         d2 = dx * dx + dy * dy;
                         d = sqrt(d2);
                         stepX = dx / d;
                         stepY = dy / d;
                         for( int i = 0; i * i < d2; i++ ) {
                              pixels[(prevY + (int)(i*stepY)) * display.w + (prevX + (int)((i * stepX)))] = 0;
                         }
                         prevX = currX, prevY = currY;
                    }
                    break;
               }
          }

          SDL_RenderClear(renderer);
          SDL_RenderCopy(renderer, texture, NULL, NULL);
          SDL_RenderPresent(renderer);
     }
}
