//
// Created by myriam on 08/01/18.
//

#ifndef CPP_RTYPE_IWINDOW_HPP
#define CPP_RTYPE_IWINDOW_HPP

namespace   Client
{
    class   IWindow
    {
    public:
        virtual ~IWindow() = default;
        virtual void    createWindow(const std::string &) = 0;
        virtual void    closeWindow() = 0;
        virtual void    checkClose() = 0;
        virtual void    display() = 0;

        virtual void    initMenu() = 0;
        virtual void    startGame() = 0;
    };
}

#endif //CPP_RTYPE_IWINDOW_HPP
