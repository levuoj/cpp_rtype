//
// Created by pashervz on 08/01/18.
//

#pragma once

#include <memory>
#include <vector>
#include <unordered_map>

#include "server/AComponent.hpp"

namespace FF
{
    class AEntity
    {
    protected:
        std::string _name;
        std::unordered_map<std::string, std::shared_ptr<AComponent>> _components;
    public:
        AEntity(std::string const &name) : _name(name) {}
        virtual ~AEntity() = default;

        void addComponent(std::shared_ptr<AComponent>);
        void removeComponent(std::string const &);
        bool hasComponent(std::string const &) const;
        AComponent *getComponent(std::string const &) const;
        long findComponent(std::string const &) const;
        std::string const &getName() const { return _name; }

        virtual void init() = 0;
    };
}