//
// Created by pashervz on 09/01/18.
//

#ifndef CPP_RTYPE_CPOSITION_HPP
#define CPP_RTYPE_CPOSITION_HPP

#include "server/AComponent.hpp"

class CPosition : public AComponent
{
private:
    float             _posX;
    float             _posY;

public:
    CPosition();
    virtual ~CPosition() = default;

    void            moveForward(float speed) { _posX += speed; };
    void            moveBehind(float speed) { _posX -= speed; };
    void            moveLeft(float speed) { _posY += speed; };
    void            moveRight(float speed) { _posY += speed; };

    void            setX(float x) { _posX = x; }
    void            setY(float y) { _posY = y; }
    void            setXY(float x, float y) { _posX = x; _posY = y; }
    float           getX() const { return _posX; }
    float           getY() const { return _posY; }

    void            init() final;
};


#endif //CPP_RTYPE_CPOSITION_HPP
