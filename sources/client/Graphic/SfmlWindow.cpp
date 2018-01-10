//
// Created by myriam on 08/01/18.
//

#include <client/Graphic/ObservableKey.hpp>
#include "client/Graphic/SfmlWindow.hpp"

namespace       Client {

    Client::SfmlWindow::SfmlWindow() :
    AObserver(),
    win(new sf::RenderWindow()),
    winWidth(1700),
    winHeight(1000),
    inMenu(true),
    inGame(false)
    {
        if (!background.texture1.loadFromFile("../ressources/scroll.png"))
            throw std::runtime_error("Cannot open file.");
        background.scrolling1.setTexture(background.texture1);
        background.pos1.x = 0;
        background.pos1.y = 0;

        background.spriteWidth = background.scrolling1.getGlobalBounds().width;

        if (!background.texture2.loadFromFile("../ressources/scroll.png"))
            throw std::runtime_error("Cannot open file.");
        background.scrolling2.setTexture(background.texture2);
        background.pos2.x = background.spriteWidth;
        background.pos2.y = 0;

    }

    void Client::SfmlWindow::createWindow(const std::string &name)
    {
        this->win->create(sf::VideoMode(winWidth, winHeight, 64), name, sf::Style::Close);
        keyManager = std::unique_ptr<ManageKeySFML>(new ManageKeySFML(win));
        this->keyManager->setObserver(this);
    }

    void Client::SfmlWindow::closeWindow()
    {
        this->win->close();
    }

    void Client::SfmlWindow::display()
    {
        this->win->display();
    }

    void            Client::SfmlWindow::initMenu()
    {
        sf::Texture background;
        sf::Sprite  sprite;

        this->win->clear(sf::Color::Black);
        if (!background.loadFromFile("../ressources/cloud.jpg"))
            throw std::runtime_error("Cannot open file.");
        sprite.setTexture(background);
        sprite.setPosition(800, 300);
        sprite.setScale(0.2, 0.2);
        this->win->draw(sprite);
    }

    void    Client::SfmlWindow::scrollingBack()
    {
        if (background.pos1.x < background.spriteWidth * -1)
            background.pos1.x = winWidth;
        if (background.pos2.x == background.spriteWidth * -1)
            background.pos2.x = winWidth;

        background.scrolling1.setPosition(background.pos1);
        background.scrolling2.setPosition(background.pos2);

        win->draw(background.scrolling1);
        background.pos1.x -= 0.5;
        win->draw(background.scrolling2);
        background.pos2.x -= 0.5;
    }

    void Client::SfmlWindow::actualize(Observable const &observable)
    {
        std::cout << "Key pressed :" << static_cast<ObservableKey const &>(observable).getKey() << std::endl;
    }

    void Client::SfmlWindow::startGame()
    {
        this->createWindow("Akatsuki");
        while (win->isOpen())
        {
            sf::Event   event;
            while (win->pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    this->closeWindow();
                if (event.type == sf::Event::KeyPressed)
                    this->keyManager->catchKey(event.key.code);
            }
            if (inMenu)
                this->initMenu();
            else if (inGame)
                this->scrollingBack();
            this->display();
        }
    }
}