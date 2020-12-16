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
	float currentFrame;
	int rangeBetweenFrames;
	float speed;
	//int distanceBetweenSprites;
public:
	Animation();
	Animation(std::string pathToFile);
	void setSpriteSheet(std::string pathToFile);
	void setAnimationParametres(sf::Vector2i size, sf::Vector2i firstFrameCoordinates, int countOfFrames = 0, int rangeBetweenFrames = 0, float speed = 0.005);
	sf::Sprite update(float time);
	sf::Sprite mirrorUpdate(float time);
	void startOver();
	void setPosition(sf::Vector2f position);
	void setPosition(float x, float y);
	sf::Sprite getSprite();
	void makeInvisible();
};

