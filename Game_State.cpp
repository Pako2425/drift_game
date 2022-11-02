#include "Game_State.hpp"

void Game_State::initVariables()
{
    this->view.reset(sf::FloatRect(0.0, 0.0, 1280, 960));
    this->view.rotate(0.0);
    this->player = new Player();
    
    sf::Texture texture;
    texture.loadFromFile("images/cars/mazda_rx7.png");
    this->textures["mazda_rx7"] = texture;
}

Game_State::Game_State(sf::RenderWindow* window) : State(window)
{
    this->initVariables();
}

Game_State::~Game_State()
{
    
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

void Game_State::updateView()
{
    this->view.rotate(this->player->getPositionComponent()->getAngle());
}

void Game_State::update(const float& dt)
{
    this->updatePlayer();
    this->updateView();
}

void Game_State::render(sf::RenderTarget* target)
{
    target->setView(this->view);
    target->draw(this->player->getSpriteComponent()->getSprite());
}
