#include "controller.hpp"
#include <SFML/Graphics.hpp>

void Controller::readInput()
{
    Controller::gasPedal = false;
    Controller::brakePedal = false;
    Controller::steerLeft = false;
    Controller::steerRight = false;
    Controller::handBrake = false;
    Controller::shiftUp = false;
    Controller::shiftDown = false;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        Controller::gasPedal = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        Controller::brakePedal = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        Controller::steerLeft = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        Controller::steerRight = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        Controller::shiftUp = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        Controller::shiftDown = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        Controller::handBrake = true;
    }
}
