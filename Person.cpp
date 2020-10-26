#include "Person.h"

Person::Person()
{
}

Person::Person(sf::Texture& image)
{
	sprite.setTexture(image);
	//��� ���� ����� ������ ������� ��������� � ������� ����, ���� ��� �� �������� ����������)
}

void Person::moveright()
{
	Person::dx = 0.1;
}

void Person::moveleft()
{
	Person::dx = -0.1;
}

//void Person::movedown()
//{
//	down_pressed = true;
//}

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

	if (!onGround) 
		dy = dy + 0.0005 * time;

	rect.top += dy * time;
	onGround = false;

	Collision(1);

	currentFrame += 0.005 * time;
	if (currentFrame > 6) currentFrame -= 6;

	if (dx > 0) 
		sprite.setTextureRect(sf::IntRect(1 * int(currentFrame), 1, 1, 1));       //������ ��������� ���� ����������
	if (dx < 0) 
		sprite.setTextureRect(sf::IntRect(1 * int(currentFrame) + 1, 1, -1, 1));  //������ ��������� ���� ����������

	sprite.setPosition(rect.left - offsetX, rect.top - offsetY);
	dx = 0;
}


// ���� �� �������� ������ �������� ����� ����� ���
void Person::Collision(int flag)
{
	for (int i = rect.top / 32; i < (rect.top + rect.height) / 32; i++)
		for (int j = rect.left / 32; j < (rect.left + rect.width) / 32; j++)
		{
			if (Map[i][j] == '|') //����� 
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
