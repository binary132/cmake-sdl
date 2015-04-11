#include <iostream>
#include <string>

#include "SDL.h"

#include "app.h"

using namespace app;

App::App(std::string titleIn) :
     title(titleIn) {}

App::~App()
{
     delete[] pixels;

     SDL_DestroyTexture(texture);
     SDL_DestroyRenderer(renderer);
     SDL_DestroyWindow(window);

     SDL_Quit();
}
