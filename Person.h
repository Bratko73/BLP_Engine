#pragma once
#include <SFML/Graphics.hpp>

class Person
{
private:
	bool left_pressed;
	bool right_pressed;
	bool down_pressed;
	bool upper_pressed;
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
	void Collision(int flag);
	//�������� ����� ��� �������� �������������, ��� ��, ��� ������ ������ Collision
};

