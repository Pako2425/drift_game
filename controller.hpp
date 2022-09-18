#pragma once

class Controller
{   
    public:
        bool gasPedal;
        bool brakePedal;
        bool handBrake;
        bool steerLeft;
        bool steerRight;
        bool shiftUp;
        bool shiftDown;
        void readInput();

    Controller()
    {
        gasPedal = false;
        brakePedal = false;
        handBrake = false;
        steerLeft = false;
        steerRight = false;
        shiftUp = false;
        shiftDown = false;
    }
};
