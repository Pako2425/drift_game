#include "car.hpp"
#include <cmath>

Car::Car(double idleXPos, double idleYPos, double idleAngle, std::string idleTexturePath)
{
    this->steerAngle = 0.0;
    this->dSteerAngle = 0.5;
    this->maxRaceSteerAngle = 30.0;
    this->steeringWheelPosition = 0;
    this->velocity = 0.0;
    this->maxVelocity = 67.0;
    this->xPos = idleXPos;
    this->yPos = idleYPos;
    this->angle = idleAngle;
    this->texturePath = idleTexturePath;
    this->length = 4.3;
    this->gear = 1;
    this->idleRpm = 800.0;
    this->maxRpm = 7800.0;
    this->gearRatios[0] = 3.683;
    this->gearRatios[1] = 2.263;
    this->gearRatios[2] = 1.397;
    this->gearRatios[3] = 1.00;
    this->gearRatios[4] = 0.862;
    this->rearAxleRatio = 3.9;
    this->wheelsDiameter = 0.68;
    this->wheelsCircumference = M_PI*wheelsDiameter;
    
    this->texture.loadFromFile(this->texturePath);
    this->sp.setTexture(this->texture);
    this->sp.setScale(0.20, 0.20);
    this->sp.setOrigin(this->texture.getSize().x*0.5, this->texture.getSize().y*0.85);
    this->sp.setPosition(this->xPos, this->yPos);
    this->sp.setRotation(this->angle);
}

Car::~Car()
{

}

void Car::move(const double dx, const double dy, const double dAngle)
{
    this->xPos += dx;
    this->yPos += dy;
    this->angle += dAngle;
}

void Car::accelerate()
{
    this->velocity += (this->maxVelocity - this->velocity)*0.002;
}

void Car::decelerate()
{
    if(this->velocity >= 19.44)
    {
        this->velocity -= this->velocity * 0.0011; 
    }
    else if(this->velocity < 19.44 && this->velocity > 0)
    {
        this->velocity -= 0.021;
    }
    else
    {
        this->velocity = 0.0;
    }
}

void Car::brake()
{
    if(this->velocity > 0.17)
    {
        this->velocity -= 0.17;
    }
    else
    {
        this->velocity = 0.0;
    }
}

void Car::steerRight()
{
    if(this->steerAngle < this->maxRaceSteerAngle)
    {
        this->steerAngle += this->dSteerAngle;
    }
    else
    {
        this->steerAngle = this->steerAngle;
    }
}

void Car::steerLeft()
{
    if(-this->steerAngle < this->maxRaceSteerAngle)
    {
        this->steerAngle -= this->dSteerAngle;
    }
    else
    {
        this->steerAngle = this->steerAngle;
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

void Car::calculateRPM()
{
    this->currentRpm = this->idleRpm+( (60.0*this->gearRatios[this->gear-1]*this->rearAxleRatio)/(this->wheelsCircumference) )*this->velocity;
}

void Car::calculateGear()
{
    if(this->currentRpm >= this->maxRpm)
    {
        this->gear+=1;
    }
    else if((this->currentRpm < this->maxRpm*0.60) && (this->gear > 1))
    {
        this->gear-=1;
    }
    else
    {
        this->gear = this->gear;
    }
}

void Car::update()
{
    this->texture.loadFromFile(this->texturePath);
    this->sp.setTexture(this->texture);
    this->sp.setPosition(this->xPos, this->yPos);
    this->sp.setRotation(this->angle);
    this->calculateRPM();
    this->calculateGear();
}
