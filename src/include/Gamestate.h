//
// Created by valon.osmani on 07.12.2021.
//

#ifndef GAMES_GAMESTATE_H
#define GAMES_GAMESTATE_H

class Game; // Vorwärtsdeklaration - damit diese classe hier bekannt ist

class Gamestate
{
public:
    virtual void HandleEvents(Game& game) = 0;
    virtual void Update(Game& game) = 0;
    virtual void Draw(Game& game) = 0;
    virtual ~Gamestate() {};
};


#endif //GAMES_GAMESTATE_H
