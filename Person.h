#pragma once
class Person
{
private:
	bool left_pressed;
	bool right_pressed;
	bool down_pressed;
	bool upper_pressed;
	//���������� ��������� ������, ������ ����� ���� - ��������.
public:
	void moveright();
	void moveleft();
	void movedown();
	void moveupper();
	void update();
};

