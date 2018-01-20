//
// Created by pashervz on 13/01/18.
//

#ifndef CPP_RTYPE_GAMESESSION_HPP
#define CPP_RTYPE_GAMESESSION_HPP

#include <functional>
#include <queue>
#include <server/Systems/SMovement.hpp>
#include <server/Systems/SShoot.hpp>
#include "EntityFactory.hpp"
#include "utils/Event.hpp"
#include "ASystem.hpp"
#include <server/Systems/SMovement.hpp>
#include <utils/EGameState.hpp>

namespace FF
{
    class GameSession {
    private:
        EntityFactory                                               _factory;
        std::unordered_map<int, std::shared_ptr<AEntity>>           _entities;
        std::unordered_map<std::string, std::shared_ptr<ASystem>>   _systems;
        std::function<void(Event const &)>                          _function;
        int                                                         _entityID = 0;
        EGameState                                                  _state = EGameState::STOP;
        std::queue<Event>                                           _eventQueue;

    public:
        explicit GameSession(std::function<void(Event const &)> const &function) : _function(function)
        {
            _systems["PlayerMovement"] = std::shared_ptr<SMovement>(new SMovement);
            _systems["NonPlayerMovement"] = std::shared_ptr<SMovement>(new SMovement);
//            _systems["PlayerShootMissile"] = std::shared_ptr<SShoot>(new SShoot);
//            _systems["MonsterShootMissile"] = std::shared_ptr<SShoot>(new SShoot);
        }

        void                initSession();
        void                startGame();
        void                stopGame();
        void                sendMap();
        void                update();
        void                loop();

        template<EEntityType Type>
        void                insert()
        {
            _entities[_entityID] = _factory.generate<Type>();
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
                    _systems.at("PlayerShootMissile")->addEntity(_entities.at(_entityID), _entityID);
                    _systems.at("MonsterShootMissile")->addEntity(_entities.at(_entityID), _entityID);
                    break;
//                case EEntityType::PLAYERMISSILE:
//                    _systems.at("PlayerShootMissile")->addEntity(_entities.at(_entityID), _entityID);
//                  break;
//                case EEntityType::MONSTERMISSILE:
//                    _systems.at("MonsterShootMissile")->addEntity(_entities.at(_entityID), _entityID);
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

        int                         findMap()
        {
            for (const auto & it : _entities)
            {
                if (it.second->getType() == MAP)
                    return (it.first);
            }
            return -1;
        }

        void                        pushEvent(Event event) { _eventQueue.push(event); }

        ~GameSession() = default;
    };
}


#endif //CPP_RTYPE_GAMESESSION_HPP
