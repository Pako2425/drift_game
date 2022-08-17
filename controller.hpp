class Controller
{   
    public:
        bool gasPedal;
        bool brakePedal;
        bool handBrake;
        bool steerLeft;
        bool steerRight;
        void readInput();

    Controller()
    {
        gasPedal = false;
        brakePedal = false;
        handBrake = false;
        steerLeft = false;
        steerRight = false;
    }
};