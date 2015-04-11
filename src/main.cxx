#include <iostream>

#include "app.h"
#include "initError.h"

int main(int argc, char** argv)
{
     app::App a;

     try {
          a.init();
     }

     catch (const error::InitError& e) {
          std::cerr << "Error while initializing App: "
                    << e.what() << std::endl;
          return 1;
     }

     // Fire off the main thread for a
     a.mainLoop();

     std::cout << "Finished";

     return 0;
}
