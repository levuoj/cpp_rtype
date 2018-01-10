//
// Created by pashervz on 10/01/18.
//

#ifndef CPP_RTYPE_FFENGINE_HPP
#define CPP_RTYPE_FFENGINE_HPP

#include "AEngine.hpp"

namespace FF {

    class FFEngine : public AEngine
    {
    public:
        explicit FFEngine(Mediator &);
        virtual ~FFEngine() {}
        virtual void receive(Event const &) final;
        virtual void launch() final;
    };
}


#endif //CPP_RTYPE_FFENGINE_HPP
