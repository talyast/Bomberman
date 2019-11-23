#pragma once
#include"toolBar.h"
class NumOfBomb :public toolBar
{
public:
	NumOfBomb();
	~NumOfBomb();
	void draw(sf::RenderWindow & m_window, int score, int life, int numOfBombs, int stage, int timer);
	void createText();
private:
	sf::Texture m_bombTexture;
	int m_numOfBomb = 0;

	
};

