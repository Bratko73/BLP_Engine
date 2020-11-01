#include "SFML/include/SFML/Graphics.hpp"
#include "Animation.h"
#include"GameMap.h"
int main()
{
    sf::Vector2f size_of_field(300, 300);
    sf::RenderWindow window(sf::VideoMode(size_of_field.x, size_of_field.y), "MapTest");
    sf::Vector2f Start(1, 1);
    sf::Vector2f PosInFile(34, 68);
    sf::Vector2u tileSize(15, 15);
    sf::Vector2f Size_Of_Rect(10,10);
    GameMap map(Start, "C:/Users/Марк/source/repos/Bratko73/BLP_Engine/Sourse/tileset.png" , PosInFile,  window,  tileSize);
    map.SetRect(Start, Size_Of_Rect);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        } 
        window.clear();
        map.DrawMap(window);
        window.display();
    }
   
    return 0;
}
