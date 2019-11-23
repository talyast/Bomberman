#pragma once
#include "Menus.h"
class EndScreen :public Menus
{


public:
	screens run();
	EndScreen();
	void openWindow() { m_isOpen = true; };
	void setBackGround();

private:

	screens eventHandler();
	void loadImages();
	bool m_isOpen = true;
	sf::Texture m_textureBackGround;
	sf::Sprite m_spriteBackGround;
	sf::Texture m_texturePlayAgain;
	sf::Texture m_textureExit;
	sf::Sprite m_spritePlayeAgain;
	sf::Sprite m_spriteExit;
	bool m_player1 = false;
	bool m_player2 = false;

};

