//
// Created by valon.osmani on 07.12.2021.
//

#ifndef GAMES_GAME_H
#define GAMES_GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Game
{
public:
    Game();

    void run();
    void init();
    bool  isRunning();

    bool running;
    sf::RenderWindow window;
};
#endif //GAMES_GAME_H
