//
// Created by insperias on 11.05.19.
//

#include "EditorState.h"

//Init func
void EditorState::initVariables() {

}

void EditorState::initBackground() {


}

void EditorState::initFonts() {
    if (!this->font.loadFromFile("/home/insperias/CLionProjects/rogue_like/fonts/ADDSBP__.TTF"))
    {
        throw("ERROR::EDITOR_STATE::COULD NOT LOAD FONT");
    }
}

void EditorState::initKeybinds() {
    std::ifstream ifs ("/home/insperias/CLionProjects/rogue_like/config/editorstate_keybinds.ini");
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

void EditorState::initButtons() {

}

EditorState::EditorState(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys,std::stack<State*>* states)
        : State(window,supportedKeys,states){
    this->initVariables();
    this->initBackground();
    this->initFonts();
    this->initKeybinds();
    this->initButtons();


}

EditorState::~EditorState() {
    auto it= this->buttons.begin();
    for (it= this->buttons.begin();it != this->buttons.end();++it)
    {
        delete it->second;
    }
}


void EditorState::updateInput(const float &dt) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))))
        this->endState();

}

void EditorState::updateButtons() {
    //Update all buttons

    for (auto &it : this->buttons)
    {
        it.second->update(this->mousePosView);
    }

}

void EditorState::update(const float& dt) {
    this->updateMousePositions();
    this->updateInput(dt);

    this->updateButtons();



}

void EditorState::renderButtons(sf::RenderTarget& target) {
    for (auto &it : this->buttons)
    {
        it.second->render(target);
    }
}

void EditorState::render(sf::RenderTarget *target) {
    if (!target)
        target = this->window;

    this->renderButtons(*target);


}