#include "Game.hpp"

void Game::initVariables()
{
    this->window = NULL;
    this->view = NULL;
}

void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(1280,960), "Perfect Line");
    this->window->setFramerateLimit(60);
}

void Game::initView()
{
    this->view = new sf::View(sf::Vector2f(640,480), sf::Vector2f(1280,960));
}

Game::Game()
{
    this->initVariables();
    this->initWindow();
    this->initView();
}

Game::~Game()
{
    delete this->window;
    delete this->view;
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

void Game::run()
{
    this->updateSFMLEvents();
    this->update();
    this->render();
}

void Game::updateDt()
{
    this->dt = this->dtClock.restart().asSeconds();
}

void Game::setView()
{
    this->window->setView(*this->view);
}

void Game::setCenter(const double xPos, const double yPos)
{
    this->view->setCenter(xPos, yPos);
}

void Game::setRotation(const double angle)
{
    this->view->setRotation(angle);
}

void Game::windowClear()
{
    this->window->clear();
}

void Game::windowDraw(const sf::Sprite& sp) const
{
    this->window->draw(sp);
}

void Game::windowDisplay()
{
    this->window->display();
}
