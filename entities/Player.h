//
// Created by insperias on 07.05.19.
//

#ifndef SDL_LEARN_PLAYER_H
#define SDL_LEARN_PLAYER_H


#include "Entity.h"

class Player : public Entity {
private:
    //Variables

    //Init func
    void initVariables();
    void initComponents();
public:
    Player(float x, float y, sf::Texture* texture);

    virtual ~Player();

    //Functions

};


#endif //SDL_LEARN_PLAYER_H
