#include "Person.h"

Person::Person()
{
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
	//Collision(0);

	if (!gravitationCheck) {
		if (!onGround)
			coordinates.y = coordinates.y + 0.0005 * time;
	}

	rect.top += coordinates.y * time;
	onGround = false;
	//Collision(1);

	if (coordinates.x > 0)
		sprite.setTextureRect(sf::IntRect(1, 1, 1, 1));       //размер персонажа пока неизвестен

	sprite.setPosition(rect.left, rect.top);

	coordinates.x = 0;

	if (gravitationCheck)
		coordinates.y = 0;
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
