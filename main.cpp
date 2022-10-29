#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cmath>
#include <string>
#include "Game.hpp"
#include "controller.hpp"
#include "car.hpp"
#include "map.hpp"
#include "driving_physic.hpp"
#include "dashboard.hpp"
#include "steering_wheel.hpp"

int main()
{
    Game game;
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
    sound.play();
    /////////////////////////////////////////
    
    while(game.isRunning())
    {
        game.updateSFMLEvents();
        
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
        myPhysic.updateCar(Mazda_rx7);
        //hudDashBoard.readCarData(&Mazda_rx7);
        //hudSteeringWheel.readCarData(&Mazda_rx7);
        //hudDashBoard.showData();
        //hudSteeringWheel.showData();
        Mazda_rx7.update();
        game.setCenter(Mazda_rx7.getXPos(), Mazda_rx7.getYPos());
        game.setRotation(Mazda_rx7.getAngle());
        game.setView();
        //////////////////////////////////////////////////////////
        //sound.setPitch(0.5 + Mazda_rx7.getCurrentRpm()/1000.0);
        /////////////////////////////////////////////////////////
        game.windowClear();
        game.windowDraw(Track1.getSprite());
        game.windowDraw(Mazda_rx7.getSprite());
        //window.draw(hudDashBoard.spGauge);
        //window.draw(hudDashBoard.spTip);
        //window.draw(hudSteeringWheel.sp);
        
        game.windowDisplay();
    }
    return 0;
}
