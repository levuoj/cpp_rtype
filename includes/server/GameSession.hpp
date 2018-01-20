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
        int                                                         _sessionID;
        EntityFactory                                               _factory;
        std::unordered_map<int, std::shared_ptr<AEntity>>           _entities;
        std::unordered_map<std::string, std::shared_ptr<ASystem>>   _systems;
        std::function<void(Event const &)>                          _function;
        int                                                         _entityID = 0;
        EGameState                                                  _state = EGameState::STOP;
        std::queue<Event>                                           _eventQueue;

    public:
        explicit GameSession(int, std::function<void(Event const &)> const &);
        ~GameSession() = default;
        void                initSession();
        void                startGame();
        void                stopGame();
        void                sendMap();
        void                update();
        void                loop();
        void                putInMap(APlayer *);
        void                assignSystems(int);
        int                 getSessionId() const { return _sessionID; }

        template<EEntityType Type>
        void                insert() {
            if (_factory.generate<Type>() == nullptr)
                return;
            _entities[_entityID] = _factory.generate<Type>();
            _entities.at(_entityID).get()->setId(_entityID);
            assignSystems(_entityID);
            if (findMap() != -1) {
                switch (Type) {
                    case EEntityType::PLAYER:
                        putInMap(reinterpret_cast<APlayer *>(_entities[_entityID].get()));
                        break;
                    default:
                        break;
                }
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
    };
}


#endif //CPP_RTYPE_GAMESESSION_HPP
