#include "Menu.h"

void Menu::MainMenu(sf::RenderWindow& window)
{
	sf::Texture startTexture, exitTexture,titleTexture, menuBackground;
	startTexture.loadFromFile("D:/Libraries/sourses/start.png");
	exitTexture.loadFromFile("D:/Libraries/sourses/exit.png");
	titleTexture.loadFromFile("D:/Libraries/sourses/title.png");
	menuBackground.loadFromFile("D:/Libraries/sourses/MainMenuBackground.jpg");
	sf::Sprite menuStart(startTexture), menuExit(exitTexture),menuTitle(titleTexture), menuBg(menuBackground);
	bool isMenu = 1;
	int menuNum = 1;
	menuTitle.setPosition(0, 0);
	menuStart.setPosition(200, 100);
	menuExit.setPosition(200, 150);	
	//menuBg.setPosition(0, 0);
	while (isMenu)
	{
		window.clear();		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

		}

		menuStart.setColor(sf::Color::White);
		menuExit.setColor(sf::Color::White);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			menuNum++;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			menuNum--;
		if (menuNum > 2)
			menuNum = 1;
		if (menuNum < 1)
			menuNum = 2;
		if (menuNum == 1) 
			menuStart.setColor(sf::Color::Red);
		if (menuNum == 2) 
			menuExit.setColor(sf::Color::Red);


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			if (menuNum == 1) 
				isMenu = false;
			//if (menuNum == 2) { window.draw(about); window.display(); while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)); }
			if (menuNum == 2) {
				window.close();
				isMenu = false; 
			}

		}

		window.draw(menuBg);
		window.draw(menuTitle);
		window.draw(menuStart);
		window.draw(menuExit);
		window.display();
	}
}

