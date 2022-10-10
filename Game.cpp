#include "Game.hpp"

void Game::initVariables()
{
    this->window = nullptr;
    this->dt = 1.0/60.0;
}

void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(1280,960), "game_window");
    this->window->setFramerateLimit(60);
}

void Game::update()
{

}

void Game::render()
{

}

Game::Game()
{
    initVariables();
    initWindow();
}

Game::~Game()
{
    delete this->window;
}

bool Game::running()
{
    return this->window->isOpen();
}

void Game::updateEvents()
{
    while(this->window->pollEvent(this->sfEvent))
    {
        if(this->sfEvent.type == sf::Event::Closed)
        {
            this->window->close();
        }
    }
}