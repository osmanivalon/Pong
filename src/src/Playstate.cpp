//
// Created by valon.osmani on 09.12.2021.
//

#include "../include/Playstate.h"

Playstate::Playstate() {
    spPad1 = std::make_shared<Paddle>(sf::Vector2f(53.f, 192.f), sf::Color::Blue, sf::Vector2f(30.f, 310.f));
    spPad2 = std::make_shared<Paddle>(sf::Vector2f(53.f, 192.f), sf::Color::Red, sf::Vector2f(1250.f, 310.f));

    upBall = std::unique_ptr<Ball>(new Ball(20.f, sf::Color::Magenta, sf::Vector2f(640.f, 310.f), spPad1, spPad2));

    spPad1->setKeyUp(sf::Keyboard::W);
    spPad1->setKeyDown(sf::Keyboard::S);

    spPad2->setKeyUp(sf::Keyboard::Up);
    spPad2->setKeyDown(sf::Keyboard::Down);


    font.loadFromFile("../assets/fnt/BRLNSR.TTF");
    txtBackMenu.setFont(font);
    txtBackMenu.setString("<< Back");
    txtBackMenu.setCharacterSize(30);
    txtBackMenu.setPosition(1100.f, 570.f);
}

void Playstate::HandleEvents(Game &game) {
    sf::Event event;

    while (game.window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) {
            game.window.close();
            game.running = false;
        }
        if (event.type == sf::Event::MouseButtonReleased) {
            if (event.mouseButton.button == 0) {

                if (txtBackMenu.getGlobalBounds().contains(
                        sf::Mouse::getPosition(game.window).x,
                        sf::Mouse::getPosition(game.window).y)){
                    game.changeState(Game::gameState::MAINMENU);
                }
            }
        }

        if (event.type == sf::Event::KeyReleased)
        {
            if (event.key.code == sf::Keyboard::Space){
                upBall->init();
            }
        }
    }
}

void Playstate::Update(Game &game) {

    upBall->Update(game.window, game.frameDeltaTime);
    spPad1->Update(game.window, game.frameDeltaTime);
    spPad2->Update(game.window, game.frameDeltaTime);

    if (txtBackMenu.getGlobalBounds().contains(
            sf::Mouse::getPosition(game.window).x,
            sf::Mouse::getPosition(game.window).y) &&
            txtBackMenu.getColor() != sf::Color::Green)
    {
        txtBackMenu.setColor(sf::Color::Green);
    }else if (!txtBackMenu.getGlobalBounds().contains(
            sf::Mouse::getPosition(game.window).x,
            sf::Mouse::getPosition(game.window).y) &&
            txtBackMenu.getColor() == sf::Color::Green){
        txtBackMenu.setColor(sf::Color::White);
    }


}

void Playstate::Draw(Game &game) {
    game.window.draw(*upBall);
    game.window.draw(*spPad1);
    game.window.draw(*spPad2);
    game.window.draw(txtBackMenu);
}

Playstate::~Playstate() noexcept {
    std::cout << "Playstate   -> destroyed" << std::endl;
}