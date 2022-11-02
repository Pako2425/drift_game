#pragma once
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Player.hpp"

class Game_State : public State
{
private:
    sf::View view;
    Player* player;

    void initVariables();
    void initKeybinds();   //funkcja która inicjalizuje klawisze do wciśnięcia; do napisania
    void initTextures();   //inicjalizuje zasoby textur
public:
    Game_State(sf::RenderWindow* window);
    ~Game_State();

    void updatePlayer();
    void updateView();

    void endState();
    void input();
    void update(const float& dt);
    void render(sf::RenderTarget* target = nullptr);
};
