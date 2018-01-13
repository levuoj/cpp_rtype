//
// Created by pashervz on 09/01/18.
//

#include <server/AEntity.hpp>

void                AEntity::addComponent(std::shared_ptr<AComponent> componentPtr)
{
    _components.insert(std::make_pair(componentPtr->getName(), componentPtr));
}

void                AEntity::removeComponent(std::string const & componentName)
{
    if (_components.find(componentName) != _components.end())
        _components.erase(_components.find((componentName)));
}

bool                AEntity::hasComponent(std::string const &componentName) const
{
    return (_components.find(componentName) != _components.end());
}

AComponent         *AEntity::getComponent(std::string const & componentName) const
{
    auto it = _components.find(componentName);

    if (it != _components.end())
        return (it->second.get());
    return nullptr;
}

long               AEntity::findComponent(std::string const & componentName) const
{
    if (!this->hasComponent(componentName))
        return (-1);
    return (std::distance(this->_components.begin(), this->_components.find(componentName)));
}