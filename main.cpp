#include <SFML/Graphics.hpp>
#include "controller.hpp"

int main()
{
    Controller myController;
    sf::RenderWindow window(sf::VideoMode(800,600), "game_window");
    sf::RectangleShape myCar(sf::Vector2f(120,50));
    int myCarx = 100;
    int myCary = 100;
    int carAngle = 0;
    myCar.setFillColor(sf::Color::Green);
    window.setFramerateLimit(60);
    //sf::Font font;
    //sf::Text text;
    //text.setFont(font);
    //text.setCharacterSize(30);
    //text.setFillColor(sf::Color::Green);
    //if(!font.loadFromFile("font_files/atwriter.ttf"))
    //{
    //    return EXIT_FAILURE;
    //}
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
        if(myController.gasPedal)
        {
            if(myCarx > 10)
            {
                myCarx -= 3;
            }
        }
        else if(myController.brakePedal)
        {
            if(myCarx < 790)
            {
                myCarx += 3;
            }
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
        window.clear();
        myCar.setPosition(myCarx,myCary);
        myCar.setRotation(carAngle);
        window.draw(myCar);
        //text.setPosition(50, 100);
        //window.draw(text);
        window.display();
    }

    return 0;
}