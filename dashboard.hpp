#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "car.hpp"

class Dashboard
{
    public:
    double xScreenPos;
    double yScreenPos;
    double x_tipOrigin;
    double y_tipOrigin;
    double x_gaugeOrigin;
    double y_gaugeOrigin;
    double tipAngle;
    double scale;
    double speed;
    double rpm;
    int gear;
    std::string gaugeTexturePath;
    std::string tipTexturePath;
    sf::Texture gaugeTexture;
    sf::Texture tipTexture;
    sf::Sprite spGauge;
    sf::Sprite spTip;

    void loadTexture();
    void setTexture();
    void setOrigins();
    void setScale(double);
    void setPosition(double, double);
    void setTipAngle();
    void readCarData(Car *);
    void showData();

    Dashboard(double xPos, double yPos, std::string idleGaugeTexturePath, std::string idleTipTexturePath, double idleScale)
    {
        gaugeTexturePath = idleGaugeTexturePath;
        tipTexturePath = idleTipTexturePath;
        x_tipOrigin = 264.87;
        y_tipOrigin = 35.88;
        x_gaugeOrigin = 0.0;
        y_gaugeOrigin = 0.0;
        xScreenPos = xPos;
        yScreenPos = yPos;
        tipAngle = -90.0;
        loadTexture();
        setTexture();
        setOrigins();
        //spGauge.setOrigin(x_gaugeOrigin, y_gaugeOrigin);
        //spTip.setOrigin(x_tipOrigin, y_tipOrigin);
        setPosition(xScreenPos, yScreenPos);
        setScale(idleScale);
    }
};
