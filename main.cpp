#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <string>
#include "controller.hpp"
#include "car.hpp"
#include "map.hpp"
#include "driving_physic.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280,960), "game_window");
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
    //if(!font.loadFromFile("font_files/atwriter.ttf"))
    //{
    //    return EXIT_FAILURE;
    //}
    Controller myController;
    Car Mazda_rx7(640, 480, 0, "images/cars/mazda_rx7_left30.png");
    Map Track1(4000.0, 200.0, -90.0, "images/tracks/track1.png");
    Driving_Physic myPhysic;
    text.setString(std::to_string(Mazda_rx7.steerAngle));
    text2.setString(std::to_string(Mazda_rx7.speed*3600/1000));
    text.setPosition(10,50);
    text2.setPosition(10,10);
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
            Mazda_rx7.steerLeft();
        }
        else if(myController.steerRight)
        {
            Mazda_rx7.steerRight();
        }
        else
        {
            Mazda_rx7.steerReturning();
        }

        if(myController.gasPedal)
        {
            Mazda_rx7.accelerate();
        }
        else if(myController.brakePedal)
        {
            Mazda_rx7.brake();
        }
        else
        {
            Mazda_rx7.decelerate();
        }
        myPhysic.updateCarDataBase(&Mazda_rx7);
        myPhysic.updateMapDataBase(&Track1);
        Mazda_rx7.setPathToRightTexture();
        std::cout<<Mazda_rx7.texturePath<<std::endl;
        Mazda_rx7.loadTexture();
        Mazda_rx7.setTexture();
        myPhysic.moveMap(&Track1);
        window.clear();
        window.draw(Track1.sp);
        window.draw(Mazda_rx7.sp);
        window.draw(text);
        window.draw(text2);
        window.display();
    }
    return 0;
}