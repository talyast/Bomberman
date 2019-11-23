#include "Score.h"
#include "GameController.h"


Score::Score()

{
	//m_scoreTexture.loadFromFile("image/score.png");
	m_scoreTexture.loadFromFile("images/score.png");
	m_toolBarSprite.setPosition({15.f,0.f });
	m_scoreTexture.setSmooth(true);
	m_toolBarSprite.setTexture(m_scoreTexture, false);
	/*sf::Text m_text;
	sf::Font m_font;
	m_font.loadFromFile("ALGER.TTF");
	std::string a = "life: ";
	m_text.setString(a);
	m_text.setPosition(30, 20);
	m_text.setCharacterSize(25);*/
	createText();


}


Score::~Score()
{
}



void Score::draw(sf::RenderWindow & m_window, int score, int life, int numOfBombs, int stage, int timer)
{

		m_window.draw(m_toolBarSprite);
		//m_score = m_game.getScore();
		text.setString(std::to_string(score));
		m_window.draw(text);
}

void Score::createText()
{
	text.setPosition({ 130,80 });
	text.setFont(font);
	text.setCharacterSize(20);
	text.setFillColor(sf::Color::White);
	text.setStyle(sf::Text::Bold);
	text.setLetterSpacing(1);
	
}
