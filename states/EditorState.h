//
// Created by insperias on 11.05.19.
//

#ifndef ROGUE_LIKE_EDITORSTATE_H
#define ROGUE_LIKE_EDITORSTATE_H


#include "State.h"
#include "/home/insperias/CLionProjects/rogue_like/Button.h"

class EditorState : public State {
    //Variables

    sf::Font font;


    std::map<std::string, Button*> buttons;

    //Functions
    void initVariables();
    void initBackground();
    void initFonts();
    void initKeybinds() override;
    void initButtons();
public:
    EditorState(sf::RenderWindow* window,std::map<std::string,int>* supportedKeys,std::stack<State*>* states);

    virtual ~EditorState();

    //Functions

    void updateInput(const float& dt) override;
    void updateButtons();
    void update(const float& dt) override;
    void renderButtons(sf::RenderTarget& target);
    void render(sf::RenderTarget* target = nullptr) override;
};


#endif //ROGUE_LIKE_EDITORSTATE_H
