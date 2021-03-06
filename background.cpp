#include "background.h"

background::background()
{
	BgColor = sf::Color(0, 0, 0, 255);
	offset = 0;
}

background::background(std::string PathToFont)
{
	StandartFont.loadFromFile(PathToFont);
	BgColor = sf::Color(0, 0, 0, 255);
	offset = 0;
}

void background::SetBgColor(sf::Color color)
{
	this->BgColor = color;
}

void background::clearOffSet()
{
	offset = 0;
}

void background::SetFont(std::string PathToFont)
{
	StandartFont.loadFromFile(PathToFont);
}

void background::ChangeText(int index, std::string text)
{
	if (index < TextObj.size())
		TextObj[index].setString(text);
}

void background::addTextObj(int kernel, std::string text, sf::Font font, sf::Vector2f Pos)
{
	TextObj.push_back(sf::Text(text, font, kernel));
	TextObj[TextObj.size() - 1].setPosition(Pos);
}

void background::addTextObj(int kernel, std::string text, sf::Vector2f Pos)
{
	TextObj.push_back(sf::Text(text, StandartFont, kernel));
	TextObj[TextObj.size() - 1].setPosition(Pos);
}

void background::addTexture(std::string name, std::string PathToFile)
{
	ImageNames.push_back(name);
	sf::Texture texture;
	texture.loadFromFile(PathToFile);
	textures.push_back(texture);
}

void background::addImageObj(std::string name, sf::Vector2f pos)
{
	for(int i = 0; i < textures.size(); i++)
		if (ImageNames[i] == name) {
			ImageObj.push_back(sf::Sprite(textures[i]));
			ImageObj[ImageObj.size() - 1].setPosition(pos);
		}
}

void background::clearBg()
{
	ImageNames.clear();
	ImageObj.clear();
	textures.clear();
	TextObj.clear();
}

void background::TextObjSetPosition(int index, sf::Vector2f Pos)
{
	if (index < TextObj.size())
		TextObj[index].setPosition(Pos);
}

void background::drawBackground(sf::RenderWindow& window, float offsetX)
{
	float tempOffset = offsetX - offset;
	offset = offsetX;
	window.clear(BgColor);
	for (int i = 0; i < ImageObj.size(); i++) {
		ImageObj[i].move(sf::Vector2f(-tempOffset,0));
		window.draw(ImageObj[i]);
	}
	for (int i = 0; i < TextObj.size(); i++) {
		TextObj[i].move(sf::Vector2f(-tempOffset, 0));
		window.draw(TextObj[i]);
	}
}

background::~background()
{
}
