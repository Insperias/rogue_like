//
// Created by insperias on 03.05.19.
//

#include "State.h"

State::State(sf::RenderWindow* window, std::map<std::string,int>* supportedKeys,std::stack<State*>* states) {
    this->window=window;
    this->supportedKeys = supportedKeys;
    this->states = states;
    this->quit= false;
}

State::~State() {

}

const bool &State::getQuit() const {
    return this->quit;
}

void State::endState() {
    this->quit = true;
}

void State::pauseState() {
    this->paused = true;
}

void State::unpauseState() {
    this->paused = false;
}

void State::updateMousePositions() {
    this->mousePosScreen = sf::Mouse::getPosition();
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}





