#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cmath>
#include <string>
#include "controller.hpp"
#include "car.hpp"
#include "map.hpp"
#include "driving_physic.hpp"
#include "dashboard.hpp"
#include "steering_wheel.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280,960), "game_window");
    window.setFramerateLimit(60);
    Controller myController;    
    Car Mazda_rx7(640, 480, 0, "images/cars/mazda_rx7_left30.png");
    Map Track1(0.0, 0.0, "images/tracks/track1.png");
    Driving_Physic myPhysic;
    //Dashboard hudDashBoard(900.0, 650.0, "images/hud/rpm_and_speed_gauge.png", "images/hud/rpm_and_speed_tip.png", 0.45);
    //SteeringWheel hudSteeringWheel(160.0, 800.0, "images/hud/steering_wheel.png");
    ////////////////////////////////////////
    sf::SoundBuffer buffer;
    buffer.loadFromFile("sounds/mazda_rx7_acceleration.wav");
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.setLoop(true);
    sound.setPitch(0.8);
    //sound.play();
    /////////////////////////////////////////
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
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
        myPhysic.moveCar(&Mazda_rx7);
        //hudDashBoard.readCarData(&Mazda_rx7);
        //hudSteeringWheel.readCarData(&Mazda_rx7);
        //hudDashBoard.showData();
        //hudSteeringWheel.showData();
        Mazda_rx7.update();
        //delete?
        //Mazda_rx7.setPathToRightTexture();
        //Mazda_rx7.loadTexture();
        //Mazda_rx7.setTexture();
        //Mazda_rx7.setPosition();
        //Mazda_rx7.setRotation();
        
        //////////////////////////////////////////////////////////
        //sound.setPitch(car_rpm/1400.0);
        //sound.setPitch(0.5 + car_rpm/1000.0);
        /////////////////////////////////////////////////////////
        window.clear();
        window.draw(Track1.sp);
        window.draw(Mazda_rx7.sp);
        //window.draw(hudDashBoard.spGauge);
        //window.draw(hudDashBoard.spTip);
        //window.draw(hudSteeringWheel.sp);
        //window.draw(text);
        //window.draw(text2);
        window.display();
    }
    return 0;
}
