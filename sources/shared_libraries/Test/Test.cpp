//
// Created by pashervz on 05/01/18.
//

#include <iostream>
#include "external_things/Test/Test.hpp"

void                Test::helloWorld() {
    std::cout << "Sexy Lady" << std::endl;
}

extern "C"
{
    Test        *entryPoint()
    {
        return (new Test());
    }
}