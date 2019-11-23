#pragma once
#include<SFML/Graphics.hpp>
#include "Macros.h"

class Menus
{
public:
	
	Menus();
	void initWindow(sf::RenderWindow *window);
	virtual screens run() = 0;
	virtual screens eventHandler() = 0;
	void setBackGroundMenu(sf::Sprite &spriteBackGround, sf::Texture &m_textureBackGround);

	~Menus();
protected:
	
	sf::Texture m_textureBackGround;
	sf::Sprite m_spriteBackGround;
	sf::Sprite m_sprite;
	sf::Sprite m_sprite2;
	sf::Sprite m_sprite3;
	sf::RenderWindow* m_window ;
};

