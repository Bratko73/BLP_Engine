#include "SFML/include/SFML/Graphics.hpp"
#include "Tile.h"
int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    sf::CircleShape shape2(50.f);
    shape.setFillColor(sf::Color::Red);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(shape);
        window.display();
    }
   
    return 0;
}
