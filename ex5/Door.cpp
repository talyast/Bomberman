#include "Door.h"




Door::Door(sf::Vector2f location)
	
{
	{
	
		m_texture.loadFromFile("images/door.png");
		m_staticSprite.setPosition(location);
		m_staticSprite.setTexture(m_texture, false);

	}
}

void Door::draw(sf::RenderWindow & m_window)
{
	
	m_window.draw(m_staticSprite);
}

todo Door::handleCollision(Objects & Obj)
{
	return (Obj.handleCollision(*this));
}

todo Door::handleCollision(Robot & Obj)
{
	m_opedDoor = true;
	return NEXT_LEVEL;
}

todo Door::handleCollision(Bomb & Obj)
{
	return NOTHING;
}

todo Door::handleCollision(Guard & Obj)
{
	return MOVE_BACK;
}

todo Door::handleCollision(Wall & Obj)
{
	return NOTHING;
}

todo Door::handleCollision(Rock & Obj)
{
	return NOTHING;
}
void Door::setToInitPosition()
{
}

todo Door::handleCollision(Door & Obj)
{
	return NOTHING;
}
