#include "Wall.h"

Wall::Wall(sf::Vector2f location)
	:m_location(location)
{
	m_texture.loadFromFile("images/wall.png");
	m_staticSprite.setPosition(location);
	m_staticSprite.setTexture(m_texture, false);

}

void Wall::draw(sf::RenderWindow & m_window)
{
	//sf::RectangleShape m_rect(sf::Vector2f(60.f, 50.f));
	m_window.draw(m_staticSprite);
}

todo Wall::handleCollision(Objects & Obj)
{
	return (Obj.handleCollision(*this));
}

void Wall::setToInitPosition()
{
}
