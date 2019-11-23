#include "Rock.h"


Rock::Rock(sf::Vector2f location)
	:m_location(location), m_initLocation(location)
{
	
	m_texture.loadFromFile("images/rock.png");
	m_staticSprite.setPosition(location);
	m_staticSprite.setTexture(m_texture, false);

}

void Rock::draw(sf::RenderWindow & m_window)
{
	//	sf::RectangleShape m_rect(sf::Vector2f(50.f, 50.f));
	m_window.draw(m_staticSprite);
}

todo Rock::handleCollision(Objects & Obj)
{
	return (Obj.handleCollision(*this));
}

void Rock::setToInitPosition()
{
	m_staticSprite.setPosition(m_initLocation);
}
