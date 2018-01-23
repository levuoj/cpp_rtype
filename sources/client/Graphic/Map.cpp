//
// Created by myriam on 22/01/18.
//

#include "client/Graphic/Map.hpp"

namespace   Client
{
    Map::Map(sf::RenderWindow *window) :
    win(window)
    {
        gameBackground.initBackground("../ressources/background/image.png");
        data.emplace_back("PLAYER");
        data.emplace_back("400");
        data.emplace_back("500");
    }

    void    Map::displayGame()
    {
        gameBackground.scrollingBack(1920, 0.5);
        win->draw(gameBackground.getFirstScrolling());
        win->draw(gameBackground.getSecondScrolling());
    }

    void    Map::displaySprite(AnimatedSprite &sprite)
    {
        win->draw(sprite.getSprite());
    }

    /*void    Map::readData()
    {
        for (int i = 0; i < data.size(); i++) {
            AnimatedSprite  newSprite("../ressources/sprite/naruto_run.png", 360);
            i++;
            map.push_back(newSprite);
        }
    }*/
}