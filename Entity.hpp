#pragma once

//#include components

class Entity
{
    private:
    //initFunction
    protected:
    //Variables

    public:
    //Component functions
    void setTexture();
    void accelerate();
    void decelerate();
    void brake();
    void steerLeft();
    void steerRight();
    void steerReturning();
    void setPathToRightTexture();
    void loadTexture();
    void setTexture();
    void getCenterOfTexture();
    void setOrigin();
    void setScale(double);
    void setPosition();
    void setRotation();
    //Accesors
    void getPosition();
    void getAngle();
    void getSpeed();
    //Modyfiers

    //Update

};
