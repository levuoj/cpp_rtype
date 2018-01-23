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
#include <functional>

#include "IWindow.hpp"
#include "AObserver.hpp"
#include "ManageKeySFML.hpp"
#include "AnimatedSprite.hpp"
#include "MovingBackground.hpp"
#include "Menu.hpp"
#include "utils/Event.hpp"
#include "Map.hpp"

namespace       Client
{
    class   SfmlWindow : public Client::IWindow, public AObserver
    {
    private:
        sf::RenderWindow    *win;
        int                 winWidth;
        int                 winHeight;
        bool                inMenu;
        bool                inGame;
        std::unique_ptr<ManageKeySFML>          keyManager;
        Menu                *menu;
        Map                 *map;

       // AnimatedSprite      *naruto;

    public:
        SfmlWindow(std::function<void(Event const &)> const &);
        ~SfmlWindow();

        void    createWindow(const std::string &) final;
        void    closeWindow() final;
        void    display() final;

        void    startGame() final;

        void    actualize(Observable const &) final;
        void    newEvent(EventType, SubType, const std::string &);
        std::function<void(Event const &)>  _notify;

    };
}
#endif //CPP_RTYPE_SFMLWINDOW_HPP
