#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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
    Controller myController;
    sf::Font font;
    sf::Text text;
    sf::Text text2;
    text.setFont(font);
    text.setCharacterSize(50);
    text2.setFont(font);
    text2.setCharacterSize(50);
    text.setFillColor(sf::Color::Green);
    text2.setFillColor(sf::Color::Yellow);    
    font.loadFromFile("font_files/atwriter.ttf");
    Car Mazda_rx7(640, 480, 0, "images/cars/mazda_rx7_left30.png");
    Map Track1(4000.0, 200.0, -90.0, "images/tracks/track1.png");
    Driving_Physic myPhysic;
    text.setString(std::to_string(Mazda_rx7.steerAngle));
    text2.setString(std::to_string(Mazda_rx7.speed*3600/1000));
    text.setPosition(10,50);
    text2.setPosition(10,10);
    ////////////////////////////////////////
    sf::SoundBuffer buffer;
    buffer.loadFromFile("sounds/mazda_rx7_acceleration.wav");
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.setLoop(true);
    sound.setPitch(0.8);
    sound.play();

    //int car_gear = 1;
    //double car_idleRpm = 800.0;
    //double car_rpm;
    //double car_maxRpm = 7800.0;
    //double car_gearRatios[] = {3.683, 2.263, 1.397, 1.00, 0.862};
    //double car_rear_axle_ratio = 3.9;
    //double car_wheel_diameter = 0.68;
    //double car_wheel_circumference = M_PI*car_wheel_diameter;

    //std::string hud_gauge_path = "images/hud/rpm_and_speed_gauge.png";
    //std::string hud_tip_path = "images/hud/rpm_and_speed_tip.png";
    //sp_hud_steeringwheel.setPosition(200.0, 800.0);
    //sp_hud_steeringwheel.setScale(0.80, 0.80);

    //int x_gauge_center = 900.0;
    //int y_gauge_center = 650.0;
    //sp_hud_gauge.setScale(0.45, 0.45);
    //sp_hud_gauge.setPosition(x_gauge_center, y_gauge_center);
    
    //int x_tip_center = x_gauge_center;
    //int y_tip_center = y_gauge_center;
    //int xd = 0;
    //int yd = 0;
    //sp_hud_tip.setOrigin(264.87, 35.88);
    //sp_hud_tip.setScale(0.45, 0.45);
    //sp_hud_tip.setPosition(x_tip_center+141, y_tip_center+135); //313.33 300.00
    /////////////////////////////////////////
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
        Mazda_rx7.setPathToRightTexture();
        Mazda_rx7.loadTexture();
        Mazda_rx7.setTexture();
        //////////////////////////////////////////////////////////
        //sound.setPitch(car_rpm/1400.0);
        //sound.setPitch(0.5 + car_rpm/1000.0);
        //car_rpm = 800.0+(60.0*car_gearRatios[car_gear-1]*car_rear_axle_ratio)/(car_wheel_circumference)*Mazda_rx7.speed;
        //if(car_rpm >= car_maxRpm)
        //{
        //    car_gear+=1;
        //}
        //else if(car_rpm<car_maxRpm*0.60 && car_gear!=1)
        //{
        //    car_gear-=1;
        //}
        //else
        //{
        //    car_gear = car_gear;
        //}
        //std::cout<<car_rpm<<std::endl<<car_gear<<std::endl;
        /////////////////////////////////////////////////////////
        myPhysic.updateCarDataBase(&Mazda_rx7);
        myPhysic.updateMapDataBase(&Track1);
        myPhysic.moveMap(&Track1);
        window.clear();
        window.draw(Track1.sp);
        window.draw(Mazda_rx7.sp);
        /////////////////////////////////////////
        //sp_hud_steeringwheel.setRotation(Mazda_rx7.steerAngle*15.0);
        //window.draw(sp_hud_steeringwheel);
        //window.draw(sp_hud_gauge);
        //sp_hud_tip.setRotation(-90.0 + car_rpm/42.8);
        //window.draw(sp_hud_tip);
        /////////////////////////////////////////
        //window.draw(text);
        //window.draw(text2);
        window.display();
    }
    return 0;
}