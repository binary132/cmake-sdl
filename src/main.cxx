#include <iostream>

#include "app.h"
#include "initError.h"

int main(int argc, char** argv)
{
     try {
          app::App a;;
     }

     catch (const error::InitError& e) {
          std::cerr << "Error while initializing SDL: "
                    << e.what() << std::endl;
     }

     return 0;
}
