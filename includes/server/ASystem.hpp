//
// Created by pashervz on 08/01/18.
//

#ifndef CPP_RTYPE_ASYSTEM_HPP
#define CPP_RTYPE_ASYSTEM_HPP

#include <vector>
#include <memory>
#include "AComponent.hpp"

class ASystem
{
private:
    std::vector<std::unique_ptr<AComponent>>    _components;

public:
    ASystem() = default;
    virtual ~ASystem() = default;

    virtual void        update()
    {
        for (const auto & it :  _components)
            it->update();
    }

    virtual void        draw()
    {
        for (const auto & it : _components)
            it->draw();
    }

    virtual void        addComponent(AComponent component)
    {
        _components.push_back(std::unique_ptr<AComponent>(component));
    }

    virtual void        disable(int Id)
    {
        for (const auto & it : _components) {
            if (it->getId() == Id && it->getStatus() == true) {
                it->setStatus(false);
                break;
            }
        }
    }
};

#endif //CPP_RTYPE_ASYSTEM_HPP
