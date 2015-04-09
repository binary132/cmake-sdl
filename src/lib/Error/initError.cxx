#include <string>

#include "initError.h"
#include "SDL.h"

using namespace error;

InitError::InitError():
     exception(), msg(SDL_GetError()) {}

InitError::InitError(const std::string& m):
     exception(), msg(m) {}

InitError::~InitError() throw() {}

const char* InitError::what() const throw()
{
     return msg.c_str();
}
