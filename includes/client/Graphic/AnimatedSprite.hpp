//
// Created by myriam on 15/01/18.
//

#ifndef CPP_RTYPE_ANIMATEDSPRITE_HPP
#define CPP_RTYPE_ANIMATEDSPRITE_HPP

#include <SFML/Graphics.hpp>

namespace       Client
{
    class   AnimatedSprite
    {
    private:
        sf::Clock       clock;
        sf::Texture     texture;
        sf::IntRect     rectSprite;
        sf::Sprite      sprite;

        int             sheetWidth;
        int             x;
        int             y;

    public:
        AnimatedSprite(std::string const &, int sheetWidth);
        ~AnimatedSprite() = default;
        void            initSprite(int, int, int, int);
        void            nextSprite(int width);
        void            setPosition(int, int);
        sf::Sprite      getSprite();
    };
}

#endif //CPP_RTYPE_ANIMATEDSPRITE_HPP
