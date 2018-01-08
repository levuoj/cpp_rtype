//
// Created by pashervz on 08/01/18.
//

#ifndef CPP_RTYPE_IENTITY_HPP
#define CPP_RTYPE_IENTITY_HPP

#include <memory>
#include <vector>
#include "AComponent.hpp"

class AEntity
{
private:
    std::vector<std::unique_ptr<AComponent>>    _components;

public:
    AEntity() = default;
    virtual ~AEntity() = default;

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

    void        addComponent(AComponent component)
    {
        _components.push_back(std::unique_ptr<AComponent>(component));
    }

    void        disable(int Id)
    {
        for (const auto & it : _components) {
            if (it->getId() == Id && it->getStatus() == true) {
                it->setStatus(false);
                break;
            }
        }
    }
};

#endif //CPP_RTYPE_IENTITY_HPP
