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
    // Main/Base/First window of game
    window.create(sf::VideoMode(1280, 720), "CyberPong");
    running =  true;

}


/*****************************************************
 *    Methode to run the Game
 * ***************************************************/
 void Game::run() {
    while (window.isOpen())
    {
        now = clock.getElapsedTime();
        frameDeltaTime = (now - then);
        then = now;

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

void Game::changeState(Game::gameState newState) {
    switch (newState) {
        case gameState::MAINMENU:
            CurrentState = move(std::unique_ptr<MainMenuState>(new MainMenuState));
            break;
        case gameState::PLAY:
            CurrentState = move(std::unique_ptr<Playstate>(new Playstate));
            break;
        default:
            break;
    }
}
