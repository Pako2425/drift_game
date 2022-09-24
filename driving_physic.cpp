#include "driving_physic.hpp"
#include <cmath>

void Driving_Physic::updateCarDataBase(Car *anyCar)
{
    Driving_Physic::carSpeed = anyCar->speed;
    Driving_Physic::carLength = anyCar->length;
    Driving_Physic::carSteerAngle = anyCar->steerAngle;
    Driving_Physic::carAngle = anyCar->angle;
}

void Driving_Physic::updateMapDataBase(Map *anyMap)
{
    Driving_Physic::xMapPos = anyMap->xPos;
    Driving_Physic::yMapPos = anyMap->yPos;
    Driving_Physic::mapAngle = anyMap->angle;
}

void Driving_Physic::calculateRadiusOfCarTurningCircle()
{
    double Beta = 0.0;
    if(Driving_Physic::carSteerAngle < -0.6)
    {
        Beta = 90.0+Driving_Physic::carSteerAngle;
        Driving_Physic::turningRadius = Driving_Physic::carLength*tan(Beta*M_PI/180);
    }
    else if(Driving_Physic::carSteerAngle > 0.6)
    {
        Beta = 90.0-Driving_Physic::carSteerAngle;
        Driving_Physic::turningRadius = Driving_Physic::carLength*tan(Beta*M_PI/180);
    }
    else
    {
        Driving_Physic::turningRadius = -1.0;
    }
}

void Driving_Physic::calculateCarRotationAngle()
{
    double dAlfa = 0.0;
    if(Driving_Physic::turningRadius >=0)
    {
        dAlfa = Driving_Physic::carSpeed*Driving_Physic::dt/Driving_Physic::turningRadius;
        Driving_Physic::dCarRotationAngle = dAlfa*180/M_PI;
    }
    else
    {
        Driving_Physic::dCarRotationAngle = 0.0;
    }
    
}

void Driving_Physic::calculateNewMapAngle()
{
    if(Driving_Physic::carSteerAngle < -0.6)
    {
        Driving_Physic::new_MapAngle = Driving_Physic::mapAngle + Driving_Physic::dCarRotationAngle;
    }
    else if(Driving_Physic::carSteerAngle > 0.6)
    {
         Driving_Physic::new_MapAngle = Driving_Physic::mapAngle - Driving_Physic::dCarRotationAngle;
    }
    else
    {
        Driving_Physic::new_MapAngle = Driving_Physic::mapAngle;
    }
}

void Driving_Physic::calculateNewMapPosition()
{
    Driving_Physic::new_xMapPos = Driving_Physic::xMapPos - 12.0*Driving_Physic::carSpeed*Driving_Physic::dt*sin(Driving_Physic::mapAngle*M_PI/180);
    Driving_Physic::new_yMapPos = Driving_Physic::yMapPos - 12.0*Driving_Physic::carSpeed*Driving_Physic::dt*cos(Driving_Physic::mapAngle*M_PI/180);
}

void Driving_Physic::moveMap(Map *ExampleMap)
{
    Driving_Physic::calculateRadiusOfCarTurningCircle();
    Driving_Physic::calculateCarRotationAngle();
    Driving_Physic::calculateNewMapAngle();
    Driving_Physic::calculateNewMapPosition();
    ExampleMap->xPos = Driving_Physic::new_xMapPos;
    ExampleMap->yPos = Driving_Physic::new_yMapPos;
    ExampleMap->angle = Driving_Physic::new_MapAngle;
    ExampleMap->setOrigin(ExampleMap->xPos, ExampleMap->yPos);
    ExampleMap->setPosition(640.0, 480.0);
    ExampleMap->setRotation(ExampleMap->angle);
}
