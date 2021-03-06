//
// Created by pashervz on 15/01/18.
//

#ifndef CPP_RTYPE_AMAP_H
#define CPP_RTYPE_AMAP_H

#include <server/Components/CPosition.hpp>
#include <utils/EElement.hpp>
#include "AEntity.hpp"
#include "MapPacket.hpp"
#include <functional>
#include <map>

namespace FF
{
    class AMap : public AEntity
    {
    protected:
        float                                                                   _length;
        float                                                                   _width;
        std::map<std::unique_ptr<FF::CPosition>, MapElem>                       _map;

    public:
        AMap(float l, float w, EEntityType type) : AEntity(type), _length(l), _width(w) {}
        virtual ~AMap() = default;

        virtual void                                                  init() = 0;
        virtual bool                                                  doShifting(int, EElement, FF::CPosition const &) = 0;
        virtual void                                                  setLimits() = 0;

        bool                                                          isValid(FF::CPosition const &) const;
        bool                                                          putElem(FF::CPosition const &, MapElem const &);
        float                                                         getLength() const { return _length; }
        float                                                         getWidth() const { return _width; }
        void                                                          setLength(float length) { _length = length; }
        void                                                          setWidth(float width) { _width = width; }
        std::map<std::unique_ptr<FF::CPosition>, MapElem>  const &    getMap() const { return _map; };
        void                                           displayMap() const;
    };
}


#endif //CPP_RTYPE_AMAP_H
