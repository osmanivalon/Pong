//
// Created by valon.osmani on 09.12.2021.
//

#ifndef GAMES_PADDLE_H
#define GAMES_PADDLE_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Paddle : public sf::RectangleShape{
public:
    Paddle(sf::Vector2f rect, sf::Color col, sf::Vector2f pos);
    void Update(sf::RenderWindow &pWindow, sf::Time elapsed);
    void init();
    void setKeyUp(sf::Keyboard::Key k);
    void setKeyDown(sf::Keyboard::Key k);

private:
    sf::Keyboard::Key Up;
    sf::Keyboard::Key Down;
    sf::Vector2f initPos;
    sf::Time tempElapsedTime;

    float speed;
};
#endif //GAMES_PADDLE_H
