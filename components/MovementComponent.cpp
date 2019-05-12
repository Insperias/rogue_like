//
// Created by insperias on 09.05.19.
//

#include "MovementComponent.h"

MovementComponent::MovementComponent(sf::Sprite& sprite,float maxVelocity,
        float acceleration, float deceleration)
    : sprite(sprite),maxVelocity(maxVelocity), acceleration(acceleration), deceleration(deceleration)
{

}

MovementComponent::~MovementComponent() {

}

//Accessors
const float &MovementComponent::getMaxVelocity() const {
    return this->maxVelocity;
}

const sf::Vector2f &MovementComponent::getVelocity() const {
    return this->velocity;
}

//Functions
const bool MovementComponent::getState(const short unsigned state) const {
    switch(state)
    {
        case IDLE:
            return (this->velocity.x == 0.f && this->velocity.y == 0.f);

            break;

        case MOVING:
            return (this->velocity.x != 0.f || this->velocity.y != 0.f);

            break;

        case MOVING_LEFT:
            return (this->velocity.x < 0.f);

            break;

        case MOVING_RIGHT:
            return (this->velocity.x > 0.f);

            break;

        case MOVING_UP:
            return (this->velocity.y < 0.f);

            break;

        case MOVING_DOWN:
            return (this->velocity.y > 0.f);

            break;

        default:
            break;
    }
}

void MovementComponent::move(const float dir_x, const float dir_y, const float& dt) {
    //Acceleration

    this->velocity.x += this->acceleration*dir_x;
    this->velocity.y += this->acceleration*dir_y;
}

void MovementComponent::update(const float &dt) {
    /*Decelerates the sprite and contol the max velocity.
      Move the sprite*/

    if(this->velocity.x > 0.f)//Check for positive x
    {
        //Max velocity check x positive
        if (this->velocity.x > this->maxVelocity)
            this->velocity.x = this->maxVelocity;


        //Deceleration x positive
        this->velocity.x -= deceleration;
        if(this->velocity.x < 0.f)
            this->velocity.x = 0.f;
    }
    else if(this->velocity.x < 0.f)//Check for negative x
    {
        //Max velocity check x negative
        if (this->velocity.x < -this->maxVelocity)
            this->velocity.x = -this->maxVelocity;

        //Deceleration x negative
        this->velocity.x += deceleration;
        if(this->velocity.x > 0.f)
            this->velocity.x = 0.f;
    }

    if(this->velocity.y > 0.f)//Check for positive y
    {
        //Max velocity check y positive
        if (this->velocity.y > this->maxVelocity)
            this->velocity.y = this->maxVelocity;


        //Deceleration y positive
        this->velocity.y -= deceleration;
        if(this->velocity.y < 0.f)
            this->velocity.y = 0.f;
    }
    else if(this->velocity.y < 0.f)//Check for negative y
    {
        //Max velocity check y negative
        if (this->velocity.y < -this->maxVelocity)
            this->velocity.y = -this->maxVelocity;

        //Deceleration y negative
        this->velocity.y += deceleration;
        if(this->velocity.y > 0.f)
            this->velocity.y = 0.f;
    }

    //Final move
    this->sprite.move(this->velocity * dt);//Use velocity
}


