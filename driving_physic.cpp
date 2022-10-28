#include "driving_physic.hpp"
#include <cmath>

Driving_Physic::Driving_Physic()
{
    dt = 1.0/60.0;
}

Driving_Physic::~Driving_Physic()
{

}

void Driving_Physic::calculateRadiusOfCarTurningCircle(const Car& anyCar)
{
    double Beta = 0.0;
    if(std::abs(anyCar.getSteerAngle()) > 0.6)
    {
        Beta = 90.0-std::abs(anyCar.getSteerAngle());
        this->turningRadius = anyCar.getLength()*tan(Beta*M_PI/180);
    }
    else
    {
        this->turningRadius = 0.0;
    }
}

void Driving_Physic::calculateCarRotationAngle(const Car& anyCar)
{
    double dAlfa = 0.0;
    if(this->turningRadius > 0)
    {
        dAlfa = anyCar.getVelocity()*this->dt/this->turningRadius;
        this->dCarRotationAngle = dAlfa*180/M_PI;
    }
    else
    {
        this->dCarRotationAngle = 0.0;
    }
    
}

void Driving_Physic::calculateNewCarAngle(const Car& anyCar)
{
    if(anyCar.getSteerAngle() < -0.6)
    {
        this->newCarAngle = -this->dCarRotationAngle;
    }
    else if(anyCar.getSteerAngle() > 0.6)
    {
        this->newCarAngle = this->dCarRotationAngle;
    }
    else
    {
        this->newCarAngle = 0.0;
    }
}

void Driving_Physic::calculateNewCarPosition(const Car& anyCar)
{
    this->newCarXPos = 18.0*anyCar.getVelocity()*this->dt*sin(anyCar.getAngle()*M_PI/180);
    this->newCarYPos = -18.0*anyCar.getVelocity()*this->dt*cos(anyCar.getAngle()*M_PI/180);
}

void Driving_Physic::updateCar(Car& anyCar)
{
    this->calculateRadiusOfCarTurningCircle(anyCar);
    this->calculateCarRotationAngle(anyCar);
    this->calculateNewCarAngle(anyCar);
    this->calculateNewCarPosition(anyCar);
    anyCar.move(this->newCarXPos, this->newCarYPos, this->newCarAngle);
}
