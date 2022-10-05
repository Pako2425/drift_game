#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "steering_wheel.hpp"
#include "dashboard.hpp"

class GameHud
{
    SteeringWheel hudSteeringWheel;

    GameHud()
    {
        SteeringWheel hudSteeringWheel(200.0, 800.0, 0.0, "images/hud/steering_wheel.png");
    }
};
