#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"

class Person
{
private:
	bool gravitationCheck; //� �������� ����������� ������� ������ �� ����� ���������� �����������
	sf::Vector2f coordinates;
	sf::FloatRect rect;
	bool onGround;
	//Animation animation;
	sf::Sprite sprite;
	//���������� ��������� ������, ������ ����� ���� - ��������.
public:
	Person();
	Person(std::string pathToFile);
	void move();
	void update(float time);
	// ���� �� �������� ������ �������� ����� ����� ���
	//void Collision(int flag);
};

