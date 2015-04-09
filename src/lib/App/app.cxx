#include <iostream>
#include <system_error>

#include "SDL.h"

#include "app.h"
#include "initError.h"

using namespace app;

App::App() throw(error::InitError)
{
     int initOk = SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);
     if (initOk != 0) {
          throw error::InitError();
     }
}

App::~App()
{
     SDL_Quit();
}
