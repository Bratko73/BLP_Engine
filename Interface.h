#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Interface
{
private:
	int score;
	float time;
	//int money;
	std::string level;
	sf::Font font;
	sf::Text titles[6];
	int countOfTitles;
public:
	Interface();
	Interface(std::string pathToFont, int score, std::string level, float time);
	Interface(std::string pathToFont);
	void increaceScore(int scoreIncrement);
	//void increaceMoney(int moneyIncrement);
	void changeLevel(std::string level);
	void updateTime(float time);
	void RestartTime();
	void RestartScore();
	void setTitlePosition(int item, sf::Vector2f Position);
	void setFont(std::string pathToFont);
	void draw(sf::RenderWindow& window);
};

//DOES NOT WORK!Leave HOPE everyone who enters here
