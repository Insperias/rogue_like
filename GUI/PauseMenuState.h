//
// Created by insperias on 25.05.19.
//

#ifndef ROGUE_LIKE_PAUSEMENUSTATE_H
#define ROGUE_LIKE_PAUSEMENUSTATE_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <map>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "../Button.h"

class PauseMenuState {
private:
    sf::RectangleShape background;
    sf::RectangleShape container;

    std::map<std::string, Button*> buttons;

public:
    PauseMenuState(sf::RenderWindow& window);

    virtual ~PauseMenuState();

    //Functions
    void update();
    void render(sf::RenderTarget& target);
};


#endif //ROGUE_LIKE_PAUSEMENUSTATE_H
