//
// Created by myriam on 17/01/18.
//

#ifndef CPP_RTYPE_MOVINGBACKGROUND_HPP
#define CPP_RTYPE_MOVINGBACKGROUND_HPP

#include <SFML/Graphics.hpp>

namespace   Client
{
    class  MovingBackground
    {
    private:
        sf::Texture     texture1;
        sf::Sprite      scrolling1;
        sf::Vector2f    pos1;
        sf::Texture     texture2;
        sf::Sprite      scrolling2;
        sf::Vector2f    pos2;
        float           spriteWidth;

    public:
        MovingBackground();
        ~MovingBackground() = default;
        void            initBackground(const std::string &);
        void            scrollingBack(int, float);
        sf::Sprite      getFirstScrolling();
        sf::Sprite      getSecondScrolling();
    };
}

#endif //CPP_RTYPE_MOVINGBACKGROUND_HPP
