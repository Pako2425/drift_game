#include "dashboard.hpp"

void Dashboard::loadTexture()
{
    Dashboard::gaugeTexture.loadFromFile(Dashboard::gaugeTexturePath);
    Dashboard::tipTexture.loadFromFile(Dashboard::tipTexturePath);
}

void Dashboard::setTexture()
{
    Dashboard::spGauge.setTexture(Dashboard::gaugeTexture);
    Dashboard::spTip.setTexture(Dashboard::tipTexture);
}

void Dashboard::setOrigins()
{
    Dashboard::spGauge.setOrigin(Dashboard::x_gaugeOrigin, Dashboard::y_gaugeOrigin);
    Dashboard::spTip.setOrigin(Dashboard::x_tipOrigin, Dashboard::y_tipOrigin);
}

void Dashboard::setScale(double scale)
{
    Dashboard::spGauge.setScale(scale, scale);
    Dashboard::spTip.setScale(scale, scale);
    Dashboard::scale = scale;
}

void Dashboard::setPosition(double x, double y)
{
    Dashboard::spGauge.setPosition(x, y);
    Dashboard::spTip.setPosition(x+141.0, y+135.0);
    //Dashboard::spTip.setPosition(Dashboard::xScreenPos+313.33*Dashboard::Scale, Dashboard::xScreenPos+300.0*Dashboard::Scale);
}

void Dashboard::setTipAngle()
{
    this->tipAngle = -90.0+this->rpm/42.8;
    this->spTip.setRotation(this->tipAngle);
}

void Dashboard::readCarData(const Car& anyCar)
{
    this->speed = anyCar.getVelocity();
    this->rpm = anyCar.getCurrentRpm();
    this->gear = anyCar.getGear();
}

void Dashboard::showData()
{
    this->setTipAngle();
}
