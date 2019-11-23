#include "Life.h"
#include "GameController.h"



Life::Life()

{
	m_lifeTexture.loadFromFile("images/life.png");
	m_toolBarSprite.setPosition({ 250.f,15.f });
	m_lifeTexture.setSmooth(true);
	m_toolBarSprite.setTexture(m_lifeTexture, false);
	createText();
}


Life::~Life()
{
}

void Life::draw(sf::RenderWindow & m_window, int score, int life, int numOfBombs, int stage, int timer)
{
	m_window.draw(m_toolBarSprite);
	//m_life = m_game.getLife();
	text.setString(std::to_string(life));
	m_window.draw(text);

	
}

void Life::createText()
{
	/*text.setPosition({ 0,0 });
	text.setFont(font);
	text.setCharacterSize(20);
	text.setFillColor(sf::Color::White);
	text.setStyle(sf::Text::Bold);
	text.setLetterSpacing(1);*/

	text.setPosition({ 350,80 });
	text.setFont(font);
	text.setCharacterSize(20);
	text.setFillColor(sf::Color::White);
	text.setStyle(sf::Text::Bold);
	text.setLetterSpacing(1);


}
