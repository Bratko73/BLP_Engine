#include "SFML/include/SFML/Graphics.hpp"
#include "Tile.h"
#include "Animation.h"
#include"Person.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    sf::CircleShape shape2(50.f);
    shape.setFillColor(sf::Color::Red);
    Animation anim("D:/Git/BLP_Engine/Sourse/spritesheet.png");
    anim.setAnimationParametres(sf::Vector2i(45, 45), sf::Vector2i(1, 1), 12, 0.002);
    anim.setPosition(45, 0);
    Animation anim2("D:/Git/BLP_Engine/Sourse/spritesheet.png");
    anim2.setAnimationParametres(sf::Vector2i(45, 45), sf::Vector2i(1, 1), 12, 0.002);
    anim2.setPosition(45, 45);
    Animation Megaman("D:/Git/BLP_Engine/Sourse/MEGAMAN.png");
    Megaman.setAnimationParametres(sf::Vector2i(37, 40), sf::Vector2i(0, 50), 8, 0.001);
    Megaman.setPosition(0, 45);

    Person player("Ваша реклама(путь к картинке");

    sf::Clock clock;
    int move = 0;
    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        //time /= 4;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        anim.update(time);
        
        anim2.setPosition(45, 45);
        move += 0.5;
        anim2.mirrorUpdate(time);
        Megaman.update(time);

        player.move();
        player.update(time);
        if (player.getRectLeft() > 200/2)
            player.setOffsetX(player.getRectLeft - 200 / 2);


        window.clear();
        window.draw(anim.getSprite());
        window.draw(anim2.getSprite());
        window.draw(Megaman.getSprite());
        window.draw(player.getSprite());
        window.display();
    }
   
    return 0;
}
