#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "Why are you GAY?!");
    sf::CircleShape shape(100.f);
    sf::CircleShape shape2(50.f);
    shape.setFillColor(sf::Color::Magenta);
    sf::CircleShape shape3(50.f);
    sf::CircleShape shape4(50.f);
    sf::CircleShape shape5(50.f);
    sf::CircleShape shape6(5.f);
    sf::CircleShape shape7(25.f);
    sf::CircleShape shape8(5.f);
    sf::CircleShape shape9(5.f);
    shape6.setFillColor(sf::Color::Black);
    shape7.setFillColor(sf::Color::Black);
    shape8.setFillColor(sf::Color::Black);
    shape9.setFillColor(sf::Color::Black);
    sf::Vector2f fuckinslave(150, 25);
    sf::Vector2f fuckyou(75, 100);
    sf::Vector2f shitfuck(40, 50);
    sf::Vector2f fuckyoushitslave(60, 50);
    shape6.setPosition(fuckinslave);
    shape7.setPosition(fuckyou);
    shape8.setPosition(shitfuck);
    shape9.setPosition(fuckyoushitslave);
    sf::Vector2f fuck(100, 0);
    shape4.setFillColor(sf::Color::Magenta);
    shape3.setPosition(fuck);
    sf::Vector2f shit(50, 50);
    shape4.setPosition(shit);

    sf::Vector2f slave(50, 60);
    shape5.setPosition(slave);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        shape7.move(0.001, -0.001);
        window.clear();
        window.draw(shape);
        window.draw(shape2);
        window.draw(shape3);
        window.draw(shape5);
        window.draw(shape4);
        window.draw(shape6);
        window.draw(shape7);
        window.draw(shape8);
 //       window.draw(shape9);
        window.display();
    }

    return 0;
}
