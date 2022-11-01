#pragma once

class GearboxComponent
{
public:
    int gear;
    double gearRatios[5];
    double rearAxleRatio;

private:
    GearboxComponent();
    ~GearboxComponent();
    
    //accessors
    const int& getGear();
    const double& getRatio(const int gear);
    const double& getRearAxleRatio();

    //functions
    void setGear(const int gear);
};