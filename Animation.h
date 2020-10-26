#pragma once
#include <SFML/Graphics.hpp>
#include <string>

enum Direction{LEFT,RIGHT,UP,DOWN};
class Animation
{
private:
	sf::Sprite sprite;
	float currentFrame;
public:
	Animation(std::string pathToFile);
	void update(Direction, float time);
};

