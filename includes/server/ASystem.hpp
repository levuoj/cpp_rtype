//
// Created by pashervz on 08/01/18.
//

#ifndef CPP_RTYPE_ASYSTEM_HPP
#define CPP_RTYPE_ASYSTEM_HPP

#include <unordered_map>
#include <memory>
#include "server/AEntity.hpp"
#include "AMap.hpp"

namespace FF {
    class ASystem {
    protected:
        std::string                                               _name;
        std::unordered_map<int, std::shared_ptr<AEntity>>         _entities;

    public:
        ASystem(std::string const &name) : _name(name) {}
        virtual ~ASystem() = default;

        void addEntity(std::shared_ptr<AEntity>, int);
        void removeEntity(int);
        bool hasEntity(int) const;

        FF::AMap                *getMap()
        {
            for (const auto & it : _entities)
            {
                if (it.second->getType() == EEntityType::MAP)
                    return (reinterpret_cast<AMap *>(it.second.get()));
            }
            return nullptr;
        }

        virtual void execute() = 0;
    };
}

#endif //CPP_RTYPE_ASYSTEM_HPP
