#include "NumOfBomb.h"
#include "GameController.h"



NumOfBomb::NumOfBomb()

{
	m_bombTexture.loadFromFile("images/bombs.png");
	m_toolBarSprite.setPosition({ 430.f,-5.f });
	m_bombTexture.setSmooth(true);
	m_toolBarSprite.setTexture(m_bombTexture, false);
	createText();
}


NumOfBomb::~NumOfBomb()
{
}

void NumOfBomb::draw(sf::RenderWindow & m_window, int score, int life, int numOfBombs, int stage, int timer)
{
	m_window.draw(m_toolBarSprite);
	if (numOfBombs == -1)
	{
		text.setPosition({ 510,80 });
		std::string a = "unlimited ";
		text.setString(a);
	}
	//text.setString("unlimited");
	else
		text.setString(std::to_string(numOfBombs));
	m_window.draw(text);
}

void NumOfBomb::createText()
{
	text.setPosition({ 550,80 });
	text.setFont(font);
	text.setCharacterSize(20);
	text.setFillColor(sf::Color::White);
	text.setStyle(sf::Text::Bold);
	text.setLetterSpacing(1);
}
