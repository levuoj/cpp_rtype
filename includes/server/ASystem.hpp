//
// Created by pashervz on 08/01/18.
//

#ifndef CPP_RTYPE_ASYSTEM_HPP
#define CPP_RTYPE_ASYSTEM_HPP

#include <unordered_map>
#include <memory>
#include "server/AEntity.hpp"

class ASystem
{
private:
    std::string                                                 _name;
    std::unordered_map<std::string, std::unique_ptr<AEntity>>   _entities;

public:
    ASystem(std::string const & name) : _name(name) {}
    virtual ~ASystem() = default;

    virtual void        execute() = 0;

    void        addEntity(AEntity&);

    void        removeEntity(std::string const &);

    bool        hasEntity(std::string const &) const;

    AEntity     *getEntity(std::string const &) const;
};

#endif //CPP_RTYPE_ASYSTEM_HPP
