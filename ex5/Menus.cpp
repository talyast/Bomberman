#include "Menus.h"




Menus::Menus()
{	

}

void Menus::initWindow(sf::RenderWindow * window)
{
	m_window = window;
	setBackGroundMenu(m_spriteBackGround, m_textureBackGround);
}

Menus::~Menus()
{
	
}
void Menus::setBackGroundMenu(sf::Sprite & spriteBackGround, sf::Texture & m_textureBackGround)
{

	m_textureBackGround.loadFromFile("images/robotbr.jpg");
	spriteBackGround.setTexture(m_textureBackGround, false);
	spriteBackGround.setOrigin(500.f, 500.f);
}
