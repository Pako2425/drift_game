enum steeringDirections {NONE_DIRECTION, LEFT, RIGHT};
enum carPedals {NONE_PEDAL, GAS, BRAKE};

class Car
{
    public:
    //bool steerLeft;
    //bool steerRight;
    int steeringWheelPosition;   //-540-540
    unsigned int dsteer;
    //bool gas;
    //bool brake;
    bool handbrake;
    bool shiftUp;
    bool shiftDown;
    bool prevShift;
    unsigned int xCarPos;
    unsigned int yCarPos;
    unsigned int carAngle;
    int wheelsSize;         //in milimiters
    float wheelsAngleVelocity;
    int xCarVelocity;   //in m/s
    int yCarVelocity;   //in m/s
    unsigned int idleEngineRpm;
    unsigned int maxEngineRpm;
    unsigned int currentEngineRpm;  //idle-max
    unsigned int currentGear;
    float gearRatio[6];
    float finalDrive;

    //Silnik wytwarza moc. Przenosi ją na koła za pomocą skrzyni i reszty układu przeniesienia.
    //Guma na kołach obracając się wytwarza siłę tarcia która pcha samochód do przodu. Jeżeli układ
    //przeniesienia przeniesie zbyt dużo mocy z silnika, to maksymalna siła tarcia opony zostanie 
    //przełamana i opona straci przyczepność.
    //Należy obliczać przyrost zmiany prędkości kątowej koła, jeżeli będzie zbyt duży to opona straci
    //przyczepność.

    float tireSlip;    //<0 tire have grip, >0 tire have no grip

    void updateStateOfSteeringSystem();
    void updateStateOfEngine();
    void updateStateOfGerbox();
    void updateStateOfWheels();
    void updateStateOfDriveSystem();

    void steering(enum steeringDirections);
    void pressPedal(enum carPedals);
    void pressGas();
    void pressBrake();
    void shiftGear();
    void handBraking();

    Car(unsigned int xIdleCarPos, unsigned int yIdleCarPos, unsigned int idleCarAngle)
    {
        steeringWheelPosition = 0;
        dsteer = 10;
        handbrake = false;
        shiftUp = false;
        shiftDown = false;
        prevShift = false;
        xCarPos = xIdleCarPos;
        yCarPos = yIdleCarPos;
        carAngle = idleCarAngle;
        wheelsSize = 215;       //in milimiters
        idleEngineRpm = 800;
        maxEngineRpm = 8400;
        currentEngineRpm = idleEngineRpm;
        currentGear = 1;
        gearRatio[0] = 4.04; //the reverse gear
        gearRatio[1] = 4.23;
        gearRatio[2] = 2.52;
        gearRatio[3] = 1.66;
        gearRatio[4] = 1.22;
        gearRatio[5] = 1.00;
        finalDrive = 3.45;
    }
};