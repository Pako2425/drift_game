#include "car.hpp"
#include <cmath>

void Car::accelerate()
{
    Car::speed = Car::speed + (Car::maxSpeed - Car::speed)*0.002;
}

void Car::decelerate()
{
    if(Car::speed >= 19.44)
    {
        Car::speed = Car::speed - Car::speed * 0.0011; 
    }
    else if(Car::speed < 19.44 && Car::speed > 0)
    {
        Car::speed = Car::speed - 0.021;
    }
    else
    {
        Car::speed = 0.0;
    }
}

void Car::brake()
{
    if(Car::speed > 0.17)
    {
        Car::speed = Car::speed - 0.17;
    }
    else
    {
        Car::speed = 0.0;
    }
}

void Car::steerRight()
{
    if(Car::steerAngle < Car::maxRaceSteerAngle)
    {
        Car::steerAngle += Car::dSteerAngle;
    }
}

void Car::steerLeft()
{
    if(Car::steerAngle > -Car::maxRaceSteerAngle)
    {
        Car::steerAngle -= Car::dSteerAngle;
    }
}

void Car::steerReturning()
{
    if(Car::steerAngle > 0)
    {
        Car::steerAngle -= Car::dSteerAngle;
    }
    else if(Car::steerAngle < 0)
    {
        Car::steerAngle += Car::dSteerAngle;
    }
    else
    {
        Car::steerAngle = Car::steerAngle;
    }
}

void Car::setPathToRightTexture()   //function responsible for choose right texture
{
    std::string path_mainPart = "images/cars/";
    std::string path;
    int steerAngle = (int)Car::steerAngle;
    if(steerAngle%2 != 0)
    {
        if(steerAngle > 0)
        {
            steerAngle = steerAngle-1;
        }
        else
        {
            steerAngle = steerAngle+1;
        }
    }
    else
    {
        steerAngle = steerAngle;
    }
    if(steerAngle > 0)
    {
        path = path_mainPart.append("mazda_rx7_right" + std::to_string(steerAngle) + ".png");
    }
    else if(steerAngle < 0)
    {
        path = path_mainPart.append("mazda_rx7_left" + std::to_string(-steerAngle) + ".png");
    }
    else
    {
        path = path_mainPart.append("mazda_rx7.png");
    }
    Car::texturePath = path;
}

void Car::loadTexture()
{
    Car::texture.loadFromFile(Car::texturePath);
}

void Car::setTexture()
{
    Car::sp.setTexture(Car::texture);
}

void Car::getCenterOfTexture()
{
    Car::center_x = Car::texture.getSize().x/2.0;
    Car::center_y = Car::texture.getSize().y/2.0;
}

void Car::setOrigin()
{
    Car::sp.setOrigin(Car::center_x, Car::center_y*1.7);
}

void Car::setScale(double scale)
{
    Car::sp.setScale(scale, scale);
}

void Car::setPosition()
{
    Car::sp.setPosition(Car::xPos, Car::yPos);
}

void Car::setRotation()
{
    Car::sp.setRotation(Car::angle);
}
