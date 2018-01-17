//
// Created by pashervz on 13/01/18.
//

#ifndef CPP_RTYPE_GAMESESSION_HPP
#define CPP_RTYPE_GAMESESSION_HPP

#include <functional>
#include <server/Systems/SMovement.hpp>
#include "EntityFactory.hpp"
#include "utils/Event.hpp"
#include "ASystem.hpp"

namespace FF
{
    class GameSession {
    private:
        EntityFactory                                               _factory;
        std::unordered_map<int, std::shared_ptr<AEntity>>           _entities;
        std::unordered_map<std::string, std::shared_ptr<ASystem>>   _systems;
        std::function<void(Event const &)>                          _function;
        int                                                         _entityID = 0;

    public:
        explicit GameSession(std::function<void(Event const &)> const &function) : _function(function)
        {
            _systems.insert(std::make_pair("PlayerMovement", std::shared_ptr<SMovement>(new SMovement)));
            _systems.insert(std::make_pair("NonPlayerMovement", std::shared_ptr<SMovement>(new SMovement)));
        }

        void                startGame();

        template<EEntityType Type>
        void                insert()
        {
            _entities.insert(std::make_pair(_entityID, _factory.generate<Type>()));
            _entities.at(_entityID).get()->setId(_entityID);
            switch (Type)
            {
                case EEntityType::PLAYER:
                    _systems.at("PlayerMovement")->addEntity(_entities.at(_entityID), _entityID);
                    break;
                case EEntityType::BASICMONSTER:
                    _systems.at("NonPlayerMovement")->addEntity(_entities.at(_entityID), _entityID);
                    break;
                case EEntityType::MAP:
                    _systems.at("NonPlayerMovement")->addEntity(_entities.at(_entityID), _entityID);
                    _systems.at("PlayerMovement")->addEntity(_entities.at(_entityID), _entityID);
                    break;
                default:
                    break;
            }
            _entityID++;
        }

        template<typename T>
        T                           *getEntity(int id)
        {
            if (_entities.find(id) == _entities.end())
                std::cout << "erreur dans getEntity" << std::endl;
            return (reinterpret_cast<T *>(_entities.at(id).get()));
        }

        ~GameSession() = default;
    };
}


#endif //CPP_RTYPE_GAMESESSION_HPP
