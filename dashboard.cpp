#include "dashboard.hpp"

void Dashboard::loadTexture()
{
    this->gaugeTexture.loadFromFile(this->gaugeTexturePath);
    this->tipTexture.loadFromFile(this->tipTexturePath);
}

void Dashboard::setTexture()
{
    this->spGauge.setTexture(this->gaugeTexture);
    this->spTip.setTexture(this->tipTexture);
}

void Dashboard::setOrigins()
{
    this->spGauge.setOrigin(this->x_gaugeOrigin, this->y_gaugeOrigin);
    this->spTip.setOrigin(this->x_tipOrigin, this->y_tipOrigin);
}

void Dashboard::setScale(double scale)
{
    this->spGauge.setScale(scale, scale);
    this->spTip.setScale(scale, scale);
    this->scale = scale;
}

void Dashboard::setPosition(double x, double y)
{
    this->spGauge.setPosition(x, y);
    this->spTip.setPosition(x+141.0, y+135.0);
}

void Dashboard::setTipAngle()
{
    this->tipAngle = -90.0+this->rpm/42.8;
    this->spTip.setRotation(this->tipAngle);
}

void Dashboard::readCarData(Car *anyCar)
{
    this->speed = anyCar->speed;
    this->rpm = anyCar->currentRpm;
    this->gear = anyCar->gear;
}

void Dashboard::showData()
{
    this->setTipAngle();
}
