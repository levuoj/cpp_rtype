//
// Created by pashervz on 12/01/18.
//

#include <utils/Loader.hpp>
#include "server/EntityFactory.hpp"

IPlayer                    *EntityFactory::generatePlayer()
{
    if (_loaderPlayer.isOpen()) {
        _loaderPlayer.setPath("../lib/libETPlayer.so");
        _loaderPlayer.Open();
    }

    _loaderPlayer.Load("create", _nbPlayer);
    _nbPlayer += 1;
    return (_loaderPlayer.getInstance(_nbPlayer - 1));
}
