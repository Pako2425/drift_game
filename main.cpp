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
    text.setFont(font);
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::Green);
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
        myController.readInput();
        myCar.steerLeft = false;
        myCar.steerRight = false;
        myCar.gas = false;
        myCar.brake = false;
        myCar.handbrake = false;
        if(myController.steerLeft)
        {
            myCar.steerLeft = true;
        }
        else if(myController.steerRight)
        {
            myCar.steerRight = true;
        }
        if(myController.gasPedal)
        {
            myCar.gas = true;
        }
        else if(myController.brakePedal)
        {
            myCar.brake = true;
        }
        if(myController.handBrake)
        {
            myCar.handbrake = true;
        }
        myCar.steering();
        myCar.workOfEngine();

        text.setString(std::to_string(myCar.steeringWheelPosition));
        window.clear();
        revLine.setPosition(300,300);
        revLine.setRotation(110.0 + (float(myCar.currentEngineRpm) / 31.0));
        window.draw(revLine);
        //myCar.setPosition(myCarx, myCary);
        //myCar.setRotation(carAngle);
        //window.draw(myCar);
        text.setPosition(100, 50);
        window.draw(text);
        window.display();
    }

    return 0;
}