//
// Created by valon.osmani on 07.12.2021.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include "include/Game.h"

int main(int argc, char* argv[])
{
    Game cyberpong;
    cyberpong.init();

    while(cyberpong.isRunning()){
        cyberpong.run();
    }

    // TODO
    // Next: https://www.youtube.com/watch?v=V2ph1XamBDI

    return EXIT_SUCCESS;
}