//
// Created by insperias on 03.05.19.
//

#include "Game.h"

//Static functions



//Init functions

void Game::initVariables() {
    this->window = nullptr;
    this->fullscreen = false;
    this->dt = 0.f;
}

void Game::initWindow() {
    //Create SFML window,options in window.ini

    std::ifstream ifs("/home/insperias/CLionProjects/rogue_like/config/window.ini");
    this->videoModes = sf::VideoMode::getFullscreenModes();



    std::string title = "None";
    sf::VideoMode window_bounds = sf::VideoMode::getDesktopMode();
    bool fullscreen = false;
    unsigned framerate_limit = 120;
    bool vertical_sync_enabled = false;
    unsigned antialiasing_level = 0;

    if (ifs.is_open())
    {
        std::getline(ifs,title);
        ifs >> window_bounds.width >> window_bounds.height;
        ifs >> fullscreen;
        ifs >> framerate_limit;
        ifs >> vertical_sync_enabled;
        ifs >> antialiasing_level;
    }

    ifs.close();

    this->fullscreen=fullscreen;
    this->window_settings.antialiasingLevel=antialiasing_level;

    if (this->fullscreen)
        this->window = new sf::RenderWindow(window_bounds,title,sf::Style::Fullscreen, window_settings);
    else
        this->window = new sf::RenderWindow(window_bounds,title,sf::Style::Titlebar | sf::Style::Close, window_settings);

    this->window->setFramerateLimit(framerate_limit);
    this->window->setVerticalSyncEnabled(vertical_sync_enabled);

}

void Game::initKeys() {
    std::ifstream ifs ("/home/insperias/CLionProjects/rogue_like/config/supported_keys.ini");
    if(ifs.is_open())
    {
        std::string key = "";
        int key_value = 0;

        while (ifs >> key >> key_value)
        {
            this->supportedKeys[key] = key_value;
        }
    }
    ifs.close();
}

void Game::initStates() {
    this->states.push(new MainMenuState(this->window, &this->supportedKeys, &this->states));
}



//Constructors/destructors
Game::Game() {
    this->initVariables();
    this->initWindow();
    this->initKeys();
    this->initStates();

}

Game::~Game() {
    delete this->window;

    while (!this->states.empty())
    {
        delete this->states.top();
        this->states.pop();
    }
}



//Functions

void Game::endApplication() {

}

void Game::updateDT() {
    this->dt = this->dtClock.restart().asSeconds();


}

void Game::updateSFMLEvents() {
    while (this->window->pollEvent(this->sfEvent))
    {

            if (this->sfEvent.type == sf::Event::Closed)
                this->window->close();
    }
}

void Game::update() {
    this->updateSFMLEvents();

    if (!this->states.empty())
    {
        this->states.top()->update(this->dt);
        if (this->states.top()->getQuit())
        {
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    }

    //Application end
    else
    {
        this->endApplication();
        this->window->close();
    }

}

void Game::render() {
    this->window->clear();

    //Render items
    if (!this->states.empty())
        this->states.top()->render(this->window);

    this->window->display();
}

void Game::run() {
    while (this->window->isOpen())
    {
        this->updateDT();
        this->update();
        this->render();
    }
}



