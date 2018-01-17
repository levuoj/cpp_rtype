//
// Created by myriam on 17/01/18.
//

#include "client/Graphic/Menu.hpp"

namespace   Client
{
    Client::Menu::Menu(sf::RenderWindow *window) :
    win(window),
    inSplashScreen(true),
    inMenu(false),
    menuSelection(0),
    cursorX(150),
    cursorY(375)
    {
        menuBackground.initBackground("../ressources/background/back.png");
    }

    void    Client::Menu::displayText(const std::string &string, int x, int y, int size)
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

    void    Client::Menu::splash()
    {
        menuBackground.scrollingBack(1920, 0.1);
        win->draw(menuBackground.getFirstScrolling());
        win->draw(menuBackground.getSecondScrolling());

        displayText("Akastuki's Revenge", 700, 500, 60);
        displayText("press [enter] to start", 850, 570, 25);
    }

    void    Client::Menu::menuCursor()
    {
        switch (key)
        {
            case ObservableKey::Up :
                if (menuSelection > 0) {
                    cursorY -= 100;
                    cursor.setPosition(150, cursorY);
                    menuSelection -= 1;
                }
                break;
            case ObservableKey::Down :
                if (menuSelection < 2) {
                    cursorY += 100;
                    cursor.setPosition(150, cursorY);
                    menuSelection += 1;
                }
                break;
            case ObservableKey::Return :
                
            default:
                break;
        }
        std::cout << menuSelection << std::endl;
    }

    void    Client::Menu::menu()
    {
        menuBackground.scrollingBack(1920, 0.1);
        win->draw(menuBackground.getFirstScrolling());
        win->draw(menuBackground.getSecondScrolling());

        sf::Texture texture;
        sf::Sprite  sprite;
        if (!texture.loadFromFile("../ressources/background/banner.png"))
            throw std::runtime_error("Cannot open file.");
        sprite.setTexture(texture);
        sprite.setPosition(150, 0);
        win->draw(sprite);

        displayText("Menu", 260, 100, 70);
        displayText("New Game", 260, 400, 40);
        displayText("Join Game", 270, 500, 40);
        displayText("Options", 280, 600, 40);

        sf::Texture kunai;
        if (!kunai.loadFromFile("../ressources/background/kunai.png"))
            throw std::runtime_error("Cannot load file.");
        cursor.setTexture(kunai);
        cursor.setPosition(cursorX, cursorY);
        win->draw(cursor);
    }

    void    Client::Menu::display()
    {
        if (inMenu)
            menu();
        else if (inSplashScreen)
            splash();
    }

    void    Client::Menu::getKey(const ObservableKey::Keys &key)
    {
        if (key == 58)
        {
            inSplashScreen = false;
            inMenu = true;
        }
        this->key = key;
        menuCursor();
    }
}
