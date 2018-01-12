//
// Created by pashervz on 12/01/18.
//

#include <utils/Loader.hpp>
#include <server/AEntity.hpp>
#include <server/IPlayer.hpp>
#include "server/EntityFactory.hpp"

void                    EntityFactory::generatePlayer()
{
    Loader<IPlayer>     loader("libETPlayer.so");

    if (loader.Open() == EXIT_FAILURE)
        return ;
    loader.Load("create");

    IPlayer             *player = loader.getInstance();

    player->shoot();
}