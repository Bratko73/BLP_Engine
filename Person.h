#pragma once
class Person
{
private:
	bool left_pressed;
	bool right_pressed;
	bool down_pressed;
	bool upper_pressed;

	float dx, dy;
	sf::FloatRect rect;
	bool onGround;
	sf::Sprite sprite;
	float currentFrame;
	//���������� ��������� ������, ������ ����� ���� - ��������.
public:
	Person();
	Person(sf::Texture& image);
	void moveright();
	void moveleft();
	//void movedown();
	void Jump();
	void update(float time);
	void Collision(int flag);
	//�������� ����� ��� �������� �������������, ��� ��, ��� ������ ������ Collision
};

