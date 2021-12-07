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
}

/*****************************************************
 *    Init methode
 * ***************************************************/
void Game::init() {
    running =  true;
}

/*****************************************************
 *    Methode to run the Game
 * ***************************************************/
 void Game::run() {
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                running = false;
            }
        }
        window.clear();
        //window.draw(shape);
        window.display();
    }
 }

/*****************************************************
*    Check if Game is running
* ***************************************************/
bool Game::isRunning() {
    return running;
}