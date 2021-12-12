//
// Created by valon.osmani on 10.12.2021.
//
#include "../include/Ball.h"

Ball::Ball(float rad, sf::Color col, sf::Vector2f pos, std::shared_ptr<Paddle> pad1, std::shared_ptr<Paddle> pad2) {
    setRadius(rad);
    setFillColor(col);
    setOrigin(getRadius() / 2, getRadius() / 2);
    setPosition(pos);

    pPad1 = pad1;
    pPad2 = pad2;

    direction = 1;
    speed = 0.f;
    movement = sf::Vector2f (0.f, 0.f);
}

void Ball::init() {
    speed = 300.f;
    direction = rand() % 2;

    if (direction == 0)
        movement = sf::Vector2f(speed, 0.f);
    else
        movement = sf::Vector2f(-speed, 0.f);

    setPosition(640.f, 310.f);
}

void Ball::Update(sf::RenderWindow &pWindow, sf::Time elapsed) {
    float  bX = getPosition().x;  // Ball X
    float  bY = getPosition().y;  // Ball Y

    sf::Vector2f p1p = pPad1->getPosition();
    sf::Vector2f p2p = pPad2->getPosition();

    // Fliegt der Ball gegen die horizontale Grenzen
    if (bY <= speed)
        movement.y = speed;
    else if (bY >= pWindow.getSize().y)
        movement.y = -speed;

    // Fliegt der Ball gegen den linken Schlaeger
    if (getGlobalBounds().left < p1p.x + (pPad1->getSize().x / 2 ) &&
        getGlobalBounds().left + getGlobalBounds().width > p1p.x - (pPad1->getSize().x / 2) &&
        getGlobalBounds().top + getGlobalBounds().height >= p1p.y - (pPad1->getSize().y / 2) &&
        getGlobalBounds().top <= p1p.y + (pPad1->getSize().x / 2))
    {
        setFillColor(pPad1->getFillColor());

        // oben unten oder mitte?
        if (bY < p1p.y){
            movement.x = speed;
            movement.y = -speed;
        } else if (bY > p1p.y){
            movement.x = speed;
            movement.y = speed;
        } else {
            movement.x = speed;
        }
    } // rechte schlaeger
    else if (getGlobalBounds().left < p2p.x + (pPad2->getSize().x / 2 ) &&
           getGlobalBounds().left + getGlobalBounds().width > p2p.x - (pPad2->getSize().x / 2) &&
           getGlobalBounds().top + getGlobalBounds().height >= p2p.y - (pPad2->getSize().x / 2) &&
           getGlobalBounds().top <= p2p.y + (pPad2->getSize().x / 2))
    {
        setFillColor(pPad2->getFillColor());

        // oben unten oder mitte?
        if (bY < p2p.y){
            movement.x = -speed;
            movement.y = -speed;
        } else if (bY > p2p.y){
            movement.x = -speed;
            movement.y = speed;
        } else {
            movement.x = -speed;
        }
    }

    move(movement.x * elapsed.asSeconds(), movement.y * elapsed.asSeconds());

}
