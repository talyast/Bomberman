#pragma once
#include"toolBar.h"
class Stage :public toolBar
{
public:
	Stage();
	~Stage();
	void draw(sf::RenderWindow & m_window, int score, int life, int numOfBombs, int stage, int timer);
	void createText();
private:
	int m_stage = 0;
	sf::Texture m_stageTexture;
	

};

