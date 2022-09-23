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
    Car Mazda_rx7(640, 480, 0, "images/cars/mazda_rx7.png");
    Map Track1("images/tracks/track1.png");
    Driving_Physic myPhysic;
    text.setString(std::to_string(Mazda_rx7.steerAngle));
    text2.setString(std::to_string(Mazda_rx7.speed*3600/1000));
    text.setPosition(10,50);
    text2.setPosition(10,10);
    Mazda_rx7.setTexture();
    Mazda_rx7.setScale(0.15);
    Mazda_rx7.getCenterOfTexture();
    Mazda_rx7.setOrigin(Mazda_rx7.center_x, Mazda_rx7.center_y*1.7);
    Mazda_rx7.setPosition(Mazda_rx7.xPos*1.0, Mazda_rx7.yPos*1.0);
    Mazda_rx7.setRotation(0.0);
    Track1.setTexture();
    Track1.setScale(1.2);
    Track1.setOrigin(640.0, 480.0);
    Track1.setPosition(640.0, 480.0);

    //double dt = 1.0/60.0;
    //double dS = 0.0;
    //double R;
    //double dAlfa;
    //double dCarRotationAngle;
    //double Beta;
    
    //double mapAngle = 90.0;
    Track1.angle = 90.0;
    //double mapDx = 640.0;
    //double mapDy = 480.0;
    Track1.xPos = 640.0;
    Track1.yPos = 480.0;

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
        //Beta = 0;
        //R = 0;
        //dS = Mazda_rx7.speed*dt;
        //dAlfa = 0;
        //dCarRotationAngle = 0;
        /*
        if(Mazda_rx7.steerAngle < -0.8)
        {
            Beta = 90.0+Mazda_rx7.steerAngle;
            R = Mazda_rx7.length*tan(Beta*M_PI/180);
            dAlfa = dS/R;
            dCarRotationAngle = dAlfa*180/M_PI;
            mapAngle = mapAngle + dCarRotationAngle;
        }
        else if(Mazda_rx7.steerAngle > 0.8)
        {
            Beta = 90.0-Mazda_rx7.steerAngle;
            R = Mazda_rx7.length*tan(Beta*M_PI/180);
            dAlfa = dS/R;
            dCarRotationAngle = dAlfa*180/M_PI;
            mapAngle = mapAngle - dCarRotationAngle;
        }
        else
        {
            mapAngle = mapAngle;
        }
        */
        myPhysic.moveMap(&Mazda_rx7, &Track1);
        //std::cout<<Mazda_rx7.steerAngle<<std::endl;
        //mapDx = mapDx - 12.0*dS*sin(mapAngle*M_PI/180);
        //mapDy = mapDy - 12.0*dS*cos(mapAngle*M_PI/180);
        //Track1.setOrigin(mapDx, mapDy);
        //Track1.setOrigin(Track1.xPos, Track1.yPos);
        //Track1.setPosition(640, 480);
        //Track1.setPosition(640.0, 480.0);
        //Track1.setRotation(mapAngle);
        //Track1.setRotation(Track1.angle);
        window.clear();
        window.draw(Track1.sp);
        window.draw(Mazda_rx7.sp);
        window.draw(text);
        window.draw(text2);
        window.display();
    }
    return 0;
}