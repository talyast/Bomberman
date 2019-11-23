#include "Stage.h"
#include "GameController.h"



Stage::Stage()
	
{
	m_stageTexture.loadFromFile("images/stage.png");
	m_toolBarSprite.setPosition({ 640.f,2.f });
	m_stageTexture.setSmooth(true);
	m_toolBarSprite.setTexture(m_stageTexture, false);
	createText();
}


Stage::~Stage()
{
}

void Stage::draw(sf::RenderWindow & m_window, int score, int life, int numOfBombs, int stage, int timer)
{
	m_window.draw(m_toolBarSprite);
//	m_stage = m_game.getstage();
	text.setString(std::to_string(stage));
	m_window.draw(text);
}

void Stage::createText()
{
	text.setPosition({ 770,80 });
	text.setFont(font);
	text.setCharacterSize(20);
	text.setFillColor(sf::Color::White);
	text.setStyle(sf::Text::Bold);
	text.setLetterSpacing(1);
}
