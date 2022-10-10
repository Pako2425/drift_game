#include "car.hpp"
#include <cmath>

void Car::accelerate()
{
    this->speed = this->speed + (this->maxSpeed - this->speed)*0.002;
}

void Car::decelerate()
{
    if(this->speed >= 19.44)
    {
        this->speed = this->speed - this->speed * 0.0011; 
    }
    else if(this->speed < 19.44 && this->speed > 0)
    {
        this->speed = this->speed - 0.021;
    }
    else
    {
        this->speed = 0.0;
    }
}

void Car::brake()
{
    if(this->speed > 0.17)
    {
        this->speed = this->speed - 0.17;
    }
    else
    {
        this->speed = 0.0;
    }
}

void Car::steerRight()
{
    if(this->steerAngle < this->maxRaceSteerAngle)
    {
        this->steerAngle += this->dSteerAngle;
    }
}

void Car::steerLeft()
{
    if(this->steerAngle > -this->maxRaceSteerAngle)
    {
        this->steerAngle -= this->dSteerAngle;
    }
}

void Car::steerReturning()
{
    if(this->steerAngle > 0)
    {
        this->steerAngle -= this->dSteerAngle;
    }
    else if(this->steerAngle < 0)
    {
        this->steerAngle += this->dSteerAngle;
    }
    else
    {
        this->steerAngle = this->steerAngle;
    }
}

void Car::setPathToRightTexture()   //function responsible for choose right texture
{
    std::string path_mainPart = "images/cars/";
    std::string path;
    int steerAngle = (int)this->steerAngle;
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
    this->texturePath = path;
}

void Car::loadTexture()
{
    this->texture.loadFromFile(this->texturePath);
}

void Car::setTexture()
{
    this->sp.setTexture(this->texture);
}

void Car::getCenterOfTexture()
{
    this->center_x = this->texture.getSize().x/2.0;
    this->center_y = this->texture.getSize().y/2.0;
}

void Car::setOrigin()
{
    this->sp.setOrigin(this->center_x, this->center_y*1.7);
}

void Car::setScale(double scale)
{
    this->sp.setScale(scale, scale);
}

void Car::setPosition()
{
    this->sp.setPosition(this->xPos, this->yPos);
}

void Car::setRotation()
{
    this->sp.setRotation(Car::angle);
}
