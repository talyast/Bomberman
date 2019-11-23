#include "Guard.h"
//#include "StaticObject.h"







Guard::Guard()
{
	/*m_texture.loadFromFile("images/guard.png");
	m_dinamicSprite.setPosition(m_location);
	m_dinamicSprite.setTexture(m_texture, false);*/
	

}

todo Guard::handleCollision(Objects & Obj)
{
	return (Obj.handleCollision(*this));
}
//
//void Guards::getController(GameController & game)
//{
//	m_game = game;
//}




//void Guards::draw(sf::RenderWindow &m_window, sf::Clock &clock)
//{
//
//	frameCounter += frameSpeed * clock.restart().asSeconds();
//
//		m_source.x++;
//		if (m_source.x * 50 >= m_texture.getSize().x)
//			m_source.x = 0;
//	
//	if (clockAnimation.getElapsedTime() > TIME)
//	{
//		m_guardSprite.setTextureRect(sf::IntRect(m_source.x * 50, m_source.y * 50, 50, 50));
//		clockAnimation.restart();
//	}
//
//	//m_dinamicSprite.setTextureRect(sf::IntRect( m_source.x * 50,  m_source.y *50, 50, 50));
//	m_window.draw(m_guardSprite);
//	
//	
//}


