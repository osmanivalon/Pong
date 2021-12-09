//
// Created by valon.osmani on 07.12.2021.
//

#ifndef GAMES_GAME_H
#define GAMES_GAME_H

#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Gamestate.h"
#include "MainMenuState.h"

class Game
{
public:
    Game();

    void run();
    bool  isRunning() const;

    bool running{};
    sf::RenderWindow window;

private:
    std::unique_ptr<Gamestate> CurrentState;
};
#endif //GAMES_GAME_H
