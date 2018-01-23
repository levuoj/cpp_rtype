//
// Created by myriam on 22/01/18.
//

#ifndef CPP_RTYPE_MAP_HPP
#define CPP_RTYPE_MAP_HPP

#include "MovingBackground.hpp"
#include "AnimatedSprite.hpp"

namespace Client
{
    class Map
    {
    public:
        Map(sf::RenderWindow *window);
        ~Map() = default;
        void    displayGame();
        void    displaySprite(AnimatedSprite &);
        void    readData();


    private:
        sf::RenderWindow    *win;
        MovingBackground    gameBackground;
        std::vector<std::string>    data;
        std::vector<AnimatedSprite> map;
    };
}

#endif //CPP_RTYPE_MAP_HPP
