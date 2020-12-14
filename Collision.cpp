#include "Collision.h"

void Collision::collision(bool flag, Person& p, GameMap& map)
{
	for (int i = p.getRectangleTop() / 16; i < (p.getRectangleTop() + p.getRectangleHeight()) / 16; i++)
		for (int j = p.getRectangleLeft() / 16; j < (p.getRectangleLeft() + p.getRectangleWidth()) / 16; j++)
		{
			if (map.GetLethality(j, i) == true)
				p.Death(250);
			if (map.get_Hardness(j,i))
			{
				if (p.getY() > 0 && flag == 1)
				{
					p.setRectangleTop(i * 16 - p.getRectangleHeight());
					p.getY() = 0;
					p.setOnGround(true);
				}
				if (p.getY() < 0 && flag == 1)
				{
					p.setRectangleTop(i * 16 + 16);
					p.getY() = 0;
				}
				if (p.getX() > 0 && flag == 0)
				{
					p.setRectangleLeft(j * 16 - p.getRectangleWidth());
				}
				if (p.getX() < 0 && flag == 0)
				{
					p.setRectangleLeft(j * 16 + 16);
				}
			}

		}
}

bool Collision::npcCollision(bool flag, Enemy& n, GameMap& map)
{
	for (int i = n.getRectangleTop() / 16; i < (n.getRectangleTop() + n.getRectangleHeight()) / 16; i++)
		for (int j = n.getRectangleLeft() / 16; j < (n.getRectangleLeft() + n.getRectangleWidth()) / 16; j++)
			if (map.get_Hardness(j, i) == true)
			{
				if (n.getY() > 0 && flag == 1)
				{
					n.setRectangleTop(i * 16 - n.getRectangleHeight());
					n.getY() = 0;
					n.setOnGround(true);
				}
				if (n.getY() < 0 && flag == 1)
				{
					n.setRectangleTop(i * 16 + 16);
					n.getY() = 0;
				}
				if (n.getX() > 0 && flag == 0)
				{
					n.setRectangleLeft(j * 16 - n.getRectangleWidth());
					return true;
				}
				else if (n.getX() < 0 && flag == 0)
				{
					n.setRectangleLeft(j * 16 + 16);
					return true;
				}

			}
	return false;
}