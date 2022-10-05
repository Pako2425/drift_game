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

void Dashboard::setScale(double scale)
{
    Dashboard::spGauge.setScale(scale, scale);
    Dashboard::spTip.setScale(scale, scale);
}

void Dashboard::setPosition(double x, double y)
{
    Dashboard::spGauge.setPosition(x, y);
    Dashboard::spTip.setPosition(x+141.0, y+135.0);
}

void Dashboard::setTipAngle(double angle)
{
    Dashboard::spTip.setRotation(angle);
}
