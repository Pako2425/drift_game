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
    const float& getAngle();
    //functions
    void move(const double dx, const double dy, const double dAngle);
    void rotate(const double dAngle);
    //update
    void update();
};
