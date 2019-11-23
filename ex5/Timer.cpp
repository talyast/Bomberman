#include "Timer.h"
#include "GameController.h"


Timer::Timer()
	
{
	m_timerTexture.loadFromFile("images/timer.png");
	m_toolBarSprite.setPosition({ 845.f,0.f });
	m_timerTexture.setSmooth(true);
	m_toolBarSprite.setTexture(m_timerTexture, false);
	createText();
}


Timer::~Timer()
{
}

void Timer::draw(sf::RenderWindow & m_window, int score, int life, int numOfBombs, int stage, int timer)
{
	
	m_window.draw(m_toolBarSprite);
	if (timer == -1)
	{
		text.setPosition({ 930,80 });
		std::string a = "unlimited ";
		text.setString(a);
	}
	else
		text.setString(std::to_string(timer));
	m_window.draw(text);
}

void Timer::createText()
{
	text.setPosition({960,80 });
	text.setFont(font);
	text.setCharacterSize(20);
	text.setFillColor(sf::Color::White);
	text.setStyle(sf::Text::Bold);
	text.setLetterSpacing(1);
}
