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
#include "Playstate.h"

class Game
{
public:
    Game();

    enum class gameState {MAINMENU, PLAY};
    void run();
    bool isRunning() const;
    void changeState(gameState newstate);
    bool running{};
    sf::RenderWindow window;

    sf::Clock clock;
    sf::Time then = clock.getElapsedTime();
    sf::Time now;
    sf::Time frameDeltaTime;

private:
    std::unique_ptr<Gamestate> CurrentState;
};
#endif //GAMES_GAME_H
