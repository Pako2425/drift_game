#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <string>
#include "controller.hpp"
#include "car.hpp"

void readMap();
void readCar();

int main()
{
    Controller myController;
    sf::RenderWindow window(sf::VideoMode(800,600), "game_window");
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
    Car myCar(50, 50, 0, "images/cars/mazda_rx7.png");


    //sf::Texture mazda_rx7;
    sf::Texture track1;
    if(track1.loadFromFile("images/tracks/track1.png"))
    {
        printf("track loaded sucessfully");
    }


    sf::Sprite spMazda_rx7;
    sf::Sprite spTrack1;
    spMazda_rx7.setPosition(10.0,50.0);
    spMazda_rx7.setScale(0.3, 0.3);
    spMazda_rx7.setTexture(myCar.myCarTexture);
    spMazda_rx7.move(100,0);
    //spTrack1.setPosition(0.0, 0.0);
    //spTrack1.setScale(1.0, 1.0);
    //spTrack1.setTexture(track1);

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
            myCar.steerLeft();
            spTrack1.move(10, 0);
        }
        else if(myController.steerRight)
        {
            myCar.steerRight();
            spTrack1.move(-10, 0);
        }
        else
        {
            myCar.steerReturning();
        }

        if(myController.gasPedal)
        {
            myCar.accelerate();
            spTrack1.move(0, 10);
        }
        else if(myController.brakePedal)
        {
            myCar.brake();
            spTrack1.move(0, -10);
        }
        else
        {
            myCar.decelerate();
        }
        //myCar.move();

        text.setString(std::to_string(myCar.steerAngle));
        text2.setString(std::to_string(myCar.speed*3600/1000));
        window.clear();
        text.setPosition(10,50);
        text2.setPosition(10,10);
        window.draw(text);
        window.draw(text2);
        window.draw(spMazda_rx7); 
        window.display();
    }
    return 0;
}