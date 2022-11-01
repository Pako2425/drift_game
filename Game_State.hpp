#pragma once
#include "State.hpp"

class Game_State : public State
{
private:
    void initKeybinds();   //funkcja która inicjalizuje klawisze do wciśnięcia; do napisania
    void initTextures();   //inicjalizuje zasoby textur
public:
    Game_State(sf::RenderWindow* window);
    ~Game_State();
    void endState();
    void input();
    void update(const float& dt);
    void render(sf::RenderTarget* target = nullptr);
};
