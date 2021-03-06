//
// Created by Oraekia on 10/01/18.
//

#ifndef CPP_RTYPE_CSHIELD_HPP
#define CPP_RTYPE_CSHIELD_HPP


#include <server/AComponent.hpp>

namespace FF
{
    class CShield : public AComponent
    {
    private:
        int _healthOfShield;
        bool _isActivate;
    public:
        CShield();
        CShield(int);
        virtual ~CShield() = default;

        void takeDamage(int power);
        void regeneration(int regen);
        void Disable();
        void Active();
        void increaseShield() { _healthOfShield++; }
        void setHealthOfShield(int shield) { _healthOfShield = shield; }
        int getShield() const { return (_healthOfShield); }
        bool getActivation() const { return (_isActivate); }

        void init() final;
    };
}


#endif //CPP_RTYPE_CSHIELD_HPP
