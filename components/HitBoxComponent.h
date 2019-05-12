//
// Created by insperias on 11.05.19.
//

#ifndef ROGUE_LIKE_HITBOXCOMPONENT_H
#define ROGUE_LIKE_HITBOXCOMPONENT_H

#include <iostream>
#include <ctime>
#include <cstdlib>


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

class HitBoxComponent {
private:
    sf::Sprite& sprite;
    sf::RectangleShape hitbox;
    float offsetX;
    float offsetY;

public:
    HitBoxComponent(sf::Sprite& sprite,
            float offset_x, float offset_y, float width, float height);
    virtual ~HitBoxComponent();

    //Functions
    bool checkIntersect(const sf::FloatRect& frect);
    void update();
    void render(sf::RenderTarget& target);
};


#endif //ROGUE_LIKE_HITBOXCOMPONENT_H
