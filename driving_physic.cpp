#include "driving_physic.hpp"
#include <cmath>

void Driving_Physic::calculateRadiusOfCarTurningCircle(Car *anyCar)
{
    double Beta = 0.0;
    double carSteerAngle = anyCar->steerAngle;
    double carLength = anyCar->length;
    if(carSteerAngle < -0.6)
    {
        Beta = 90.0+carSteerAngle;
        this->turningRadius = carLength*tan(Beta*M_PI/180);
    }
    else if(carSteerAngle > 0.6)
    {
        Beta = 90.0-carSteerAngle;
        this->turningRadius = carLength*tan(Beta*M_PI/180);
    }
    else
    {
        this->turningRadius = -1.0;
    }
}

void Driving_Physic::calculateCarRotationAngle(Car *anyCar)
{
    double dAlfa = 0.0;
    double carSpeed = anyCar->speed;
    if(this->turningRadius >=0)
    {
        dAlfa = carSpeed*this->dt/this->turningRadius;
        this->dCarRotationAngle = dAlfa*180/M_PI;
    }
    else
    {
        this->dCarRotationAngle = 0.0;
    }
    
}

void Driving_Physic::calculateNewCarAngle(Car *anyCar)
{
    double carSteerAngle = anyCar->steerAngle;
    if(carSteerAngle < -0.6)
    {
        this->newCarAngle = anyCar->angle - dCarRotationAngle;
    }
    else if(carSteerAngle > 0.6)
    {
        this->newCarAngle = anyCar->angle + dCarRotationAngle;
    }
    else
    {
        this->newCarAngle = anyCar->angle;
    }
}

void Driving_Physic::calculateNewCarPosition(Car *anyCar)
{
    double carSpeed = anyCar->speed;
    double carAngle = anyCar->angle;
    this->newCarXPos = anyCar->xPos + 12.0*carSpeed*this->dt*sin(carAngle*M_PI/180);
    this->newCarYPos = anyCar->yPos - 12.0*carSpeed*this->dt*cos(carAngle*M_PI/180);
}

void Driving_Physic::moveCar(Car *anyCar)
{
    calculateRadiusOfCarTurningCircle(anyCar);
    calculateCarRotationAngle(anyCar);
    calculateNewCarAngle(anyCar);
    calculateNewCarPosition(anyCar);
    anyCar->xPos = this->newCarXPos;
    anyCar->yPos = this->newCarYPos;
    anyCar->angle = this->newCarAngle;
}
