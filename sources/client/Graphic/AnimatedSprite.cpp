//
// Created by myriam on 15/01/18.
//

#include "client/Graphic/AnimatedSprite.hpp"

Client::AnimatedSprite::AnimatedSprite(std::string const &path, int sheetWidth)
{
    if (!this->texture.loadFromFile(path))
        throw std::runtime_error("Cannot load file.");
    this->sheetWidth = sheetWidth;

    x = 500;
    y = 700;
}

void        Client::AnimatedSprite::initSprite(int top, int left, int width, int height)
{
    this->rectSprite.top = top;
    this->rectSprite.left = left;
    this->rectSprite.width = width;
    this->rectSprite.height = height;

    sprite.setTexture(texture);
    sprite.setTextureRect(rectSprite);
    sprite.setPosition(x, y);
}

void    Client::AnimatedSprite::nextSprite(int left)
{
    if (rectSprite.left == sheetWidth - rectSprite.width)
        rectSprite.left = 0;
    else
        rectSprite.left += left;

    sprite.setTextureRect(rectSprite);
}

sf::Sprite      Client::AnimatedSprite::getSprite()
{
    return sprite;
}

void    Client::AnimatedSprite::setPositionUp()
{
    y += 3;
    sprite.setPosition(x, y);
}

void    Client::AnimatedSprite::setPositionDown()
{
    y -= 3;
    sprite.setPosition(x, y);
}

void    Client::AnimatedSprite::setPositionRight()
{
    x += 3;
    sprite.setPosition(x, y);
}

void    Client::AnimatedSprite::setPositionLeft()
{
    x -= 3;
    sprite.setPosition(x, y);
}