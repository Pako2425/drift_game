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
        Driving_Physic::turningRadius = carLength*tan(Beta*M_PI/180);
    }
    else if(carSteerAngle > 0.6)
    {
        Beta = 90.0-carSteerAngle;
        Driving_Physic::turningRadius = carLength*tan(Beta*M_PI/180);
    }
    else
    {
        Driving_Physic::turningRadius = -1.0;
    }
}

void Driving_Physic::calculateCarRotationAngle(Car *anyCar)
{
    double dAlfa = 0.0;
    double carSpeed = anyCar->speed;
    if(Driving_Physic::turningRadius >=0)
    {
        dAlfa = carSpeed*Driving_Physic::dt/Driving_Physic::turningRadius;
        Driving_Physic::dCarRotationAngle = dAlfa*180/M_PI;
    }
    else
    {
        Driving_Physic::dCarRotationAngle = 0.0;
    }
    
}

void Driving_Physic::calculateNewCarAngle(Car *anyCar)
{
    double carSteerAngle = anyCar->steerAngle;
    if(carSteerAngle < -0.6)
    {
        anyCar->angle += dCarRotationAngle;
    }
    else if(carSteerAngle > 0.6)
    {
        anyCar->angle -= dCarRotationAngle;
    }
    else
    {
        anyCar->angle = anyCar->angle;
    }
}

void Driving_Physic::calculateNewCarPosition(Car *anyCar)
{
    double carSpeed = anyCar->speed;
    double carAngle = anyCar->angle;
    anyCar->xPos -= 12.0*carSpeed*Driving_Physic::dt*sin(carAngle*M_PI/180);
    anyCar->yPos -= 12.0*carSpeed*Driving_Physic::dt*cos(carAngle*M_PI/180);
}
