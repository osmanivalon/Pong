//
// Created by valon.osmani on 07.12.2021.
//

#include "../include/MainMenuState.h"

MainMenuState::MainMenuState() {
    font.loadFromFile("../assets/fnt/BRLNSR.TTF");

    txtStartGame.setFont(font);
    txtStartGame.setString("Start Game");
    txtStartGame.setCharacterSize(30);
    txtStartGame.setPosition(400.f, 500.f);

    txtQuitGame.setFont(font);
    txtQuitGame.setString("Quit Game");
    txtQuitGame.setCharacterSize(30);
    txtQuitGame.setPosition(600.f, 500.f);
}

void MainMenuState::HandleEvents(Game &game) {
    sf::Event event;

    while (game.window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed){
            game.window.close();
            game.running = false;
        }

        if (event.type == sf::Event::MouseButtonReleased){
            if (event.mouseButton.button == 0){
                if (txtStartGame.getGlobalBounds().contains(
                        sf::Mouse::getPosition(game.window).x,
                        sf::Mouse::getPosition(game.window).y))
                {
                    game.changeState(Game::gameState::PLAY);
                } else if (txtQuitGame.getGlobalBounds().contains(
                        sf::Mouse::getPosition(game.window).x,
                        sf::Mouse::getPosition(game.window).y))
                {
                    game.window.close();
                    game.running = false;
                }
            }
        }
    }
}

void MainMenuState::Update(Game &game) {

    if (txtStartGame.getGlobalBounds().contains(
            sf::Mouse::getPosition(game.window).x,
            sf::Mouse::getPosition(game.window).y) &&
            txtStartGame.getColor() != sf::Color::Green)
    {
        txtStartGame.setColor(sf::Color::Green);
        bStartGameSelected = true;
    }else if (!txtStartGame.getGlobalBounds().contains(
            sf::Mouse::getPosition(game.window).x,
            sf::Mouse::getPosition(game.window).y) &&
              txtStartGame.getColor() == sf::Color::Green){
        txtStartGame.setColor(sf::Color::White);
        bStartGameSelected = false;
    }

    if (txtQuitGame.getGlobalBounds().contains(
            sf::Mouse::getPosition(game.window).x,
            sf::Mouse::getPosition(game.window).y) &&
            txtQuitGame.getColor() != sf::Color::Green)
    {
        txtQuitGame.setColor(sf::Color::Green);
        bStartGameSelected = true;
    }else if (!txtQuitGame.getGlobalBounds().contains(
            sf::Mouse::getPosition(game.window).x,
            sf::Mouse::getPosition(game.window).y) &&
            txtQuitGame.getColor() == sf::Color::Green){
        txtQuitGame.setColor(sf::Color::White);
        bQuitGameSelected = false;
    }
}

void MainMenuState::Draw(Game &game) {
    game.window.draw(txtStartGame);
    game.window.draw(txtQuitGame);
}

MainMenuState::~MainMenuState() noexcept {
    std::cout << "MainMenuState -> destroyed" << std::endl;
}