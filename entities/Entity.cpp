//
// Created by insperias on 04.05.19.
//

#include "Entity.h"

void Entity::initVariables() {

    this->movementComponent = nullptr;
}

Entity::Entity() {
    this->initVariables();
}

Entity::~Entity() {

}

//Component func
void Entity::setTexture(sf::Texture& texture) {

    this->sprite.setTexture(texture);
}

void Entity::createMovementComponent(const float maxVelocity) {
    this->movementComponent = new MovementComponent(this->sprite, maxVelocity);
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
    if (this->movementComponent)
        this->movementComponent->update(dt);
}

void Entity::render(sf::RenderTarget* target) {
        target->draw(this->sprite);
}







