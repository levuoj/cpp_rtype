//
// Created by pashervz on 17/01/18.
//

#ifndef CPP_RTYPE_MAPPACKET_HPP
#define CPP_RTYPE_MAPPACKET_HPP

#include <utils/EElement.hpp>
#include <map>

template<typename T>
struct Coords
{
    T           posx;
    T           posy;

    Coords(T x, T y) : posx(x), posy(y) {}
    ~Coords() = default;

    bool            operator<(Coords const & coords) const
    {
        return ((posx + posy) < (coords.posx + coords.posy));
    }
};

struct MapPacket
{
    std::map<Coords<float>, EElement>           _map;

    void            insert(Coords<float> coords, EElement element)
    {
        _map[coords] = element;
    }
};

#endif //CPP_RTYPE_MAPPACKET_HPP
