#include "Animation.h"
#include<SFML/Graphics/Image.hpp>

/*Animation::Animation(std::string pathToFile)
{
	currentFrame = 0;
	sf::Texture texture;
	texture.loadFromFile(pathToFile);
	sprite.setTexture(texture);
}

void Animation::setFrameSize(sf::Vector2i size)
{
}*/




/*void Animation::update(Direction, float time)
{
	if (LEFT) {
		p.dir = 1; p.speed = 0.1;//dir =1 - ����������� �����, speed =0.1 - �������� ��������. �������� - ����� �� ��� ����� �� �� ��� �� �������� � ����� �� ���������� ������ ���
		currentFrame += 0.005 * time;
		if (currentFrame > 3) currentFrame -= 3;
		p.sprite.setTextureRect(sf::IntRect(96 * int(currentFrame), 96, 96, 96)); //����� ������ p ������ player ������ ������, ����� �������� (��������� �������� �����)
	}

	if (RIGHT) {
		p.dir = 0; p.speed = 0.1;//����������� ������, �� ����
		currentFrame += 0.005 * time;
		if (currentFrame > 3) currentFrame -= 3;
		p.sprite.setTextureRect(sf::IntRect(96 * int(currentFrame), 192, 96, 96)); //����� ������ p ������ player ������ ������, ����� �������� (��������� �������� �����)
	}

	if (UP) {
		p.dir = 3; p.speed = 0.1;//����������� ����, �� ����
		currentFrame += 0.005 * time;
		if (currentFrame > 3) currentFrame -= 3;
		p.sprite.setTextureRect(sf:: IntRect(96 * int(currentFrame), 288, 96, 96)); //����� ������ p ������ player ������ ������, ����� �������� (��������� �������� �����)

	}

	if (DOWN) { //���� ������ ������� ������� ����� ��� ���� ����� �
		p.dir = 2; p.speed = 0.1;//����������� �����, �� ����
		currentFrame += 0.005 * time; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. ������� 0.005 ����� �������� �������� ��������
		if (currentFrame > 3) currentFrame -= 3; //���������� �� ������ � ������� �� ������ ������������. ���� ������ � �������� ����� - ������������ �����.
		p.sprite.setTextureRect(sf::IntRect(96 * int(currentFrame), 0, 96, 96)); //���������� �� ����������� �. ���������� 96,96*2,96*3 � ����� 96

	}
} */
