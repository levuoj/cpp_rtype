//
// Created by pashervz on 15/01/18.
//

#ifndef CPP_RTYPE_ETMAP_HPP
#define CPP_RTYPE_ETMAP_HPP

#include "server/AMap.hpp"

namespace FF {
    class ETLevel1 : public FF::AMap {
    public:
        ETLevel1();

        virtual ~ETLevel1() = default;

        void init() final;

        void doShifting() final;

        void setLimits() final;
    };
}

#endif //CPP_RTYPE_ETMAP_HPP
