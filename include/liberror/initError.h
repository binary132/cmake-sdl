#ifndef INIT_ERROR_H
#define INIT_ERROR_H

#include <exception>
#include <string>

namespace error {
     class InitError: public std::exception {
     private:
          std::string msg;
     public:
          InitError();
          InitError(const std::string&);
          virtual ~InitError() throw();
          virtual const char* what() const throw();
     };
}

#endif
