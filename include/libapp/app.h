#ifndef APP_H
#define APP_H

#include "initError.h"

namespace app {
     class App {
     public:
          App() throw (error::InitError);
          ~App();
     };
}

#endif
