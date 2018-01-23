//
// Created by myriam on 15/01/18.
//

#include "client/Graphic/AnimatedSprite.hpp"

namespace Client {

    Client::AnimatedSprite::AnimatedSprite(std::string const &path, int sheetWidth) {
        if (!this->texture.loadFromFile(path))
            throw std::runtime_error("Cannot load file.");
        this->sheetWidth = sheetWidth;
    }

    void Client::AnimatedSprite::initSprite(int top, int left, int width, int height) {
        this->rectSprite.top = top;
        this->rectSprite.left = left;
        this->rectSprite.width = width;
        this->rectSprite.height = height;

        sprite.setTexture(texture);
        sprite.setTextureRect(rectSprite);
        sprite.setPosition(x, y);
    }

    void Client::AnimatedSprite::nextSprite(int left) {
        if (clock.getElapsedTime().asSeconds() > 0.12f) {
            if (rectSprite.left == sheetWidth - rectSprite.width)
                rectSprite.left = 0;
            else
                rectSprite.left += left;
            clock.restart();
        }
        sprite.setTextureRect(rectSprite);
    }

    sf::Sprite Client::AnimatedSprite::getSprite() {
        this->nextSprite(60);
        return sprite;
    }

    void    AnimatedSprite::setPosition(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    void    AnimatedSprite::setX(int x)
    {
        this->x = x;
    }

    void    AnimatedSprite::setY(int y)
    {
        this->y = y;
    }
}