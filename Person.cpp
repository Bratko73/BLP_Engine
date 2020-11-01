#include "Person.h"

Person::Person()
{
	//надо инициализировать animation
	offset.x = 0;
	offset.y = 0;
	//rect = sf::FloatRect(100, 180, 16, 16); //пока не знаем размеры(а надо бы)
	coordinates.x = 0.1;
	coordinates.y = 0.1;
}

Person::Person(std::string pathToFile)
{
	sf::Texture texture;
	texture.loadFromFile(pathToFile);
}

void Person::move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		coordinates.x = -0.1;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		coordinates.x = 0.1;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		if (onGround) {
			coordinates.y = -0.27;
			onGround = false;
		}
}

void Person::update(float time)
{
	rect.left += coordinates.x * time;

	if (!onGround)
		coordinates.y = coordinates.y + 0.0005 * time;

	rect.top += coordinates.y * time;
	onGround = false;

	/*currentFrame += time * 0.005;
		if (currentFrame > 3)
			currentFrame -= 3;*/ 

	/*if (coordinates.x > 0)
			sprite.setTextureRect(sf::IntRect(112 + 31 * int(currentFrame), 144, 16, 16));
		if (coordinates.x < 0)
			sprite.setTextureRect(sf::IntRect(112 + 31 * int(currentFrame) + 16, 144, -16, 16));*/ // Тема Сани

	sprite.setPosition(rect.left - offset.x, rect.top - offset.y); 

	coordinates.x = 0;

}

float Person::getX()
{
	return coordinates.x;
}

float Person::getY()
{
	return coordinates.y;
}

float Person::getOffsetX()
{
	return offset.x;
}

float Person::getOffsetY()
{
	return offset.y;
}

void Person::setOffsetX(float x)
{
	offset.x = x;
}


// пока не добавили модуль коллизий пусть лежит тут
/*void Person::Collision(int flag)
{
	for (int i = rect.top / 32; i < (rect.top + rect.height) / 32; i++)
		for (int j = rect.left / 32; j < (rect.left + rect.width) / 32; j++)
		{
			if (Map[i][j] == '|') //стена 
			{
				if ((dx > 0) && (flag == 0)) 
					rect.left = j * 32 - rect.width;
				if ((dx < 0) && (flag == 0)) 
					rect.left = j * 32 + 32;
				if ((dy > 0) && (flag == 1)) { 
					rect.top = i * 32 - rect.height;  
					dy = 0;   
					onGround = true; 
				}
				if ((dy < 0) && (flag == 1)) { 
					rect.top = i * 32 + 32;   
					dy = 0; 
				}
			}
		}
}*/
