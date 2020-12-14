#include "background.h"

background::background()
{
	BgColor = sf::Color(0, 0, 0, 255);
}

background::background(std::string PathToFont)
{
	StandartFont.loadFromFile(PathToFont);
	BgColor = sf::Color(0, 0, 0, 255);
}

void background::SetBgColor(sf::Color color)
{
	this->BgColor = color;
}

void background::addTextObj(int kernel, std::string text, sf::Font font)
{
	TextObj.push_back(sf::Text(text, font, kernel));
}

void background::addTextObj(int kernel, std::string text)
{
	TextObj.push_back(sf::Text(text, StandartFont, kernel));
}

void background::addImageObj(std::string PathToFile)
{
	sf::Texture texture;
	texture.loadFromFile(PathToFile);
	textures.push_back(texture);
	ImageObj.push_back(sf::Sprite(textures[textures.size()-1]));
}

void background::clearBg()
{
	ImageObj.clear();
	textures.clear();
	TextObj.clear();
}

void background::ImageObjSetPosition(int index, sf::Vector2f Pos)
{
	ImageObj[index].setPosition(Pos);
}

void background::TextObjSetPosition(int index, sf::Vector2f Pos)
{
	TextObj[index].setPosition(Pos);
}

void background::drawBackground(sf::RenderWindow& window, sf::Vector2f offset)
{
	window.clear(BgColor);
	for (int i = 0; i < ImageObj.size(); i++) {
		ImageObj[i].move(offset);
		window.draw(ImageObj[i]);
	}
	for (int i = 0; i < TextObj.size(); i++) {
		TextObj[i].move(offset);
		window.draw(TextObj[i]);
	}
}
