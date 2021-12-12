//
// Created by valon.osmani on 07.12.2021.
//

#include <iostream>
#include "include/Game.h"

int main(int argc, char* argv[])
{
    Game pingpong;
    pingpong.changeState(Game::gameState::MAINMENU);

    while(pingpong.isRunning()){
        pingpong.run();
    }

    // TODO
    // Next: https://www.youtube.com/watch?v=V2ph1XamBDI

    return EXIT_SUCCESS;
}