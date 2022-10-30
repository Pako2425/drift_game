#pragma once
#include <SFML/Graphics.hpp>
#include <stack>
#include "State.hpp"

class Game
{
private:
    sf::RenderWindow* window;
    sf::Event event;

    sf::Clock dtClock;
    float dt;

    std::stack<State*> states;    

    void initVariables();
    void initWindow();
    void initStates();
    void initView();
    
public:
    Game();
    ~Game();
    bool isRunning();
    void updateSFMLEvents();
    void updateDt();
    void inputs();
    void update();
    void render();
    void run();

    void windowDraw(const sf::Sprite&) const;
};