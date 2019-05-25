//
// Created by insperias on 25.05.19.
//

#include "PauseMenuState.h"

PauseMenuState::PauseMenuState(sf::RenderWindow& window, sf::Font& font)
    :font(font){
    //Init background
    this->background.setSize(sf::Vector2f(static_cast<float>(window.getSize().x),
            static_cast<float>(window.getSize().y)));
    this->background.setFillColor(sf::Color(20, 20, 20, 100));

    //Init container
    this->container.setSize(sf::Vector2f(static_cast<float>(window.getSize().x / 4.f),
            static_cast<float>(window.getSize().y)-100.f));
    this->container.setFillColor(sf::Color(20, 20, 20, 200));
    this->container.setPosition(static_cast<float>(window.getSize().x) / 2.f, 30.f);

    //Init text
    this->menuText.setFont(font);
    this->menuText.setFillColor(sf::Color(255, 255, 255, 200));
    this->menuText.setCharacterSize(30);
    this->menuText.setString("PAUSED");
    this->menuText.setPosition(this->container.getPosition().x + this->container.getSize().x / 2.f - this->menuText.getGlobalBounds().width / 2.f,
            this->container.getPosition().y + 30.f);
}

PauseMenuState::~PauseMenuState() {
    auto it= this->buttons.begin();
    for (it= this->buttons.begin();it != this->buttons.end();++it)
    {
        delete it->second;
    }
}

//Accessors
std::map<std::string, Button *> &PauseMenuState::getButtons() {
    return this->buttons;
}


//Functions

const bool PauseMenuState::isButtonPressed(const std::string key) {
    return this->buttons[key]->isPressed();
}

void PauseMenuState::addButton(const std::string key, float y, const std::string text) {
    float width = 250.f;
    float height = 50.f;
    float x = this->container.getPosition().x + this->container.getSize().x / 2.f - width / 2.f;

    this->buttons[key] = new Button(x, y, width, height,
            &this->font, text, 50,
            sf::Color(70,70,70,200), sf::Color(250,250,250,250), sf::Color(20,20,20,50),
            sf::Color(70,70,70,0), sf::Color(150,150,150,0), sf::Color(20,20,20,0));
}

void PauseMenuState::update(const sf::Vector2f& mousePosition) {
    for (auto &i : this->buttons)
    {
        i.second->update(mousePosition);
    }
}

void PauseMenuState::render(sf::RenderTarget &target) {
    target.draw(this->background);
    target.draw(this->container);


    for (auto &it : this->buttons)
    {
        it.second->render(target);
    }

    target.draw(this->menuText);
}





