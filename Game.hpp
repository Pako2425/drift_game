#pragma once

#include <SFML/Graphics.hpp>

class Game
{
public:
    sf::RenderWindow* window;
    sf::Event sfEvent;
    double dt;

    void initVariables();
    void initWindow();

public:
    void update();
    void render();
    bool running();
    void updateEvents();

    Game();
    ~Game();
};