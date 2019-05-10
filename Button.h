//
// Created by insperias on 04.05.19.
//

#ifndef SDL_LEARN_BUTTON_H
#define SDL_LEARN_BUTTON_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

enum button_states{BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE};

class Button {
private:
    short unsigned buttonState;

    bool pressed;
    bool hover;

    sf::RectangleShape shape;
    sf::Font* font;
    sf::Text text;

    sf::Color textIdleColor;
    sf::Color textHoverColor;
    sf::Color textActiveColor;

    sf::Color idleColor;
    sf::Color hoverColor;
    sf::Color activeColor;


public:
    Button(float x, float y, float width, float height, sf::Font* font,
            std::string text, unsigned character_size,
           sf::Color text_idle_color,  sf::Color text_hover_color, sf::Color text_active_color,
           sf::Color idle_color, sf::Color hover_color, sf::Color active_color);

    virtual ~Button();

    //Accessors
    const bool isPressed() const;

    //Functions
    void update(const sf::Vector2f mousePos);
    void render(sf::RenderTarget* target);
};


#endif //SDL_LEARN_BUTTON_H
