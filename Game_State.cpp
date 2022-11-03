#include "Game_State.hpp"
#include <iostream>

void Game_State::initVariables()
{
    this->view.reset(sf::FloatRect(0.0, 0.0, 1280, 960));
    this->view.rotate(0.0);
    this->player = new Player();
    this->trackMap = new TrackMap();
    this->gasPedal = false;
    this->brakePedal = false;
    this->steerLeft = false;
    this->steerRight = false;

    sf::Texture texture;
    texture.loadFromFile("images/cars/mazda_rx7.png");
    this->textures["mazda_rx7"] = texture;
    texture.loadFromFile("images/tracks/track1.png");
    this->textures["track1"] = texture;
}

void Game_State::initPlayerSpriteComponent()
{
    (this->player->getSpriteComponent()->getSprite()).setTexture(this->textures["mazda_rx7"]);
    (this->player->getSpriteComponent()->getSprite()).setScale(0.2, 0.2);
    (this->player->getSpriteComponent()->getSprite()).setOrigin(textures["mazda_rx7"].getSize().x*0.5, textures["mazda_rx7"].getSize().y*0.85);
    (this->player->getSpriteComponent()->getSprite()).setPosition(this->player->getPositionComponent()->getPosition().x, this->player->getPositionComponent()->getPosition().y);
    (this->player->getSpriteComponent()->getSprite()).setRotation(this->player->getPositionComponent()->getAngle());
}

Game_State::Game_State(sf::RenderWindow* window) : State(window)
{
    this->initVariables();
    this->initPlayerSpriteComponent();
}

Game_State::~Game_State()
{
    delete this->player;
    delete this->trackMap;
}

void Game_State::endState()
{

}

void Game_State::input()
{
    this->gasPedal = false;
    this->brakePedal = false;
    this->steerLeft = false;
    this->steerRight = false;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        this->gasPedal = true;
        std::cout<<'g'<<std::endl;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        this->brakePedal = true;
        std::cout<<'b'<<std::endl;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        this->steerLeft = true;
        std::cout<<'l'<<std::endl;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        this->steerRight = true;
        std::cout<<'r'<<std::endl;
    }
}

void Game_State::updatePlayer()
{
    this->player->getSpriteComponent()->getSprite().setTexture(this->textures["mazda_rx7"]);
}

void Game_State::updateTrackMap()
{
    this->trackMap->getSpriteComponent()->getSprite().setTexture(this->textures["track1"]);
}

void Game_State::updateView()
{
    this->view.rotate(this->player->getPositionComponent()->getAngle());
}

void Game_State::update(const float& dt)
{
    this->updatePlayer();
    this->updateTrackMap();
    this->updateView();
}

void Game_State::render(sf::RenderTarget* target)
{
    target->setView(this->view);
    trackMap->render(target);
    player->render(target);
}
