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
    void initComponents(sf::Texture& texture_sheet);
public:
    Player(float x, float y, sf::Texture& texture_sheet);

    virtual ~Player();

    //Functions
    virtual void update(const float& dt);

};


#endif //SDL_LEARN_PLAYER_H
