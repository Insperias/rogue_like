//
// Created by insperias on 04.05.19.
//

#ifndef SDL_LEARN_ENTITY_H
#define SDL_LEARN_ENTITY_H

#include "/home/insperias/CLionProjects/rogue_like/components/HitBoxComponent.h"
#include "/home/insperias/CLionProjects/rogue_like/components/MovementComponent.h"
#include "/home/insperias/CLionProjects/rogue_like/components/AnimationComponent.h"

class Entity {
private:
    void initVariables();

protected:

    sf::Sprite sprite;

    HitBoxComponent* hitboxComponent;
    MovementComponent* movementComponent;
    AnimationComponent* animationComponent;

public:
    Entity();

    virtual ~Entity();

    //Component func
    void setTexture(sf::Texture& texture);
    void createHitboxComponent(sf::Sprite& sprite,
            float offset_x, float offset_y, float width, float height);
    void createMovementComponent(const float maxVelocity, const float acceleration, const float deceleration);
    void createAnimationComponent(sf::Texture& texture_sheet);

    //Functions
    virtual void setPosition(const float x, const float y);
    virtual void move(const float x, const float y, const float& dt);

    virtual void update(const float& dt);
    virtual void render(sf::RenderTarget& target);
};


#endif //SDL_LEARN_ENTITY_H
