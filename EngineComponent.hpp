#pragma once

class EngineComponent
{
private:
    double idleRpm;
    double currentRpm;
    double maxRpm;
public:
    EngineComponent();
    ~EngineComponent();

    //accessors
    const double& getCurrentRpm();

    //functions
    void setRpm(const double rpm);

};