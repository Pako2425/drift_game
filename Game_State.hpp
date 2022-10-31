#pragma once
#include "State.hpp"

class Game_State : public State
{
private:

public:
    Game_State(sf::RenderWindow* window);
    ~Game_State();
    void endState();
    void update(const float& dt);
    void render(sf::RenderTarget* target = nullptr);
};
