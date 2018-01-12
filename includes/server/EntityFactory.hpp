//
// Created by pashervz on 12/01/18.
//

#ifndef CPP_RTYPE_ENTITYFACTORY_HPP
#define CPP_RTYPE_ENTITYFACTORY_HPP

#include <unordered_map>
#include "server/IPlayer.hpp"
#include "utils/Loader.hpp"

class EntityFactory {
private:
    Loader<IPlayer>         _loaderPlayer;
    int                     _nbPlayer = 0;

public:
    EntityFactory() = default;
    ~EntityFactory() = default;

    IPlayer                 *generatePlayer();
};


#endif //CPP_RTYPE_ENTITYFACTORY_HPP
