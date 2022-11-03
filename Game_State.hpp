#pragma once
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Player.hpp"
#include "TrackMap.hpp"

class Game_State : public State
{
private:
    sf::View view;
    Player* player;
    TrackMap* trackMap;
    
    bool gasPedal;
    bool brakePedal;
    bool steerLeft;
    bool steerRight;

    double dt;
    double turningRadius;
    double dCarRotationAngle;
    double newCarAngle;
    double newCarXPos;
    double newCarYPos;
    
    void initVariables();
    void initPlayerSpriteComponent();
    void initKeybinds();   //funkcja która inicjalizuje klawisze do wciśnięcia; do napisania
    void initTextures();   //inicjalizuje zasoby textur

    void calculateRadiusOfCarTurningCircle();
    void calculateCarRotationAngle();
    void calculateNewCarAngle();
    void calculateNewCarPosition();
public:
    Game_State(sf::RenderWindow* window);
    ~Game_State();

    void updatePlayer();
    void updateTrackMap();
    void updateView();

    void endState();        //funckja wychodząca i kończąca obecny State, do napisania
    void input();
    void update(const float& dt);
    void render(sf::RenderTarget* target = nullptr);
};
