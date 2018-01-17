//
// Created by myriam on 17/01/18.
//

#ifndef CPP_RTYPE_MENU_HPP
#define CPP_RTYPE_MENU_HPP

#include "MovingBackground.hpp"
#include "ObservableKey.hpp"
#include <iostream>

namespace   Client
{
    class   Menu
    {
    public:
        Menu(sf::RenderWindow *win);
        ~Menu() = default;
        void    displayText(const std::string &, int, int, int);
        void    splash();
        void    menu();
        void    display();
        void    getKey(const ObservableKey::Keys &);
        void    menuCursor();

    private:
        sf::RenderWindow    *win;
        bool                inSplashScreen;
        bool                inMenu;
        MovingBackground    menuBackground;
        int                 menuSelection;
        ObservableKey::Keys key;

        sf::Sprite          cursor;
        int                 cursorX;
        int                 cursorY;
    };
}
#endif //CPP_RTYPE_MENU_HPP
