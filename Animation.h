#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Animation
{
private:
	sf::Sprite sprite;
	//LEFT,RIGHT,UP,DOWN
	sf::Vector2f firstFrameCoordinates;
	sf::Vector2i frameSize;
	int countOfFrames;
	int currentFrame;
	float animationSpeed;
public:
	/*Animation(std::string pathToFile,int countOfFrames);
	void setFrameSize( sf::Vector2i size);
	void setAnimationParametres(int countOfFrames, sf::Vector2f firstFrameCoordinates);
	void update(const sf::Time& time);*/

};

