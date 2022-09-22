#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <string>
#include "controller.hpp"
#include "car.hpp"
#include "map.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280,960), "game_window");
    window.setFramerateLimit(60);
    //sf::Font font;
    //sf::Text text;
    //sf::Text text2;
    //text.setFont(font);
    //text.setCharacterSize(50);
    //text2.setFont(font);
    //text2.setCharacterSize(50);
    //text.setFillColor(sf::Color::Green);
    //text2.setFillColor(sf::Color::Yellow);
    //if(!font.loadFromFile("font_files/atwriter.ttf"))
    //{
    //    return EXIT_FAILURE;
    //}
    Controller myController;
    Car Mazda_rx7(640, 480, 0, "images/cars/mazda_rx7.png");
    Map Track1("images/tracks/track1.png");
    Mazda_rx7.setTexture();
    Mazda_rx7.setScale(0.25);
    Mazda_rx7.getCenterOfTexture();
    Mazda_rx7.setOrigin(Mazda_rx7.center_x, Mazda_rx7.center_y*1.7);
    Mazda_rx7.setPosition(Mazda_rx7.xPos*1.0, Mazda_rx7.yPos*1.0);
    Mazda_rx7.setRotation(0.0);
    Track1.sp.setTexture(Track1.texture);
    Track1.sp.setScale(1.3, 1.3);
    Track1.sp.setOrigin(640.0, 480.0);
    Track1.sp.setPosition(640.0, 480.0);

    double dt = 1.0/60.0;
    double dS = 0.0;
    double R;
    double dx;
    double dy;
    double dAlfa;
    double dCarRotationAngle;
    double Beta;
    
    double mapAngle = 0.0;
    double mapDx = 640.0;
    double mapDy = 480.0;

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
            mapAngle = mapAngle + 1.0;
        }
        else if(myController.steerRight)
        {
            Mazda_rx7.steerRight();
            mapAngle = mapAngle - 1.0;
        }
        else
        {
            Mazda_rx7.steerReturning();
            mapAngle = mapAngle;
        }

        if(myController.gasPedal)
        {
            Mazda_rx7.accelerate();
            mapDy = mapDy + 5.0;
        }
        else if(myController.brakePedal)
        {
            Mazda_rx7.brake();
            mapDy = mapDy - 5.0;
        }
        else
        {
            Mazda_rx7.decelerate();
        }
        Track1.sp.setRotation(mapAngle);
        Track1.sp.setPosition(mapDx, mapDy);
        //Mazda_rx7.setRotation(mapAngle);
        dS = Mazda_rx7.speed*dt;
        R = 0;
        Beta = 0;
        dAlfa = 0;
        dx = 0;
        dy = dS;
        dCarRotationAngle = 0;
        if(Mazda_rx7.steerAngle != 0)
        {
            Beta = 90-Mazda_rx7.steerAngle;
            R = Mazda_rx7.length*tan(Beta*M_PI/180);
            dAlfa = dS/R;
            dCarRotationAngle = dAlfa*180/M_PI;
            dx = R*(1-cos(dAlfa));
            dy = R*sin(dAlfa); 
        }
        //text.setString(std::to_string(myCar.steerAngle));
        //text2.setString(std::to_string(myCar.speed*3600/1000));
        //text.setPosition(10,50);
        //text2.setPosition(10,10);
        window.clear();
        //window.draw(text);
        //window.draw(text2); 
        window.draw(Track1.sp);
        window.draw(Mazda_rx7.sp);
        window.display();
    }
    return 0;
}