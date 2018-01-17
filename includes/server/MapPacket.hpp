//
// Created by pashervz on 17/01/18.
//

#ifndef CPP_RTYPE_MAPPACKET_HPP
#define CPP_RTYPE_MAPPACKET_HPP

#include <utils/EElement.hpp>
#include <unordered_map>

template<typename T>
struct Coords
{
    T           posx;
    T           posy;

    Coords(T x, T y) : posx(x), posy(y) {}
    ~Coords() = default;
};

struct MapPacket
{
    std::unordered_map<Coords<float>, EElement>           _map;

    void            insert(Coords<float>, EElement element)
    {
        _map[Coords<float>] = element;
    }
};

#endif //CPP_RTYPE_MAPPACKET_HPP
