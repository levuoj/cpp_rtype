//
// Created by myriam on 10/01/18.
//

#ifndef CPP_RTYPE_GRAPHICMANAGER_HPP
#define CPP_RTYPE_GRAPHICMANAGER_HPP

#include "utils/AManager.hpp"
#include "client/Graphic/SfmlWindow.hpp"
#include "utils/Event.hpp"
#include <functional>

namespace   Client
{
    class   GraphicManager : public AManager
    {
    private:
        SfmlWindow      *window;

    public:
        GraphicManager(Mediator &);
        ~GraphicManager();

        virtual void    receive(Event const &);
        virtual void    launch();
        void           notify(Event const &);
    };
}

#endif //CPP_RTYPE_GRAPHICMANAGER_HPP
