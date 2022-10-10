#include "controller.hpp"
#include <SFML/Graphics.hpp>

void Controller::readInput()
{
    this->gasPedal = false;
    this->brakePedal = false;
    this->steerLeft = false;
    this->steerRight = false;
    this->handBrake = false;
    this->shiftUp = false;
    this->shiftDown = false;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        this->gasPedal = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        this->brakePedal = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        this->steerLeft = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        this->steerRight = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        this->shiftUp = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        this->shiftDown = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        this->handBrake = true;
    }
}
