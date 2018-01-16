//
// Created by pashervz on 09/01/18.
//

#ifndef CPP_RTYPE_CPOSITION_HPP
#define CPP_RTYPE_CPOSITION_HPP

#include "server/AComponent.hpp"

namespace FF
{
    class CPosition : public AComponent
    {
    private:
        float _posX;
        float _posY;

    public:
        CPosition();
        CPosition(float x, float y) : AComponent("Position"), _posX(x), _posY(y) {}
        virtual ~CPosition() = default;

        void moveForward(float speed) { _posX += speed; };
        void moveBehind(float speed) { _posX -= speed; };
        void moveLeft(float speed) { _posY += speed; };
        void moveRight(float speed) { _posY -= speed; };
        void setX(float x) { _posX = x; }
        void setY(float y) { _posY = y; }
        void setXY(float x, float y) {
            _posX = x;
            _posY = y;
        }
        float getX() const { return _posX; }
        float getY() const { return _posY; }

        void init() final;

        bool                    operator==(CPosition const &pos) const
        {
            if (_posX != pos.getX())
                return false;
            if (_posY != pos.getY())
                return false;
            return true;
        }
    };
}


#endif //CPP_RTYPE_CPOSITION_HPP
