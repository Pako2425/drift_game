#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Dashboard
{
    public:
    double xPos;
    double yPos;
    double angle;
    double x_tipOrigin;
    double y_tipOrigin;
    double x_gaugeOrigin;
    double y_gaugeOrigin;
    double gaugeScale;
    double tipScale;
    std::string gaugeTexturePath;
    std::string tipTexturePath;
    sf::Texture gaugeTexture;
    sf::Texture tipTexture;
    sf::Sprite spGauge;
    sf::Sprite spTip;

    void loadTexture();
    void setTexture();
    void setOrigin();
    void setScale(double);
    void setPosition(double, double);
    void setTipAngle(double);

    Dashboard(double scale)
    {
        x_tipOrigin = 264.87;
        y_tipOrigin = 35.88;
        x_gaugeOrigin = 0;
        y_gaugeOrigin = 0;
        gaugeScale = scale;
        tipScale = scale;
        loadTexture();
        setTexture();
        spGauge.setOrigin(x_gaugeOrigin, y_gaugeOrigin);
        spTip.setOrigin(x_tipOrigin, y_tipOrigin);
    }
};
