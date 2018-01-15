//
// Created by myriam on 08/01/18.
//

#include <client/Graphic/ObservableKey.hpp>
#include "client/Graphic/SfmlWindow.hpp"

namespace       Client {

    Client::SfmlWindow::SfmlWindow() :
    AObserver(),
    win(new sf::RenderWindow()),
    winWidth(1920),
    winHeight(1080),
    inSplashScreen(false),
    inMenu(false),
    inGame(true)
    {
        initMovingBackground(GameBackground, "../ressources/background/image.png");
        initMovingBackground(MenuBackground, "../ressources/background/back.png");
        naruto = new AnimatedSprite("../ressources/sprite/naruto.png", 360);
        naruto->initSprite(0, 0, 60, 60);
    }

    void Client::SfmlWindow::initMovingBackground(MovingBackground &background, std::string path)
    {
        if (!background.texture1.loadFromFile(path))
            throw std::runtime_error("Cannot open file.");
        background.scrolling1.setTexture(background.texture1);
        background.pos1.x = 0;
        background.pos1.y = 0;

        background.spriteWidth = background.scrolling1.getGlobalBounds().width;

        if (!background.texture2.loadFromFile(path))
            throw std::runtime_error("Cannot open file.");
        background.scrolling2.setTexture(background.texture2);
        background.pos2.x = background.spriteWidth;
        background.pos2.y = 0;
    }

    void Client::SfmlWindow::createWindow(const std::string &name)
    {
        this->win->create(sf::VideoMode(winWidth, winHeight, 64), name, sf::Style::Fullscreen);
        keyManager = std::unique_ptr<ManageKeySFML>(new ManageKeySFML(win));
        this->keyManager->setObserver(this);
    }

    void Client::SfmlWindow::closeWindow()
    {
        this->win->close();
        exit(0);
    }

    void Client::SfmlWindow::display()
    {
        if (inSplashScreen)
            displaySplash();
        else if (inMenu)
        {
            displayMenu();
        }
        else if (inGame)
        {
            this->scrollingBack(GameBackground, 0.5);
            displaySprite();
        }
        this->win->display();
    }

    void    Client::SfmlWindow::displayText(const std::string &string, int x, int y, int size)
    {
        sf::Text    text;
        sf::Font    font;

        if (!font.loadFromFile("../ressources/font/OptimusPrinceps.ttf"))
            throw std::runtime_error("Cannont load font.");
        text.setFont(font);
        text.setString(string);
        text.setCharacterSize(size);
        text.setPosition(x, y);
        text.setFillColor(sf::Color::White);
        win->draw(text);
    }

    void    Client::SfmlWindow::displaySplash()
    {
        scrollingBack(MenuBackground, 0.1);
        displayText("Akastuki's Revenge", 700, 500, 60);
        displayText("press [enter] to start", 850, 570, 25);
    }

    void    Client::SfmlWindow::displayMenu()
    {
        scrollingBack(MenuBackground, 0.1);

    }

    void    Client::SfmlWindow::scrollingBack(MovingBackground &back, float speed)
    {
        if (back.pos1.x < back.spriteWidth * -1)
            back.pos1.x = winWidth;
        if (back.pos2.x == back.spriteWidth * -1)
            back.pos2.x = winWidth;

        back.scrolling1.setPosition(back.pos1);
        back.scrolling2.setPosition(back.pos2);

        win->draw(back.scrolling1);
        back.pos1.x -= speed;
        win->draw(back.scrolling2);
        back.pos2.x -= speed;
    }

    void Client::SfmlWindow::actualize(Observable const &observable)
    {
        auto key = static_cast<ObservableKey const &>(observable).getKey();
        std::cout << "Key pressed :" << key << std::endl;
        if (inSplashScreen && key == 58)
        {
            inSplashScreen = false;
            inMenu = true;
        }
        else if (key == 36)
            closeWindow();
        else if (key == 73)
            naruto->setPositionUp(); //send package go up
        else if (key == 74)
            naruto->setPositionDown(); //send package go up
        else if (key == 71)
            naruto->setPositionLeft(); //send package go lef
        else if (key == 72)
            naruto->setPositionRight(); //send package go right

    }

    void    Client::SfmlWindow::displaySprite()
    {
       if (clock.getElapsedTime().asSeconds() > 0.12f)
        {
            std::cout << "tst" << std::endl;
            naruto->nextSprite(60);
            clock.restart();
        }
        win->draw(naruto->getSprite());
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
            this->display();
        }
    }
}