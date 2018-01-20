//
// Created by pashervz on 20/01/18.
//

#include "utils/Error.hpp"

Error::Error(std::string const& errorMessage) throw() : _errorMessage(errorMessage) {}

Error::~Error() throw() {}

Error::Error(Error const & other) :  _errorMessage(other._errorMessage) {}

Error&                  Error::operator=(Error const & other)
{
    if (this != &other)
        this->_errorMessage = other._errorMessage;
    return (*this);
}

const char              *Error::what() const throw()
{
    return (this->_errorMessage.c_str());
}