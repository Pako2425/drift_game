#include <SFML/Graphics.hpp>
#include <cmath>
#include <string>
#include "controller.hpp"
#include "car.hpp"

int main()
{
    Controller myController;
    Car myCar(50, 50, 0);
    sf::RenderWindow window(sf::VideoMode(800,600), "game_window");
    //sf::RectangleShape nissan(sf::Vector2f(myCar.xCarPos,myCar.yCarPos));
    sf::RectangleShape revLine(sf::Vector2f(150,5));
    //nissan.setFillColor(sf::Color::Green);
    revLine.setFillColor(sf::Color::Red);
    window.setFramerateLimit(60);
    sf::Font font;
    sf::Text text;
    sf::Text text2;
    text.setFont(font);
    text.setCharacterSize(50);
    text2.setFont(font);
    text2.setCharacterSize(50);
    text.setFillColor(sf::Color::Green);
    text2.setFillColor(sf::Color::Yellow);
    if(!font.loadFromFile("font_files/atwriter.ttf"))
    {
        return EXIT_FAILURE;
    }





    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        myCar.handbrake = false;
        myController.readInput();
        if(myController.steerLeft)
        {
            myCar.steering(LEFT);
        }
        else if(myController.steerRight)
        {
            myCar.steering(RIGHT);
        }
        else
        {
            myCar.steering(NONE_DIRECTION);
        }

        if(myController.gasPedal)
        {
            myCar.pressPedal(GAS);
        }
        else if(myController.brakePedal)
        {
            myCar.pressPedal(BRAKE);
        }
        else
        {
            myCar.pressPedal(NONE_PEDAL);
        }

        if(myController.shiftUp)
        {
            myCar.shiftGear(SHIFT_UP);
            myCar.currentEngineRpm = static_cast<int>(myCar.wheelsAngleVelocity * myCar.gearRatio[myCar.currentGear] * myCar.finalDrive);
        }
        else if(myController.shiftDown)
        {
            myCar.shiftGear(SHIFT_DOWN);
            myCar.currentEngineRpm = static_cast<int>(myCar.wheelsAngleVelocity * myCar.gearRatio[myCar.currentGear] * myCar.finalDrive);
        }
        else
        {
            myCar.prevShift = false;
        }
        if(myController.handBrake)
        {
            myCar.handbrake = true;
        }
        myCar.calculateWheelsAngleVelocity();





        text.setString(std::to_string(myCar.steeringWheelPosition));
        text2.setString(std::to_string(myCar.currentGear));
        window.clear();
        revLine.setPosition(300,300);
        revLine.setRotation(110.0 + (float(myCar.currentEngineRpm) / 31.0));
        window.draw(revLine);
        //myCar.setPosition(myCarx, myCary);
        //myCar.setRotation(carAngle);
        //window.draw(myCar);
        text.setPosition(100, 50);
        text2.setPosition(10,10);
        window.draw(text);
        if(true)
        {
           window.draw(text2); 
        }
        window.display();
    }

    return 0;
}