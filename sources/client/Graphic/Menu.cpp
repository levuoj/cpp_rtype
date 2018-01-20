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
    newGameWin(false),
    launchGame(false),
    menuSelection(0),
    playerSelection(0),
    nbPlayer(0),
    cursorX(150),
    cursorY(375),
    cursorPlayerX(1000),
    cursorPlayerY(600)
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
        displayText("press [space] to start", 850, 570, 25);
    }

    void    Client::Menu::menuCursor()
    {
        switch (key)
        {
            case ObservableKey::Up :
                if (menuSelection > 0 && !newGameWin) {
                    cursorY -= 100;
                    menuSelection -= 1;
                }
                break;
            case ObservableKey::Down :
                if (menuSelection < 2 && !newGameWin) {
                    cursorY += 100;
                    menuSelection += 1;
                }
                break;
            case ObservableKey::Return :
                if (inMenu)
                    selectionMenu();
                break;
            default:
                break;
        }
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
        if (newGameWin)
            newGame();
    }

    void    Client::Menu::newGame()
    {
        sf::Texture texture;
        sf::Sprite  frame;

        if (!texture.loadFromFile("../ressources/background/frame.png"))
            throw std::runtime_error("Cannot load file.");
        frame.setTexture(texture);
        frame.setPosition(900, 300);
        frame.scale(2, 2);
        if (newGameWin)
            win->draw(frame);

        displayText("Enter number players", 1080, 360, 40);

        sf::Texture sharigan;
        if (!sharigan.loadFromFile("../ressources/background/cursor.png"))
            throw std::runtime_error("Cannot load file.");
        cursorPlayer.setTexture(sharigan);
        cursorPlayer.setPosition(cursorPlayerX, cursorPlayerY);
        win->draw(cursorPlayer);
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
        if (key == 57 && inSplashScreen)
        {
            inSplashScreen = false;
            inMenu = true;
        }
        this->key = key;
        if (newGameWin)
            selectPlayer();
        else
            menuCursor();
    }

    bool    Client::Menu::getLaunchGame()
    {
        return launchGame;
    }

    void    Client::Menu::selectionMenu()
    {
        if (menuSelection == 0)
            newGameWin = true;
        // else Join or Option
    }

    void    Client::Menu::selectPlayer()
    {
        switch (key)
        {
            case ObservableKey::Left :
                if (playerSelection > 0) {
                    cursorPlayerX -= 150;
                    std::cout << "Left" << std::endl;
                    playerSelection -= 1;
                }
                break;
            case ObservableKey::Right :
                if (playerSelection < 3) {
                    cursorPlayerX += 150;
                    std::cout << "Right" << std::endl;
                    playerSelection += 1;
                }
                break;
            case ObservableKey::Return :
                nbPlayer = playerSelection + 1;
                launchGame = true;
                break;
            default:
                break;
        }
    }

}
