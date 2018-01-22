//
// Created by myriam on 08/01/18.
//

#include <client/Graphic/ObservableKey.hpp>
#include "client/Graphic/SfmlWindow.hpp"

namespace       Client {

    Client::SfmlWindow::SfmlWindow(std::function<void(Event const &)> const &notify) :
    AObserver(),
    win(new sf::RenderWindow()),
    winWidth(1920),
    winHeight(1080),
    inMenu(true),
    inGame(false),
    menu(new Menu(win)),
    _notify(notify)
    {
        GameBackground.initBackground("../ressources/background/image.png");
        naruto = new AnimatedSprite("../ressources/sprite/itachi_attack.png", 360);
        naruto->setPosition(500, 700);
        naruto->initSprite(0, 0, 60, 60);
    }

    Client::SfmlWindow::~SfmlWindow() {
        delete menu;
        delete naruto;
        delete win;
    }

    void Client::SfmlWindow::createWindow(const std::string &name) {
        this->win->create(sf::VideoMode(winWidth, winHeight, 64), name, sf::Style::Fullscreen);
        keyManager = std::unique_ptr < ManageKeySFML > (new ManageKeySFML(win));
        this->keyManager->setObserver(this);
    }

    void Client::SfmlWindow::closeWindow() {
        this->win->close();
        exit(0);
    }

    void Client::SfmlWindow::display() {
        if (inMenu) {
            menu->display();
            if (menu->getLaunchGame()) {
                inMenu = false;
                newEvent(NEWGAME, FROMCLIENT, std::to_string(menu->getNbPlayer()));
            }
        } else if (inGame) {
            GameBackground.scrollingBack(1920, 0.5);
            win->draw(GameBackground.getFirstScrolling());
            win->draw(GameBackground.getSecondScrolling());
            displaySprite();
        }
        this->win->display();
    }


    void Client::SfmlWindow::actualize(Observable const &observable) {
        auto key = static_cast<ObservableKey const &>(observable).getKey();
        std::cout << "KEY " << key << std::endl;
        if (key == 36) {
            closeWindow();
            newEvent(QUITGAME, FROMCLIENT, nullptr);
        }
        if (inMenu)
            menu->getKey(key);
        else {
            switch (key) {
                case ObservableKey::Up :
                    newEvent(INPUT, FROMCLIENT, "Up");
                    break;
                case ObservableKey::Down :
                    newEvent(INPUT, FROMCLIENT, "Down");
                    break;
                case ObservableKey::Right :
                    newEvent(INPUT, FROMCLIENT, "Right");
                    break;
                case ObservableKey::Left :
                    newEvent(INPUT, FROMCLIENT, "Left");
                    break;
                case ObservableKey::Space :
                    newEvent(INPUT, FROMCLIENT, "Space");
                    break;
                default:
                    break;
            }
        }
    }

    void Client::SfmlWindow::displaySprite() {
        win->draw(naruto->getSprite());
    }


    void Client::SfmlWindow::startGame() {
        this->createWindow("Akatsuki");

        while (win->isOpen()) {
            sf::Event event;
            while (win->pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    this->closeWindow();
                if (event.type == sf::Event::KeyPressed)
                    this->keyManager->catchKey(event.key.code);
            }
            this->display();
        }
    }

    void Client::SfmlWindow::newEvent(EventType type, SubType subtype, const std::string &data)
    {
        Event   event;

        event.type = type;
        event.subType = subtype;
        event.datas.push_back(data);
        _notify(event);
    }
}