#include "Interface.h"

Interface::Interface()
{
	this->score = 0;
	this->time = 999;
	this->money = 0;
	this->level = "1-1";
	this->countOfTitles = 8;
}

Interface::Interface(std::string pathToFont, int score, std::string level, float time)
{

	this->score = score;
	this->time = time;
	this->money = money;
	this->level = level;
	this->countOfTitles = 8;
	font.loadFromFile(pathToFont);
	for (int i = 0; i < countOfTitles; i++) {
		titles[i].setFont(font);
	}
	titles[0].setString("000000");
	titles[1].setString(level);
	titles[2].setString("999");
	titles[3].setString("MARIO");
	titles[4].setString("WORLD");
	titles[5].setString("TIME");
	titles[6].setString("00");
	titles[7].setString("COINS");
}

Interface::Interface(std::string pathToFont)
{
	this->score = 0;
	this->time = 999;
	this->money = 0;
	this->level = "1-1";
	this->countOfTitles = 8;
	font.loadFromFile(pathToFont);
	for (int i = 0; i < countOfTitles; i++) {
		titles[i].setFont(font);
	}
	titles[0].setString("000000");
	titles[1].setString(level);
	titles[2].setString("400");
	titles[3].setString("MARIO");
	titles[4].setString("WORLD");
	titles[5].setString("TIME");
	titles[6].setString("0");
	titles[7].setString("MONEY");
}

void Interface::increaceScore(int scoreIncrement)
{
	this->score += scoreIncrement;
	if (score >= 1000000)
		score = 999999;
	std::string score = std::to_string(this->score);
	int strScoreSize = 6 - score.size();
	for (int i = 0; i < strScoreSize; i++)
		score = '0' + score;
	std::string temp = score;
	titles[0].setString(score);
}

void Interface::increaceMoney(int moneyIncrement)
{
	this->money += moneyIncrement;
	if (money >= 100)
		money = 99;
	titles[6].setString(std::to_string(money));
}

void Interface::changeLevel(std::string level)
{
	this->level = level;
	titles[1].setString(this->level);
}

void Interface::updateTime(float time)
{
	this->time -= time;
	titles[2].setString(std::to_string(int(this->time)));

}

void Interface::RestartTime()
{
	this->time = 400;
	titles[2].setString(std::to_string(int(this->time)));
}

void Interface::RestartScore()
{
	titles[0].setString("000000");
	this->score = 0;

}

void Interface::RestartMoney()
{
	this->money = 0;
	titles[6].setString(std::to_string(money));
}

float& Interface::getTime()
{
	return this->time;
}

void Interface::setTitlePosition(int item, sf::Vector2f Position)
{
	titles[item].setPosition(Position);
}

void Interface::setFont(std::string pathToFont)
{
	font.loadFromFile(pathToFont);
}

void Interface::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < countOfTitles; i++)
		window.draw(titles[i]);
}
