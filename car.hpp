enum steeringDirections {STRAIGHT, LEFT, RIGHT};

class Car
{
    public:
    int steeringWheelPosition;   //-540-540
    unsigned int xPos;
    unsigned int yPos;
    double speed;     //in m/s
    double maxSpeed;
    unsigned int angle;
    float tireSlip;    //<0 tire have grip, >0 tire have no grip

    void steer(enum steeringDirections, unsigned int);
    void accelerate();
    void decelerate();
    void brake();
    void move();

    Car(unsigned int idleXPos, unsigned int idleYPos, unsigned int idleAngle)
    {
        steeringWheelPosition = 0;
        speed = 0.0;
        maxSpeed = 67.0;
        xPos = idleXPos;
        yPos = idleYPos;
        angle = idleAngle;
        
    }
};
