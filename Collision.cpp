#include "Collision.h"


void Collision::collision(bool flag, Person& p, sf::String Map[])
{

	for (int i = p.getRectTop() / 16; i < (p.getRectTop() + p.getRectHeight()) / 16; i++)
		for (int j = p.getRectLeft() / 16; j < (p.getRectLeft() + p.getRectWidth()) / 16; j++)
		{
			if ((Map[i][j] == 'P') || (Map[i][j] == 'k') || (Map[i][j] == '0') || (Map[i][j] == 'r') || (Map[i][j] == 't'))
			{
				if (p.getY() > 0 && flag == 1)
				{
					p.setRectTop(i * 16 - p.getRectHeight());
					p.getY() = 0;
					p.setOnGround(true);
				}
				if (p.getY() < 0 && flag == 1)
				{
					p.setRectTop(i * 16 + 16);
					p.getY() = 0;
				}
				if (p.getX() > 0 && flag == 0)
				{
					p.setRectLeft(j * 16 - p.getRectWidth());
				}
				if (p.getX() < 0 && flag == 0)
				{
					p.setRectLeft(j * 16 + 16);
				}
			}
		}
}

bool Collision::npcCollision(Enemy& n, sf::String Map[])
{
	for (int i = n.getRectTop() / 16; i < (n.getRectTop() + n.getRectHeight()) / 16; i++)
		for (int j = n.getRectLeft() / 16; j < (n.getRectLeft() + n.getRectWidth()) / 16; j++)
			if ((Map[i][j] == 'P') || (Map[i][j] == 'k') || (Map[i][j] == '0') || (Map[i][j] == 'r') || (Map[i][j] == 't'))
			{
				if (n.getX() > 0)
				{
					n.setRectLeft(j * 16 - n.getRectWidth());
					return 1;
				}
				else if (n.getX() < 0)
				{
					n.setRectLeft(j * 16 + 16);
					return 1;
				}

			}
	return 0;
}