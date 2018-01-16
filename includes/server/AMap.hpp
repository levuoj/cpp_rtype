//
// Created by pashervz on 15/01/18.
//

#ifndef CPP_RTYPE_AMAP_H
#define CPP_RTYPE_AMAP_H

#include <server/Components/CPosition.hpp>
#include <utils/EElement.hpp>
#include "AEntity.hpp"
#include <functional>
#include <map>

namespace FF
{
    class AMap : public AEntity
    {
    protected:
        float                                                                   _length;
        float                                                                   _width;
        std::map<std::unique_ptr<FF::CPosition>, EElement>                      _map;

    public:
        AMap(float length, float width) : AEntity("Map"), _length(length), _width(width) {}
        virtual ~AMap() = default;

        virtual void                init() = 0;
        virtual void                doShifting() = 0;
        virtual void                setLimits() = 0;

        bool                        isValid(FF::CPosition const &) const;
        bool                        putElem(FF::CPosition const &, EElement);
        float                       getLength() const { return _length; }
        float                       getWidth() const { return _width; }
        void                        setLength(float length) { _length = length ;}
        void                        setWidth(float width) { _width = width ;}

        void                        displayMap() const;
    };
}


#endif //CPP_RTYPE_AMAP_H
