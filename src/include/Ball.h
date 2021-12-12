//
// Created by valon.osmani on 10.12.2021.
//
// Präprozessoren, um zu vermeiden, dass es zweimal definiert wird
#ifndef GAMES_BALL_H
#define GAMES_BALL_H

#include "../include/Paddle.h"

class Ball : public sf::CircleShape{
public:
    Ball(float rad, sf::Color col, sf::Vector2f pos, std::shared_ptr<Paddle> pad1, std::shared_ptr<Paddle> pad2);
    void init();
    void Update(sf::RenderWindow &pWindow, sf::Time elapsed);

private:
    int direction;
    float speed;
    sf::Vector2f movement;

    std::shared_ptr<Paddle> pPad1;
    std::shared_ptr<Paddle> pPad2;
};
#endif //GAMES_BALL_H
