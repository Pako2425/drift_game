class Car
{
    int steering;   //-540-540
    unsigned int gas;       //0-100
    unsigned int brake;     //0-100
    unsigned int idleEngineRpm;
    unsigned int currentEngineRpm;  //idle-max
    unsigned int maxEngineRpm;

    unsigned int xCarPos;
    unsigned int yCarPos;
    unsigned int carAngle;

    Car(unsigned int xIdleCarPos, unsigned int yIdleCarPos, unsigned int idleCarAngle)
    {
        steering = 0;
        gas = 0;
        brake = 0;
        idleEngineRpm = 800;
        currentEngineRpm = idleEngineRpm;
        maxEngineRpm = 8000;
        xCarPos = xIdleCarPos;
        yCarPos = yIdleCarPos;
        carAngle = idleCarAngle;
    }
};