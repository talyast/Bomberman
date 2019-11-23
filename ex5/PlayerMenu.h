
#include "Menus.h"


#pragma once
#include<SFML/Graphics.hpp>

class PlayerMenu :public Menus
{
public:
	screens run();
	PlayerMenu();
	void openWindow() { m_isOpen = true; };
	int getChosenPlayer();
	void setBackGround();

	
private:
	
	screens eventHandler();
	void loadImages();

	sf::Texture m_textureBackGround;
	sf::Sprite m_spriteBackGround;
	sf::Texture m_texturePlayer1;
	sf::Texture m_texturePlayer2;
	sf::Texture m_texturePlayer3;
	sf::Sprite m_spritePlayer1;
	sf::Sprite m_spritePlayer2;
	sf::Sprite m_spritePlayer3;

	bool m_isOpen = true;
	bool m_player1 = false;
	bool m_player2 = false;
	bool m_player3 = false;
	
};

