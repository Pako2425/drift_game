#pragma once
#include <SFML/Graphics.hpp>

class Game
{
private:
    sf::RenderWindow* window;
    sf::View* view;
    sf::Event event;
    void initVariables();
    void initWindow();
    void initView();
public:
    Game();
    ~Game();
    bool isRunning();
    void updateEvents();
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