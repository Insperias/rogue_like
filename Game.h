//
// Created by insperias on 03.05.19.
//

#ifndef SDL_LEARN_GAME_H
#define SDL_LEARN_GAME_H

#include "states/MainMenuState.h"

class Game {
private:
//Variables
    sf::RenderWindow *window;
    sf::Event sfEvent;
    std::vector<sf::VideoMode> videoModes;
    sf::ContextSettings window_settings;
    bool fullscreen;

    sf::Clock dtClock;
    float dt;

    std::stack<State*> states;

    std::map<std::string,int> supportedKeys;

//Initialization
    void initVariables();
    void initWindow();
    void initKeys();
    void initStates();


public:
    //Constructors/Destructors
    Game();

    virtual ~Game();

    //Functions

    //Regular
    void endApplication();

    //Update
    void updateDT();
    void updateSFMLEvents();
    void update();


    //Render
    void render();


    //Core
    void run();
};


#endif //SDL_LEARN_GAME_H
