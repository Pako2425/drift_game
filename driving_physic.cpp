#include "driving_physic.hpp"
#include <cmath>

double Driving_Physic::calculateRadiusOfTurningCircle(double steerAngle, double carLength)
{
    double Beta = 0.0;
    double radius = 0.0;
    if(steerAngle < -0.6)
    {
        Beta = 90.0+steerAngle;
        radius = carLength*tan(Beta*M_PI/180);
    }
    else if(steerAngle > 0.6)
    {
        Beta = 90.0-steerAngle;
        radius = carLength*tan(Beta*M_PI/180);
    }
    else
    {
        radius = -1.0;
    }
    
    return radius;
}

double Driving_Physic::calculateCarRotationAngle(double steerAngle, double carSpeed, double radiusOfTurningCircle)
{
    double dAlfa = 0.0;
    double dCarRotationAngle = 0.0;
    dAlfa = carSpeed*Driving_Physic::dt/radiusOfTurningCircle;
    dCarRotationAngle = dAlfa*180/M_PI;

    return dCarRotationAngle;
}

double Driving_Physic::calculateNewMapAngle(double mapAngle, double steerAngle, double dCarRotationAngle)
{
    double newMapAngle;
    if(steerAngle < -0.6)
    {
        newMapAngle = mapAngle + dCarRotationAngle;
    }
    else if(steerAngle > 0.6)
    {
        newMapAngle = mapAngle - dCarRotationAngle;
    }
    else
    {
        newMapAngle = mapAngle;
    }
    return newMapAngle;
}

double Driving_Physic::calculateNewMapPosition(double mapAngle, double xMapPos, double yMapPos, double carSpeed)
{
    double new_xMapPos;
    double new_yMapPos;
    new_xMapPos = xMapPos - 12.0*carSpeed*Driving_Physic::dt*sin(mapAngle*M_PI/180);
    new_yMapPos = yMapPos - 12.0*carSpeed*Driving_Physic::dt*cos(mapAngle*M_PI/180);
    return (new_xMapPos, new_yMapPos);
}

void Driving_Physic::moveMap(Car *ExampleCar, Map *ExampleMap)
{
    double turningRadius;
    double dCarRotationAngle;
    double mapAngle;
    turningRadius = Driving_Physic::calculateRadiusOfTurningCircle(ExampleCar->steerAngle, ExampleCar->length);
    dCarRotationAngle = Driving_Physic::calculateCarRotationAngle(ExampleCar->steerAngle, ExampleCar->speed, turningRadius);
    mapAngle = Driving_Physic::calculateNewMapAngle(ExampleMap->angle, ExampleCar->steerAngle, dCarRotationAngle);
    (ExampleMap->xPos, ExampleMap->yPos) = Driving_Physic::calculateNewMapPosition(ExampleMap->angle, ExampleMap->xPos, ExampleMap->yPos, ExampleCar->speed);
    ExampleMap->setOrigin(ExampleMap->xPos, ExampleMap->yPos);
    ExampleMap->setPosition(640.0, 480.0);
    ExampleMap->setRotation(ExampleMap->angle);
}
