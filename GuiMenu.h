#include <SFML/Graphics.hpp>
#include <stack>
#pragma once
namespace gui
{
    class Menu : sf::Drawable
    {
    protected:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

        std::stack<sf::Drawable*> elements;

    public:
        //virtual Menu();

        virtual ~Menu() = 0;

        virtual void initMenu() = 0;

    private:
    };
}