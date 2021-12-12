//
// Created by valon.osmani on 09.12.2021.
//
// -- Preprocessor Directive
#ifndef GAMES_PLAYSTATE_H
#define GAMES_PLAYSTATE_H

#include "Game.h"
#include "Gamestate.h"
#include "Paddle.h"
#include "Ball.h"

class Playstate : public Gamestate{
public:
    Playstate();
    ~Playstate();

    void HandleEvents(Game& game);
    void Update(Game& game);
    void Draw(Game& game);

private:
    sf::Font font;
    sf::Text txtBackMenu;

    std::unique_ptr<Ball> upBall;
    std::shared_ptr<Paddle> spPad1;
    std::shared_ptr<Paddle> spPad2;
};
#endif //GAMES_PLAYSTATE_H
