#include "Bomb.h"




Bomb::Bomb(sf::Vector2f location)
	
{
	m_bombLocation = location;
	m_texture.loadFromFile("images/bomb.png");
	m_bombSprite.setPosition(location);
	m_bombSprite.setTexture(m_texture, false);
	
}


bool Bomb::check()
{
	

	sf::Time elapsed = m_timer.getElapsedTime();
	if (elapsed >= sf::seconds(4))
	{
		if (m_exploded)
		{
			m_exploded = false;

			m_explosion.creatExplosion(m_bombLocation);
			return true;
		}
		else
			return false;
	}
	return false;
	
}

bool Bomb::checlExplosion()
{
	sf::Time elapsed = m_timer.getElapsedTime();
	if (elapsed >= sf::seconds(6))
		return true;
	return false;
}


todo Bomb::handleCollision(Objects & Obj)
{
	return(Obj.handleCollision(*this));
}

todo Bomb::handleCollision(Door & Obj)
{
	return NOTHING;
}

todo Bomb::handleCollision(Robot & Obj)
{
	//kill
	return ROBOT_DIED;
}
todo Bomb::handleCollision(Bomb & Obj)
{
	return NOTHING;
}

todo Bomb::handleCollision(Guard & Obj)
{
	//kill
	return GUARD_DIED;
}

todo Bomb::handleCollision(Wall & Obj)
{
	return NOTHING;
}

//todo Bomb::handleCollision(Gift & Obj)
//{
//	//think about the situation
//	return DELETE;
//}

todo Bomb::handleCollision(Rock & Obj)
{
	//delete
	return DELETE;
}

//todo Bomb::handleCollision(SmartGuard & Obj)
//{
//	return GUARD_DIED;
//}
//
//todo Bomb::handleCollision(RandomGuard & Obj)
//{
//	return GUARD_DIED;
//}

void Bomb::setToInitPosition()
{
}

void Bomb::draw(sf::RenderWindow & m_window)
{
	sf::Time elapsed = m_timer.getElapsedTime();
	if (elapsed <= sf::seconds(4))
		m_window.draw(m_bombSprite);
	else
			m_explosion.draw(m_window);
	
}

