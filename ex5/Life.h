#pragma once
#include"toolBar.h"
class Life :public toolBar
{
public:
	Life();
	~Life();
	void draw(sf::RenderWindow &m_window, int score, int life, int numOfBombs, int stage, int timer);
	void createText();
private:
	sf::Texture m_lifeTexture;
	int m_life = 3;
};

