//
// Created by valon.osmani on 09.12.2021.
//

#include "../include/Paddle.h"

Paddle::Paddle(sf::Vector2f rect, sf::Color col, sf::Vector2f pos) {
    setSize(rect);
    setFillColor(col);
    setOrigin(getSize().x / 2, getSize().y /2);
    setPosition(pos);

    initPos = pos;
    speed = 1000.f;
}

void Paddle::init() {
    setPosition(initPos);
}

void Paddle::setKeyUp(sf::Keyboard::Key k) {
    Up = k;
}

void Paddle::setKeyDown(sf::Keyboard::Key k) {
    Down = k;
}

void Paddle::Update(sf::RenderWindow &pWindow, sf::Time elapsed) {
    // tempElapsedTime += elapsed;

    if (sf::Keyboard::isKeyPressed(Up) && getPosition().y > getGlobalBounds().height / 2)
    {
        move(sf::Vector2f(0.f, -speed * elapsed.asSeconds()));
    } else if (sf::Keyboard::isKeyPressed(Down) && getPosition().y < (pWindow.getSize().y - getGlobalBounds().height / 2))
    {
        move(sf::Vector2f(0.f, speed * elapsed.asSeconds()));
    }
}