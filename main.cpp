#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(400,400), "game_window");
    window.setFramerateLimit(60);
    sf::Font font;
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::Green);
    if(!font.loadFromFile("font_files/atwriter.ttf"))
    {
        return EXIT_FAILURE;
    }
    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        window.clear();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            text.setString("Move left!");
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            text.setString("Move right!");
        }
        else
        {
            text.setString(" ");
        }
        text.setPosition(50, 100);
        window.draw(text);
        window.display();
    }

    return 0;
}