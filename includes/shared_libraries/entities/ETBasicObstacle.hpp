//
// Created by Oraekia on 16/01/18.
//

#ifndef CPP_RTYPE_ETBASICOBSTACLE_HPP
#define CPP_RTYPE_ETBASICOBSTACLE_HPP


#include <server/AObstacle.hpp>

namespace FF
{
    class ETBasicObstacle : public AObstacle
    {
    public:
        ETBasicObstacle() : AObstacle() {}
        virtual ~ETBasicObstacle() = default;

        void    move() final;
        int     explosion() final;
        void    takeDamage(int power) final;
        void    setPosition(float x, float y) final { reinterpret_cast<CPosition*>(this->getComponent("CPosition"))->setXY(x, y); }
        int     score() final { return (reinterpret_cast<CScore*>(this->getComponent("CScore"))->getScore()); }

        void    init() final;
    };
}


#endif //CPP_RTYPE_ETBASICOBSTACLE_HPP
