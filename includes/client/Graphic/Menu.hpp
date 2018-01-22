//
// Created by myriam on 17/01/18.
//

#ifndef CPP_RTYPE_MENU_HPP
#define CPP_RTYPE_MENU_HPP

#include "MovingBackground.hpp"
#include "ObservableKey.hpp"
#include <iostream>
#include <string>

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
        void    newGame();
        bool    getLaunchGame();
        void    selectionMenu();
        void    selectPlayer();
        int     getNbPlayer();
        void    joinGame();
        void    enterIP();

    private:
        sf::RenderWindow    *win;
        bool                inSplashScreen;
        bool                inMenu;

        bool                newGameWin;
        bool                joining;
        bool                launchGame;

        MovingBackground    menuBackground;
        int                 menuSelection;
        int                 playerSelection;
        int                 nbPlayer;
        std::string         ipAddress;

        ObservableKey::Keys key;

        sf::Sprite          cursor;
        int                 cursorX;
        int                 cursorY;

        sf::Sprite          cursorPlayer;
        int                 cursorPlayerX;
        int                 cursorPlayerY;
    };
}
#endif //CPP_RTYPE_MENU_HPP
