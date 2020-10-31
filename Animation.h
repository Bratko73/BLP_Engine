#pragma once
#include <SFML/Graphics.hpp>
#include <string>

enum Direction{LEFT,RIGHT,UP,DOWN};
class Animation
{
private:
	sf::Sprite sprite;
	sf::Vector2f* firstFrameCoordinates[4];//LEFT,RIGHT,UP,DOWN
	sf::Vector2i* frameSize[4];//LEFT,RIGHT,UP,DOWN
	int* countOfFrames[4];//LEFT,RIGHT,UP,DOWN
	int currentFrame;
public:
	Animation(std::string pathToFile);
	void setCountOfFrames(Direction, int count);
	void setFirstFrameCoordinates(Direction, sf::Vector2f coordinates);
	void update(Direction, float time);
};

