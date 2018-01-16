//
// Created by pashervz on 08/01/18.
//

#ifndef CPP_RTYPE_ICOMPONENT_HPP
#define CPP_RTYPE_ICOMPONENT_HPP

#include <memory>

namespace FF
{
    class AComponent
    {
    protected:
        std::string _name;
    public:
        explicit AComponent(std::string const &name) : _name(name) {}
        virtual ~AComponent() = default;

        std::string const &getName() const { return _name; }

        virtual void init() = 0;
    };
}
#endif //CPP_RTYPE_ICOMPONENT_HPP
