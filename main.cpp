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
    Car myCar(360, 400, 0, "images/cars/mazda_rx7.png");
    Map myMap("images/tracks/track1.png");
    sf::Sprite spMazda_rx7;
    sf::Transform mapTransform;
    spMazda_rx7.setPosition(myCar.xPos*1.0, myCar.yPos*1.0);
    spMazda_rx7.setScale(0.25, 0.25);
    spMazda_rx7.setTexture(myCar.myCarTexture);
    sf::Sprite spTrack1;
    spTrack1.setPosition(0.0, 0.0);
    spTrack1.setScale(1.3, 1.3);
    spTrack1.setTexture(myMap.myMapTexture);

    double dt = 1.0/60.0;
    double dS = 0.0;
    double R;
    double dx;
    double dy;
    double dAlfa;
    double dCarRotationAngle;
    double Beta;
    
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
        }
        else if(myController.steerRight)
        {
            myCar.steerRight();
        }
        else
        {
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

        dS = myCar.speed*dt;
        R = 0;
        Beta = 0;
        dAlfa = 0;
        dx = 0;
        dy = dS;
        dCarRotationAngle = 0;
        if(myCar.steerAngle != 0)
        {
            Beta = 90-myCar.steerAngle;
            R = myCar.length*tan(Beta*M_PI/180);
            dAlfa = dS/R;
            dCarRotationAngle = dAlfa*180/M_PI;
            dx = R*(1-cos(dAlfa));
            dy = R*sin(dAlfa); 
        }
        std::cout<<dCarRotationAngle<<dx<<" "<<dy<<std::endl;

        if(myCar.steerAngle >= 0)
        {
            //transform.translate(0.0, 10.0);
            //spTrack1.move(0.0, 0.001*dy);
            //transform.rotate(-dAlfa, myCar.xPos, myCar.yPos);
            //spTrack1.rotate(dAlfa);
        }
        else
        {
            //spTrack1.move(0.0, 0.0001*dy);
            //transform.rotate(dAlfa, myCar.xPos, myCar.yPos);
            //spTrack1.rotate(dAlfa);
        }
        
        //text.setString(std::to_string(myCar.steerAngle));
        //text2.setString(std::to_string(myCar.speed*3600/1000));
        //text.setPosition(10,50);
        //text2.setPosition(10,10);
        window.clear();
        //window.draw(text);
        //window.draw(text2); 
        window.draw(spTrack1, mapTransform);
        window.draw(spMazda_rx7);
        window.display();
    }
    return 0;
}