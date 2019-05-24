//
// Created by insperias on 25.05.19.
//

#include "PauseMenuState.h"

PauseMenuState::PauseMenuState(sf::RenderWindow& window) {
    //Init background
    this->background.setSize(sf::Vector2f(static_cast<float>(window.getSize().x),
            static_cast<float>(window.getSize().y)));
    this->background.setFillColor(sf::Color(20, 20, 20, 100));

    //Init container
    this->container.setSize(sf::Vector2f(static_cast<float>(window.getSize().x / 4.f),
            static_cast<float>(window.getSize().y)-50.f));
    this->container.setFillColor(sf::Color(20, 20, 20, 200));
    this->container.setPosition(static_cast<float>(window.getSize().x) / 2.f, 30.f);

}

PauseMenuState::~PauseMenuState() {
    auto it= this->buttons.begin();
    for (it= this->buttons.begin();it != this->buttons.end();++it)
    {
        delete it->second;
    }
}

//Functions

void PauseMenuState::update() {

}

void PauseMenuState::render(sf::RenderTarget &target) {
    target.draw(this->background);
    target.draw(this->container);


    for (auto &it : this->buttons)
    {
        it.second->render(target);
    }
}

