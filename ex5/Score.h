#pragma once
#include"toolBar.h"
class Score :public toolBar
{
public:
	Score();
	~Score();
	void draw(sf::RenderWindow & m_window, int score, int life, int numOfBombs, int stage, int timer);
	void createText();
	
private:
	int m_score;
	sf::Texture m_scoreTexture;
	
};

