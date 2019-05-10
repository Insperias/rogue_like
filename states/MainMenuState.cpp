//
// Created by insperias on 04.05.19.
//

#include "MainMenuState.h"

//Init func
void MainMenuState::initVariables() {

}

void MainMenuState::initBackground() {
    this->background.setSize(sf::Vector2f(static_cast<float>(this->window->getSize().x), static_cast<float>(this->window->getSize().y)));

    if(!this->backgroundTexture.loadFromFile("/home/insperias/CLionProjects/sdl_learn/resources/backgrounds/hh.jpg"))
    {
        throw "ERROR::MAIMENUSTATE::FAILED_TO_LOAD_BACKGRoUND_TEXTURE";
    }

    this->background.setTexture(&this->backgroundTexture);

}

void MainMenuState::initFonts() {
    if (!this->font.loadFromFile("/home/insperias/CLionProjects/sdl_learn/fonts/ADDSBP__.TTF"))
    {
        throw("ERROR::MAIN_MENU_STATE::COULD NOT LOAD FONT");
    }
}

void MainMenuState::initKeybinds() {
    std::ifstream ifs ("/home/insperias/CLionProjects/sdl_learn/config/mainmenustate_keybinds.ini");
    if(ifs.is_open())
    {
        std::string key;
        std::string key2;

        while (ifs >> key >> key2)
        {
            this->keybinds[key] = this->supportedKeys->at(key2);
        }
    }

    ifs.close();

}

void MainMenuState::initButtons() {
    this->buttons["GAME_STATE"] = new Button(300, 450, 250, 50,
            &this->font, "New Game", 50,
            sf::Color(70,70,70,200), sf::Color(250,250,250,250), sf::Color(20,20,20,50),
            sf::Color(70,70,70,0), sf::Color(150,150,150,0), sf::Color(20,20,20,0));

    this->buttons["SETTINGS"] = new Button(300, 570, 250, 50,
            &this->font, "Settins", 50,
            sf::Color(70,70,70,200), sf::Color(250,250,250,250), sf::Color(20,20,20,50),
            sf::Color(70,70,70,0), sf::Color(150,150,150,0), sf::Color(20,20,20,0));

    this->buttons["EDITOR_STATE"] = new Button(300, 690, 250, 50,
            &this->font, "Editor", 50,
            sf::Color(70,70,70,200), sf::Color(150,150,150,250), sf::Color(20,20,20,50),
            sf::Color(70,70,70,0), sf::Color(150,150,150,0), sf::Color(20,20,20,0));

    this->buttons["EXIT_STATE"] = new Button(300, 810, 250, 50,
            &this->font, "QuiT", 50,
            sf::Color(70,70,70,200), sf::Color(150,150,150,250), sf::Color(20,20,20,50),
            sf::Color(70,70,70,0), sf::Color(150,150,150,0), sf::Color(20,20,20,0));
}

MainMenuState::MainMenuState(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys,std::stack<State*>* states)
        : State(window,supportedKeys,states){
    this->initVariables();
    this->initBackground();
    this->initFonts();
    this->initKeybinds();
    this->initButtons();


}

MainMenuState::~MainMenuState() {
    auto it= this->buttons.begin();
    for (it= this->buttons.begin();it != this->buttons.end();++it)
    {
        delete it->second;
    }
}


void MainMenuState::updateInput(const float &dt) {


}

void MainMenuState::updateButtons() {
    //Update all buttons

    for (auto &it : this->buttons)
    {
        it.second->update(this->mousePosView);
    }

    //New Game
    if (this->buttons["GAME_STATE"]->isPressed())
    {
        this->states->push(new GameState(this->window, this->supportedKeys,this->states));
    }

    //Quit
    if (this->buttons["EXIT_STATE"]->isPressed())
    {
        this->endState();
    }
}

void MainMenuState::update(const float& dt) {
    this->updateMousePositions();
    this->updateInput(dt);

    this->updateButtons();



}

void MainMenuState::renderButtons(sf::RenderTarget *target) {
    for (auto &it : this->buttons)
    {
        it.second->render(target);
    }
}

void MainMenuState::render(sf::RenderTarget *target) {
    if (!target)
        target = this->window;
    target->draw(this->background);

    this->renderButtons(target);


}




