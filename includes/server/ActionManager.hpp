//
// Created by pashervz on 23/01/18.
//

#ifndef CPP_RTYPE_ACTIONMANAGER_HPP
#define CPP_RTYPE_ACTIONMANAGER_HPP

#include <utils/Error.hpp>
#include "ASystem.hpp"

namespace FF
{
    enum   ActionType
    {
        MOVE_FORWARD,
        MOVE_BACKWARD,
        MOVE_UP,
        MOVE_DOWN,
        SHOOT
    };

    struct Action {
        ActionType  actionType;
        int         playerId;

        Action(ActionType type, int id) : actionType(type), playerId(id) {}
    };

    class ActionManager {
        std::unordered_map<std::string, std::shared_ptr<ASystem>>   _playerSystems;

    public:
        ActionManager() = default;
        ~ActionManager() = default;

        void            doAction(Action);

        void            addSystem(std::string const & str, std::shared_ptr<ASystem> system)
        {
            _playerSystems[str] = system;
        }

        void           removeSystem(std::string const & str)
        {
            if (_playerSystems.find(str) == _playerSystems.end())
                throw Error(str + " doesn't exist");
            _playerSystems.erase(_playerSystems.find(str));
        }

        void           assign(std::string const & system, std::shared_ptr<AEntity> entity, int id)
        {
            if (_playerSystems.find(system) == _playerSystems.end())
                throw Error(system + " doesn't exist");
            _playerSystems[system]->addEntity(entity, id);
        }
    };
}

#endif //CPP_RTYPE_ACTIONMANAGER_HPP
