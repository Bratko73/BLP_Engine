#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"

class Person
{
private:
	sf::Vector2f offset;
	sf::Vector2f coordinates;
	sf::FloatRect rect;
	bool onGround;
	Animation animation;
	sf::Sprite sprite;
	//Необходима доработка класса, данная часть кода - набросок.
public:
	Person();
	Person(std::string pathToFile);

	void move();
	void update(float time);


	float getX();
	float getY();
	float getOffsetX();
	float getOffsetY();
	float getRectLeft();
	float getRectLeft();
	float getRectTop();
	float getRectHeight();
	float getRectWidth();
	bool getOnGround();


	void setOffsetX(float x);
	void setOffsetY(float y);
	void setOnGround(bool val);
	void setRectLeft(float left);
	void setRectTop(float top);
	void setRectHeight(float height);
	void setRectWidth(float width);

};

