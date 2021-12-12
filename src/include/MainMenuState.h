//
// Created by valon.osmani on 07.12.2021.
//

#ifndef GAMES_MAINMENESTATE_H
#define GAMES_MAINMENESTATE_H

#include "Game.h"

class MainMenuState : public Gamestate
{
public:
    MainMenuState();
    ~MainMenuState();
    void HandleEvents(Game& game);
    void Update(Game& game);
    void Draw(Game& game);

private:
    bool bStartGameSelected;
    bool bQuitGameSelected;

    sf::Font font;
    sf::Text txtStartGame;
    sf::Text txtQuitGame;
};
#endif //GAMES_MAINMENESTATE_H
