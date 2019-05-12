//
// Created by insperias on 07.05.19.
//

#include "Player.h"

//Init func
void Player::initVariables() {

}

void Player::initComponents(sf::Texture& texture_sheet) {
    this->createHitboxComponent(this->sprite, 0.f, 0.f, 33.f, 33.f);
    this->createMovementComponent(300.f, 15.f, 5.f);
    this->createAnimationComponent(texture_sheet);
}

//Contructors/Destructors
Player::Player(float x, float y, sf::Texture& texture_sheet) {
    this->initVariables();

    this->setPosition(x,y);

    this->initComponents(texture_sheet);

    this->animationComponent->addAnimation("IDLE_DOWN", 10.f, 0, 0, 7, 0, 33, 33);
    this->animationComponent->addAnimation("WALK_UP", 7.f, 4, 0, 7, 4, 33, 33);
    this->animationComponent->addAnimation("WALK_LEFT", 7.f, 2, 0, 7, 2, 33, 33);
    this->animationComponent->addAnimation("WALK_RIGHT", 7.f, 3, 0, 7, 3, 33, 33);
    this->animationComponent->addAnimation("WALK_DOWN", 7.f, 1, 0, 7, 1, 33, 33);
}

Player::~Player() {

}

//Functions
void Player::update(const float &dt) {
    this->movementComponent->update(dt);

    if (this->movementComponent->getState(IDLE))
        this->animationComponent->play("IDLE_DOWN", dt);
    else if (this->movementComponent->getState(MOVING_LEFT))
    {
        this->animationComponent->play("WALK_LEFT", dt, this->movementComponent->getVelocity().x, this->movementComponent->getMaxVelocity());
    }
    else if (this->movementComponent->getState(MOVING_RIGHT))
    {
        this->animationComponent->play("WALK_RIGHT", dt, this->movementComponent->getVelocity().x, this->movementComponent->getMaxVelocity());
    }
    else if (this->movementComponent->getState(MOVING_DOWN))
    {
        this->animationComponent->play("WALK_DOWN", dt, this->movementComponent->getVelocity().y, this->movementComponent->getMaxVelocity());
    }
    else if (this->movementComponent->getState(MOVING_UP))
    {
        this->animationComponent->play("WALK_UP", dt, this->movementComponent->getVelocity().y, this->movementComponent->getMaxVelocity());
    }

this->hitboxComponent->update();

}
