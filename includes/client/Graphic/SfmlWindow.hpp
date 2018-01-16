//
// Created by myriam on 08/01/18.
//

#ifndef CPP_RTYPE_SFMLWINDOW_HPP
#define CPP_RTYPE_SFMLWINDOW_HPP

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>

#include "IWindow.hpp"
#include "AObserver.hpp"
#include "ManageKeySFML.hpp"

namespace       Client
{
    struct  MovingBackground
    {
        sf::Texture     texture1;
        sf::Sprite      scrolling1;
        sf::Vector2f    pos1;

        sf::Texture     texture2;
        sf::Sprite      scrolling2;
        sf::Vector2f    pos2;

        float           spriteWidth;
    };

    class   SfmlWindow : public Client::IWindow, public AObserver
    {
    private:
        sf::RenderWindow    *win;
        int                 winWidth;
        int                 winHeight;
        bool                inMenu;
        bool                inGame;
        MovingBackground    background;
        std::unique_ptr<ManageKeySFML>          keyManager;

    public:
        SfmlWindow();
        ~SfmlWindow() = default;
        void    createWindow(const std::string &) final;
        void    closeWindow() final;
        void    display() final;

        void    initMenu() final;
        void    startGame() final;
        void    scrollingBack();

        void    actualize(Observable const &) final;
    };
}
#endif //CPP_RTYPE_SFMLWINDOW_HPP