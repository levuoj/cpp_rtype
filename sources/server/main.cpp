#include <server/Systems/SMovement.hpp>
#include <server/Entities/ETPlayer.hpp>
#include "server/Mediator.hpp"
#include "server/ASystem.hpp"

int main()
{
    SMovement       movement;
    ETPlayer        player;

    movement.addEntity(player);
    while (1)
    {
        movement.execute();
    }
}
