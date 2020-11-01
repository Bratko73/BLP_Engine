#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Animation
{
private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2i firstFrameCoordinates;
	sf::Vector2i frameSize;
	int countOfFrames;
	int currentFrame;
	float speed;
public:
	Animation(std::string pathToFile);
	void setAnimationParametres(sf::Vector2i size, sf::Vector2i firstFrameCoordinates, int countOfFrames = 0, float speed = 0.1);
	sf::Sprite update(float time);
	void startOver();
};

