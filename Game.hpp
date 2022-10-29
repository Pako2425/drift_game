#pragma once
#include <SFML/Graphics.hpp>

class Game
{
private:
    sf::RenderWindow* window;
    sf::View* view;
    sf::Event event;

    sf::Clock dtClock;
    float dt;

    void initVariables();
    void initWindow();
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

    void setView();
    void setCenter(const double, const double);
    void setRotation(const double);
    void windowClear();
    void windowDraw(const sf::Sprite&) const;
    void windowDisplay();
};