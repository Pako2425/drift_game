#include "Game_State.hpp"

void Game_State::initVariables()
{
    this->view.reset(sf::FloatRect(0.0, 0.0, 1280, 960));
    this->view.rotate(0.0);
    this->player = new Player();
    this->trackMap = new TrackMap();
    
    sf::Texture texture;
    texture.loadFromFile("images/cars/mazda_rx7.png");
    this->textures["mazda_rx7"] = texture;
    texture.loadFromFile("images/tracks/track1.png");
    this->textures["track1"] = texture;
}

Game_State::Game_State(sf::RenderWindow* window) : State(window)
{
    this->initVariables();
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
