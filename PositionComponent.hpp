#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class PositionComponent
{
private:
    sf::Vector2f xyPos;
    double angle;

public:
    PositionComponent(double xPos, double yPos, double angle);
    ~PositionComponent();
    //accesors
    const sf::Vector2f& getPosition();
    const double& getAngle();
    //functions
    void move(const double dx, const double dy, const double dAngle);
    //update
    //void update();
};
