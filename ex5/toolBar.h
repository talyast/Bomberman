#pragma once
#include <SFML/Graphics.hpp>
class GameController;


class toolBar
{
	
public:
	toolBar();
	~toolBar();
	//void createToolBar();
	virtual void draw(sf::RenderWindow & m_window, int score, int life, int numOfBombs, int stage, int timer) = 0;
	virtual void createText() = 0;
protected:
	sf::Sprite m_toolBarSprite;
	sf::Font font;
	sf::Text text;
	
private:
	
};

