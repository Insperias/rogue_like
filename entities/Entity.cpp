//
// Created by insperias on 04.05.19.
//

#include "Entity.h"

void Entity::initVariables() {

    this->movementComponent = nullptr;
    this->animationComponent = nullptr;
    this->hitboxComponent = nullptr;
}

Entity::Entity() {
    this->initVariables();
}

Entity::~Entity() {
    delete this->movementComponent;
    delete this->animationComponent;
    delete this->hitboxComponent;
}

//Component func
void Entity::setTexture(sf::Texture& texture) {

    this->sprite.setTexture(texture);
}

void Entity::createHitboxComponent(sf::Sprite& sprite,
        float offset_x, float offset_y, float width, float height) {
    this->hitboxComponent = new HitBoxComponent(sprite, offset_x, offset_y, width, height);
}

void Entity::createMovementComponent(const float maxVelocity, const float acceleration, const float deceleration) {
    this->movementComponent = new MovementComponent(this->sprite, maxVelocity, acceleration, deceleration);
}

void Entity::createAnimationComponent(sf::Texture &texture_sheet) {
    this->animationComponent = new AnimationComponent(this->sprite, texture_sheet);
}

//Functions
void Entity::setPosition(const float x, const float y) {
        this->sprite.setPosition(x,y);
}

void Entity::move(const float dir_x, const float dir_y, const float& dt) {
    if (this->movementComponent) {
        this->movementComponent->move(dir_x, dir_y, dt);//Set velocity

    }
}

void Entity::update(const float &dt) {

}

void Entity::render(sf::RenderTarget& target) {
        target.draw(this->sprite);

        if(this->hitboxComponent)
            this->hitboxComponent->render(target);
}











