#include "Person.h"

Person::Person()
{
}

Person::Person(std::string pathToFile)
{
	sf::Texture texture;
	texture.loadFromFile(pathToFile);
}

void Person::moveRight()
{
	Person::dx = 0.1;
}

void Person::moveLeft()
{
	Person::dx = -0.1;
}

void Person::moveDown()
{
	Person::dy = 0.1;
}

void Person::moveUp()
{
	Person::dy = -0.1;
}

void Person::Jump()
{
	if (Person::onGround) { 
		Person::dy = -0.35; 
		Person::onGround = false; 
	}
}

void Person::update(float time)
{
	rect.left += dx * time;
	Collision(0);

	if (!gravitationCheck) {
		if (!onGround)
			dy = dy + 0.0005 * time;
	}

	rect.top += dy * time;
	onGround = false;

	Collision(1);

	currentFrame += 0.005 * time;
	if (currentFrame > 6) currentFrame -= 6;

	if (dx > 0) 
		sprite.setTextureRect(sf::IntRect(1 * int(currentFrame), 1, 1, 1));       //размер персонажа пока неизвестен
	if (dx < 0) 
		sprite.setTextureRect(sf::IntRect(1 * int(currentFrame) + 1, 1, -1, 1));  //размер персонажа пока неизвестен

	sprite.setPosition(rect.left, rect.top);

	dx = 0;

	if (gravitationCheck)
		dy = 0;
}


// пока не добавили модуль коллизий пусть лежит тут
void Person::Collision(int flag)
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
}
