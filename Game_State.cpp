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
    this->turningRadius = 0.0;
    this->dCarRotationAngle = 0.0;
    this->newCarAngle = 0.0;
    this->newCarXPos = 0.0;
    this->newCarYPos = 0.0;
    this->dt = 1.0/60.0;

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
    //this->gasPedal = false;
    //this->brakePedal = false;
    //this->steerLeft = false;
    //this->steerRight = false;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        //this->gasPedal = true;
        this->player->getVelocityComponent()->accelerate();
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        //this->brakePedal = true;
        this->player->getVelocityComponent()->brake();
    }
    else
    {
        this->player->getVelocityComponent()->decelerate();
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        //this->steerLeft = true;
        this->player->getSteeringComponent()->steerLeft();
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        //this->steerRight = true;
        this->player->getSteeringComponent()->steerRight();
    }
    else
    {
        this->player->getSteeringComponent()->steerReturning();
    }
}

//-------------------------CAR_SECTION-----------------------------
void Game_State::calculateRadiusOfCarTurningCircle()
{
    double Beta = 0.0;
    if(std::abs(this->player->getSteeringComponent()->getSteerAngle()) > 0.6)
    {
        Beta = 90.0-std::abs(this->player->getSteeringComponent()->getSteerAngle());
        this->turningRadius =  this->player->getCarDimensionsComponent()->getLength() * tan(Beta*M_PI/180);
    }
    else
    {
        this->turningRadius = 0.0;
    }
}

void Game_State::calculateCarRotationAngle()
{
    double dAlfa = 0.0;
    if(this->turningRadius > 0)
    {
        dAlfa = this->player->getVelocityComponent()->getVelocity() * this->dt/this->turningRadius;
        this->dCarRotationAngle = dAlfa*180/M_PI;
    }
    else
    {
        this->dCarRotationAngle = 0.0;
    }
}

void Game_State::calculateNewCarAngle()
{
    if(this->player->getSteeringComponent()->getSteerAngle() < -0.6)
    {
        this->newCarAngle = -this->dCarRotationAngle;
    }
    else if(this->player->getSteeringComponent()->getSteerAngle() > 0.6)
    {
        this->newCarAngle = this->dCarRotationAngle;
    }
    else
    {
        this->newCarAngle = 0;
    }
}

void Game_State::calculateNewCarPosition()
{
    this->newCarXPos = 18.0 * this->player->getVelocityComponent()->getVelocity() * this->dt * sin(this->player->getPositionComponent()->getAngle() * M_PI/180);
    this->newCarYPos = -18.0 * this->player->getVelocityComponent()->getVelocity() * this->dt * cos(this->player->getPositionComponent()->getAngle() * M_PI/180);
}
//---------------------END_CAR_SECTION-------------------------------

void Game_State::updatePlayer()
{
    this->calculateRadiusOfCarTurningCircle();
    this->calculateCarRotationAngle();
    this->calculateNewCarAngle();
    this->calculateNewCarPosition();
    this->player->getPositionComponent()->move(this->newCarXPos, this->newCarYPos, this->newCarAngle);
    this->player->getSpriteComponent()->getSprite().setTexture(this->textures["mazda_rx7"]);
    this->player->getSpriteComponent()->getSprite().setPosition(this->player->getPositionComponent()->getPosition());
    this->player->getSpriteComponent()->getSprite().setRotation(this->player->getPositionComponent()->getAngle());
}

void Game_State::updateTrackMap()
{
    this->trackMap->getSpriteComponent()->getSprite().setTexture(this->textures["track1"]);
}

void Game_State::updateView()
{
    this->view.move(this->newCarXPos, this->newCarYPos);
    this->view.rotate(this->newCarAngle);
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
