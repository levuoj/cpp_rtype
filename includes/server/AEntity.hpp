//
// Created by pashervz on 08/01/18.
//

#ifndef CPP_RTYPE_IENTITY_HPP
#define CPP_RTYPE_IENTITY_HPP

#include <memory>
#include <vector>
#include <unordered_map>

#include "server/AComponent.hpp"

class AEntity
{
protected:
    std::string                                                     _name;
    std::unordered_map<std::string, std::shared_ptr<AComponent>>    _components;
public:
    AEntity(std::string const & name) : _name(name) {}
    virtual ~AEntity() = default;

    virtual void        init() = 0;

    void                addComponent(std::shared_ptr<AComponent>);

    void                removeComponent(std::string const &);

    bool                hasComponent(std::string const &) const;

    AComponent          *getComponent(std::string const &) const;

    long                findComponent(std::string const &) const;

    std::string const & getName() const { return _name; }
};

#endif //CPP_RTYPE_IENTITY_HPP
