#include "EngineComponent.hpp"

EngineComponent::EngineComponent()
{
    this->idleRpm = 800.0;
    this->currentRpm = this->idleRpm;
    this->maxRpm = 7800.0;
}

EngineComponent::~EngineComponent()
{

}

const double& EngineComponent::getCurrentRpm()
{
    return this->currentRpm;
}

void EngineComponent::setRpm(const double rpm)
{
    this->currentRpm = rpm;
}
