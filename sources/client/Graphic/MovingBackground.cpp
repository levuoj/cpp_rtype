//
// Created by myriam on 17/01/18.
//

#include "client/Graphic/MovingBackground.hpp"

namespace   Client
{
    Client::MovingBackground::MovingBackground()
    {

    }

    void Client::MovingBackground::initBackground(const std::string &path)
    {
        if (!texture1.loadFromFile(path))
            throw std::runtime_error("Cannot open file.");
        scrolling1.setTexture(texture1);
        pos1.x = 0;
        pos1.y = 0;

        spriteWidth = scrolling1.getGlobalBounds().width;

        if (!texture2.loadFromFile(path))
            throw std::runtime_error("Cannot open file.");
        scrolling2.setTexture(texture2);
        pos2.x = spriteWidth;
        pos2.y = 0;
    }

    void    Client::MovingBackground::scrollingBack(int winWidth, float speed)
    {
        if (pos1.x < spriteWidth * -1)
            pos1.x = winWidth;
        if (pos2.x < spriteWidth * -1)
            pos2.x = winWidth;

        scrolling1.setPosition(pos1);
        scrolling2.setPosition(pos2);

        pos1.x -= speed;
        pos2.x -= speed;
    }

    sf::Sprite  Client::MovingBackground::getFirstScrolling()
    {
        return scrolling1;
    }

    sf::Sprite  Client::MovingBackground::getSecondScrolling()
    {
        return scrolling2;
    }
}