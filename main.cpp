#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <string>
#include "controller.hpp"
#include "car.hpp"

int main()
{
    Controller myController;
    Car myCar(50, 50, 0);
    sf::RenderWindow window(sf::VideoMode(800,600), "game_window");
    sf::RectangleShape nissan(sf::Vector2f(myCar.xPos,myCar.yPos));
    nissan.setFillColor(sf::Color::Green);
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

    double carSteeringStep = 0.5;
    myCar.dSteerAngle = carSteeringStep;
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
        if(myController.steerLeft)
        {
            //myCar.steer(LEFT, carSteeringStep);
            myCar.steerLeft();
        }
        else if(myController.steerRight)
        {
            //myCar.steer(RIGHT, carSteeringStep);
            myCar.steerRight();
        }
        else
        {
            //myCar.steer(STRAIGHT, carSteeringStep);
            myCar.steerReturning();
        }

        if(myController.gasPedal)
        {
            myCar.accelerate();
        }
        else if(myController.brakePedal)
        {
            myCar.brake();
        }
        else
        {
            myCar.decelerate();
        }
        //myCar.move();


        text.setString(std::to_string(myCar.steerAngle));
        text2.setString(std::to_string(myCar.speed*3600/1000));
        window.clear();
        //nissan.setPosition(myCar.xPos, myCar.yPos);
        //nissan.setRotation(myCar.angle);
        //window.draw(nissan);
        text.setPosition(100, 50);
        text2.setPosition(10,10);
        window.draw(text);
        window.draw(text2); 
        window.display();
    }

    return 0;
}