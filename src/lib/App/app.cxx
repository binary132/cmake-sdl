#include <iostream>
#include <string>

#include "SDL.h"

#include "app.h"

using namespace app;

App::App(std::string titleIn) :
     title(titleIn) {}

App::~App()
{
     SDL_DestroyWindow(window);
     SDL_Quit();
}
