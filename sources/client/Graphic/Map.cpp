//
// Created by myriam on 22/01/18.
//

#include "client/Graphic/Map.hpp"

namespace   Client {
    Map::Map(sf::RenderWindow *window) :
            win(window) {
        gameBackground.initBackground("../ressources/background/image.png");
        data.emplace_back("PLAYER");
        data.emplace_back("400");
        data.emplace_back("500");
    }

    void Map::displayGame() {
        gameBackground.scrollingBack(1920, 0.5);
        win->draw(gameBackground.getFirstScrolling());
        win->draw(gameBackground.getSecondScrolling());
    }

    void Map::displaySprite(AnimatedSprite &sprite) {
        win->draw(sprite.getSprite());
    }

    void Map::displayMap(Event const &ev) {
        try {
            int idx = 0;
            for (auto const &it : ev.datas) {
                if (it == "1") {
                    std::cout << "1" << std::endl;
                    sf::Texture texture;
                    std::cout << "2" << std::endl;
                    if (!texture.loadFromFile("../ressources/sprite/naruto_run.png")) {
                        throw (std::runtime_error("throw texture load"));
                    }
                    std::cout << "3" << std::endl;
                    sf::Sprite sprite;
                    std::cout << "4" << std::endl;
                    sprite.setTexture(texture);
                    std::cout << "5" << std::endl;
                    sprite.setPosition(stof(ev.datas[idx - 2]), stof(ev.datas[idx - 1]));
                    std::cout << "6" << std::endl;
                    win->draw(sprite);
                    std::cout << "7" << std::endl;

                }
                ++idx;
            }
        }
        catch (std::exception const &e) {
            std::cout << e.what() << std::endl;
        }
    }
}
    /*void    Map::readData()
    {
        for (int i = 0; i < data.size(); i++) {
            AnimatedSprite  newSprite("../ressources/sprite/naruto_run.png", 360);
            i++;
            map.push_back(newSprite);
        }
    }*/
