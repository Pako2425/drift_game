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
        
        if(myController.steerLeft)
        {
            myCar.steering++;
        }
        else if(myController.steerRight)
        {
            myCar.steering++;
        }
        
        if(myController.gasPedal)
        {
            myCar.gas = true;
        }
        else if(myController.brakePedal)
        {
            myCar.brake = true;
        }
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            if(myCary > 10)
            {
                myCary -= 3;
            }
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            if(myCary < 590)
            {
                myCary += 3;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            carAngle ++;
        }
        */
       myCar.gas = false;
       myCar.brake = false;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            myCar.gas = true;
            myCar.workOfEngine();
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        {
            myCar.brake = true;
            myCar.workOfEngine();
        }
        else
        {
            myCar.workOfEngine();
        }
        text.setString(std::to_string(myCar.currentEngineRpm));
        window.clear();
        revLine.setPosition(300,300);
        revLine.setRotation(110.0 + (float(myCar.currentEngineRpm) / 31.0));
        window.draw(revLine);
        //myCar.setPosition(myCarx, myCary);
        //myCar.setRotation(carAngle);
        //window.draw(myCar);
        text.setPosition(100, 100);
        //window.draw(text);
        window.display();
    }

    return 0;
}