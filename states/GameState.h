//
// Created by insperias on 04.05.19.
//

#ifndef SDL_LEARN_GAMESTATE_H
#define SDL_LEARN_GAMESTATE_H



#include "State.h"
#include "../GUI/PauseMenuState.h"

class GameState : public State {
private:
    PauseMenuState pmenu;

    Player* player;


    //Functions
    void initKeybinds() override;
    void initTextures();
    void initPlayers();

public:
    GameState(sf::RenderWindow* window,std::map<std::string,int>* supportedKeys,std::stack<State*>* states);

    virtual ~GameState();

    //Functions

    void updateInput(const float& dt) override;
    void update(const float& dt) override;
    void render(sf::RenderTarget* target = nullptr) override;

};


#endif //SDL_LEARN_GAMESTATE_H
