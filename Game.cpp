#include "Game.hpp"
#include "Game_State.hpp"

void Game::initVariables()
{
    this->window = NULL;
}

void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(1280,960), "Perfect Line");
    this->window->setFramerateLimit(60);
}

void Game::initStates()
{
    this->states.push(new Game_State(this->window));
}

Game::Game()
{
    this->initVariables();
    this->initWindow();
    this->initStates();
}

Game::~Game()
{
    delete this->window;
    while(!this->states.empty())
    {
        delete this->states.top();
        this->states.pop();
    }
}

bool Game::isRunning()
{
    return this->window->isOpen();
}

void Game::updateSFMLEvents()
{
    while(this->window->pollEvent(this->event))
    {
        if(this->event.type == sf::Event::Closed)
        {
            this->window->close();
        }
    }
}

void Game::updateDt()
{
    this->dt = this->dtClock.restart().asSeconds();
}

void Game::update()
{
    this->updateSFMLEvents();
    this->updateDt();
    if(!this->states.empty())
    {
        this->states.top()->update(this->dt);
    }
}

void Game::render()
{
    if(!this->states.empty())
    {
        this->window->clear();

        this->states.top()->render(this->window);
        
        this->window->display();
    }
}

void Game::run()
{
    this->update();
    this->render();
}
