//
// Created by myriam on 22/01/18.
//

#include "client/Graphic/Map.hpp"

namespace   Client {
    Map::Map(sf::RenderWindow *window) :
        win(window)
    {
        gameBackground.initBackground("../ressources/background/image.png");
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
                    sf::Texture texture;
                    if (!texture.loadFromFile("../ressources/sprite/naruto_run.png")) {
                        throw (std::runtime_error("throw texture load"));
                    }
                    sf::Sprite sprite;
                    sprite.setTexture(texture);
                    sprite.setPosition(stof(ev.datas[idx - 2]) * 28.3f + 100.0f, stof(ev.datas[idx - 1]) * 20.0f + 600.0f);
                    win->draw(sprite);
                }
                ++idx;
            }
        }
        catch (std::exception const &e) {
            std::cout << e.what() << std::endl;
        }
    }
}