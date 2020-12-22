#pragma once
#include "SFML/include/SFML/Graphics.hpp"
#include <vector>
class background
{
private:
	std::vector<std::string> ImageNames;
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
	void clearOffSet();
	void SetFont(std::string PathToFont);
	void ChangeText(int index, std::string text);
	void addTextObj(int kernel, std::string text, sf::Font font, sf::Vector2f Pos);
	void addTextObj(int kernel, std::string text, sf::Vector2f Pos);
	void addTexture(std::string name, std::string PathToFile);
	void addImageObj(std::string name, sf::Vector2f pos);
	void clearBg();
	void TextObjSetPosition(int index, sf::Vector2f Pos);
	void drawBackground(sf::RenderWindow& window, float offsetX);
	~background();
};

