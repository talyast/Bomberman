#pragma once
#include"toolBar.h"
class Timer :public toolBar
{
public:
	Timer();
	~Timer();

	void draw(sf::RenderWindow & m_window, int score, int life, int numOfBombs, int stage, int timer);
	
private:
	void createText();
	sf::Texture m_timerTexture;
	int m_time;
	
};

