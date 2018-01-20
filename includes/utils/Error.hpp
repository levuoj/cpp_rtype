//
// Created by pashervz on 20/01/18.
//

#ifndef CPP_RTYPE_ERROR_HPP
#define CPP_RTYPE_ERROR_HPP

#include <exception>
#include <string>

class Error             : public std::exception {
    std::string _errorMessage;
public:
    Error(std::string const &errorMessage) throw();

    Error(Error const &other);

    virtual ~Error() throw();

    Error &operator=(Error const &);

    virtual const char *what() const throw();
};


#endif //CPP_RTYPE_ERROR_HPP
