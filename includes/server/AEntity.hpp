//
// Created by pashervz on 08/01/18.
//

#pragma once

#include <memory>
#include <vector>
#include <unordered_map>

#include "server/AComponent.hpp"
#include "EEntityType.hpp"

namespace FF
{
    class AEntity
    {
    protected:
        int                                                          _id;
        EEntityType                                                  _type;
        std::unordered_map<std::string, std::shared_ptr<AComponent>> _components;

    public:
        AEntity(EEntityType type) : _type(type) {}
        virtual ~AEntity() = default;

        void addComponent(std::shared_ptr<AComponent>);
        void removeComponent(std::string const &);
        bool hasComponent(std::string const &) const;
        AComponent *getComponent(std::string const &) const;
        long findComponent(std::string const &) const;
        EEntityType getType() const { return _type; }
        int         getId() const { return _id; }
        void        setId(int id) { _id = id; }
        virtual void init() = 0;
    };
}