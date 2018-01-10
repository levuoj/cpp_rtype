//
// Created by pashervz on 08/01/18.
//

#ifndef CPP_RTYPE_ICOMPONENT_HPP
#define CPP_RTYPE_ICOMPONENT_HPP

#include <memory>

class AComponent
{
protected:
    std::string                         _name;

public:
    explicit AComponent(std::string const & name) : _name(name) {}
    virtual ~AComponent() = default;

    virtual    void         init() = 0;
    std::string const &     getId() const { return _name; }
};

#endif //CPP_RTYPE_ICOMPONENT_HPP
