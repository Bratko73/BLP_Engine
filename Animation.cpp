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
		p.dir = 1; p.speed = 0.1;//dir =1 - направление вверх, speed =0.1 - скорость движения. Заметьте - время мы уже здесь ни на что не умножаем и нигде не используем каждый раз
		currentFrame += 0.005 * time;
		if (currentFrame > 3) currentFrame -= 3;
		p.sprite.setTextureRect(sf::IntRect(96 * int(currentFrame), 96, 96, 96)); //через объект p класса player меняем спрайт, делая анимацию (используя оператор точку)
	}

	if (RIGHT) {
		p.dir = 0; p.speed = 0.1;//направление вправо, см выше
		currentFrame += 0.005 * time;
		if (currentFrame > 3) currentFrame -= 3;
		p.sprite.setTextureRect(sf::IntRect(96 * int(currentFrame), 192, 96, 96)); //через объект p класса player меняем спрайт, делая анимацию (используя оператор точку)
	}

	if (UP) {
		p.dir = 3; p.speed = 0.1;//направление вниз, см выше
		currentFrame += 0.005 * time;
		if (currentFrame > 3) currentFrame -= 3;
		p.sprite.setTextureRect(sf:: IntRect(96 * int(currentFrame), 288, 96, 96)); //через объект p класса player меняем спрайт, делая анимацию (используя оператор точку)

	}

	if (DOWN) { //если нажата клавиша стрелка влево или англ буква А
		p.dir = 2; p.speed = 0.1;//направление вверх, см выше
		currentFrame += 0.005 * time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
		if (currentFrame > 3) currentFrame -= 3; //проходимся по кадрам с первого по третий включительно. если пришли к третьему кадру - откидываемся назад.
		p.sprite.setTextureRect(sf::IntRect(96 * int(currentFrame), 0, 96, 96)); //проходимся по координатам Х. получается 96,96*2,96*3 и опять 96

	}
} */
