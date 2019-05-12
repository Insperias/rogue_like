//
// Created by insperias on 04.05.19.
//

#ifndef SDL_LEARN_MAINMENUSTATE_H
#define SDL_LEARN_MAINMENUSTATE_H


#include "GameState.h"
#include "EditorState.h"
#include "/home/insperias/CLionProjects/sdl_learn/Button.h"

class MainMenuState : public State{
private:
    //Variables
    sf::Texture backgroundTexture;
    sf::RectangleShape background;
    sf::Font font;


    std::map<std::string, Button*> buttons;

    //Functions
    void initVariables();
    void initBackground();
    void initFonts();
    void initKeybinds() override;
    void initButtons();
public:
    MainMenuState(sf::RenderWindow* window,std::map<std::string,int>* supportedKeys,std::stack<State*>* states);

    virtual ~MainMenuState();

    //Functions

    void updateInput(const float& dt) override;
    void updateButtons();
    void update(const float& dt) override;
    void renderButtons(sf::RenderTarget& target);
    void render(sf::RenderTarget* target = nullptr) override;
};


#endif //SDL_LEARN_MAINMENUSTATE_H
