#pragma once

class SteeringComponent
{
private:
    double steerAngle;     //-30 - 30
    double dSteerAngle;
    double maxRaceSteerAngle;
public:
    SteeringComponent();
    ~SteeringComponent();

    //accessors
    const double& getSteerAngle();
    //functions
    void steerLeft();
    void steerRight();
    void steerReturning();
};