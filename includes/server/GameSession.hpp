//
// Created by pashervz on 13/01/18.
//

#ifndef CPP_RTYPE_GAMESESSION_HPP
#define CPP_RTYPE_GAMESESSION_HPP

#include <functional>
#include "EntityFactory.hpp"
#include "utils/Event.hpp"

namespace FF
{
    class GameSession {
    private:
        EntityFactory                                           _factory;
        std::unordered_map<int, std::shared_ptr<AEntity>>       _entities;
        std::function<void(Event const &)>                      _function;
        int                                                     _entityID = 0;

    public:
        explicit GameSession(std::function<void(Event const &)> const &function) : _function(function) {}
        void     startGame();

        template<EEntityType Type>
        void                insert()
        {
            _entities.insert(std::make_pair(_entityID, _factory.generate<Type>()));
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
