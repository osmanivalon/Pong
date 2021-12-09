//
// Created by valon.osmani on 07.12.2021.
//

#include "../include/Game.h"

using namespace std;

/*****************************************************
 *    Constructor
 * ***************************************************/
Game::Game()
{
    window.create(sf::VideoMode(1280, 720), "CyberPong");
    running =  true;

    CurrentState = std::move(std::unique_ptr<MainMenuState>(new MainMenuState));
}


/*****************************************************
 *    Methode to run the Game
 * ***************************************************/
 void Game::run() {
    while (window.isOpen())
    {
        CurrentState->HandleEvents(*this);
        window.clear(sf::Color(0,134,194));

        CurrentState->Update(*this);
        CurrentState->Draw(*this);

        window.display();
    }
 }

/*****************************************************
*    Check if Game is running
* ***************************************************/
bool Game::isRunning() const {
    return running;
}