#pragma once
#include "SFML/include/SFML/Graphics.hpp"
#include <vector>
class background
{
private:
	std::vector<sf::Sprite>ImageObj;
	std::vector<sf::Texture> textures;
	std::vector<sf::Text> TextObj;
	sf::Font StandartFont;
	sf::Color BgColor;
	float offset;
public:
	background();
	background(std::string PathToFont);
	void SetBgColor(sf::Color color);
	void SetFont(std::string PathToFont);
	void addTextObj(int kernel, std::string text, sf::Font font);
	void addTextObj(int kernel, std::string text);
	void addImageObj(std::string PathToFile);
	void clearBg();
	void ImageObjSetPosition(int index, sf::Vector2f Pos);
	void TextObjSetPosition(int index, sf::Vector2f Pos);
	void drawBackground(sf::RenderWindow& window, float offsetX);
};

