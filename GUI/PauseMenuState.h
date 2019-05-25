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
    sf::Font& font;
    sf::Text menuText;
    sf::RectangleShape background;
    sf::RectangleShape container;

    std::map<std::string, Button*> buttons;

    //Functions


public:
    PauseMenuState(sf::RenderWindow& window, sf::Font& font);

    virtual ~PauseMenuState();

    //Accessors
    std::map<std::string, Button*>& getButtons();

    //Functions
    const bool isButtonPressed(const std::string key);
    void addButton(const std::string key, float y, const std::string text);
    void update(const sf::Vector2f& mousePosition);
    void render(sf::RenderTarget& target);
};


#endif //ROGUE_LIKE_PAUSEMENUSTATE_H
