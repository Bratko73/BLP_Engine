#pragma once
#include <SFML/Graphics.hpp>

class Person
{
private:
	bool gravitationCheck; //� �������� ����������� ������� ������ �� ����� ���������� �����������
	float dx;
	float dy;
	sf::FloatRect rect;
	bool onGround;
	sf::Sprite sprite;
	//���������� ��������� ������, ������ ����� ���� - ��������.
public:
	Person();
	Person(std::string pathToFile);
	// � ������ ����� �������� ����� ������������ ������������� ����� ��������
	void moveRight();
	void moveLeft();
	void moveDown();
	void moveUp();
	void Jump();
	void update(float time);
	// ���� �� �������� ������ �������� ����� ����� ���
	//void Collision(int flag);
};

