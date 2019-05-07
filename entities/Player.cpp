//
// Created by insperias on 07.05.19.
//

#include "Player.h"

//Init func
void Player::initVariables() {

}

void Player::initComponents() {

}

//Contructors/Destructors
Player::Player(float x, float y, sf::Texture* texture) {
    this->initVariables();
    this->initComponents();

    this->createSprite(texture);
    this->setPosition(x,y);
}

Player::~Player() {

}