#include "Animation.h"
#include<SFML/Graphics/Image.hpp>

Animation::Animation(std::string pathToFile)
{
	this->texture.loadFromFile(pathToFile);
	this->sprite.setTexture(this->texture);
	this->speed = 0.1;
	this->currentFrame = 0;
	this->firstFrameCoordinates.x = 0;
	this->firstFrameCoordinates.y = 0;
	this->countOfFrames = 0;
	this->frameSize.x = 0;
	this->frameSize.y = 0;
}

void Animation::setAnimationParametres(sf::Vector2i size, sf::Vector2i firstFrameCoordinates, int countOfFrames = 0, float speed = 0.1)
{
	this->frameSize = size;
	this->firstFrameCoordinates = firstFrameCoordinates;
	this->countOfFrames = countOfFrames;
	this->speed = speed;
}

sf::Sprite Animation::update(float time)
{
	int line = 1;
	int framesInLine = texture.getSize().x / frameSize.x;
	currentFrame += 0.005 * time;
	if (currentFrame > countOfFrames) 
		currentFrame -= countOfFrames;
	if (framesInLine < countOfFrames)
		line = currentFrame / framesInLine;
	sprite.setTextureRect(sf::IntRect(firstFrameCoordinates.x * int(currentFrame), firstFrameCoordinates.y*line, frameSize.x, frameSize.y));
	return sprite;
}

void Animation::startOver()
{
	int line = 1;
	currentFrame = 0;
	sprite.setTextureRect(sf::IntRect(firstFrameCoordinates.x * int(currentFrame), firstFrameCoordinates.y * line, frameSize.x, frameSize.y));
}

void Animation::setPosition(sf::Vector2f position)
{
	sprite.setPosition(position);
}

void Animation::setPosition(float x, float y)
{
	sprite.setPosition(x, y);
}
