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

    public:
        explicit GameSession(std::function<void(Event const &)> const &function) : _function(function) {}
        ~GameSession() = default;
    };
}


#endif //CPP_RTYPE_GAMESESSION_HPP
