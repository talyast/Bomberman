#pragma once
#include "Menus.h"

class GameController;

class MainMenu:public Menus
{
public:
	
	MainMenu();
	screens run();
	void openWindow() { m_isOpen = true; };
private:

	void loadImages();
	screens eventHandler();

	bool m_isOpen =true;

	sf::Texture m_textureStart;
	sf::Texture m_textureChoosePlayer;
	sf::Texture m_textureExit;
};

