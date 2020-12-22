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
public:
	Animation();
	Animation(std::string pathToFile);
	void setSpriteSheet(std::string pathToFile);
	void setAnimationParametres(sf::Vector2i size, sf::Vector2i firstFrameCoordinates, int countOfFrames, int rangeBetweenFrames, float speed);
	sf::Sprite update(float time);
	sf::Sprite mirrorUpdate(float time);
	void startOver();
	void setPosition(sf::Vector2f position);
	void setPosition(float x, float y);
	sf::Sprite getSprite();
	void makeInvisible();
	~Animation();
};

