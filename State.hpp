#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

//class for states like "Game State" and "Menu State"
//wykorzystywanie stanów jest dobrym sposobem na zarządzanie zasobami, jeżeli jesteśmy w menu to nie musimy
//ładować do pamięci wczytanych tekstur z gry. Analogicznie, będąc w grze nie musimy ładować tekstur menu.
//W stanach trzymać będziemy praktycznie całe zasoby gry; materiały wykorzystywane w grze.
//Nie będziemy tworzyli obiektu, ma to być klasa virtualna.

class State
{
private:
    std::vector<sf::Texture> textures;
    sf::RenderWindow* window;
public:
    State(sf::RenderWindow* window);
    virtual ~State();
    virtual void endState() = 0;
    virtual void update(const float& dt) = 0;
    virtual void render(sf::RenderTarget* target = nullptr) = 0;
};