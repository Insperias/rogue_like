//
// Created by insperias on 04.05.19.
//

#ifndef SDL_LEARN_ENTITY_H
#define SDL_LEARN_ENTITY_H

#include "/home/insperias/CLionProjects/rogue_like/components/MovementComponent.h"

class Entity {
private:
    void initVariables();

protected:

    sf::Sprite sprite;


    MovementComponent* movementComponent;

public:
    Entity();

    virtual ~Entity();

    //Component func
    void setTexture(sf::Texture& texture);
    void createMovementComponent(const float maxVelocity, const float acceleration, const float deceleration);

    //Functions
    virtual void setPosition(const float x, const float y);
    virtual void move(const float x, const float y, const float& dt);

    virtual void update(const float& dt);
    virtual void render(sf::RenderTarget* target);
};


#endif //SDL_LEARN_ENTITY_H
