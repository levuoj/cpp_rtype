//
// Created by pashervz on 09/01/18.
//

#ifndef CPP_RTYPE_CPOSITION_HPP
#define CPP_RTYPE_CPOSITION_HPP


#include "AComponent.hpp"

class CPosition : public AComponent
{
private:
    int             _posX;
    int             _posY;

public:
    CPosition();
    virtual ~CPosition() = default;

    void            setX(int x) { _posX = x; }
    void            setY(int y) { _posY = y; }
    void            setXY(int x, int y) { _posX = x; _posY = y; }
    int             getX() const { return _posX; }
    int             getY() const { return _posY; }

    void            update() override final;
};


#endif //CPP_RTYPE_CPOSITION_HPP
