#include "SmartGuard.h"



SmartGuard::SmartGuard(sf::Vector2f location)
	:m_location(location), m_InitLocation(location)
{
	m_texture.loadFromFile("images/guard.png");
	m_guardSprite.setPosition(m_location);
	m_guardSprite.setTexture(m_texture, false);
}


SmartGuard::~SmartGuard()
{
}

directions SmartGuard::move(directions direction, float currentTime, bool stuck, sf::Vector2f robotPlace)
{
	
	if (passTime.getElapsedTime().asSeconds() > time.asSeconds())
		{
			time = sf::seconds(0.1);
			m_source.x++;
			if (m_source.x * 39 >= m_texture.getSize().x)
				m_source.x = 0;

			m_guardSprite.setTextureRect(sf::IntRect(m_source.x * 39, m_source.y * 39, 39, 39));
			passTime.restart();
		}



	float guardPosX = m_guardSprite.getPosition().x;
	float guardPosY = m_guardSprite.getPosition().y;



	int height = abs(guardPosY - robotPlace.y);//getRobotSprite().getGlobalBounds().top);
	int width = abs(guardPosX - robotPlace.x);

	if (stuck || m_clock.getElapsedTime() > sf::seconds(0.1f)) {
		m_clock.restart();
		if (stuck)
		{
			m_source.y = direction;
		}
		else if (width >= height)
		{
			if (guardPosX < robotPlace.x)
			{
				m_source.y = RIGHT;
			}
			else
			{
				m_source.y = LEFT;
			}
		}
		else {
			if (guardPosY < robotPlace.y)
			{
				m_source.y = DOWN;
			}
			else
			{
				m_source.y = UP;
			}
		}
		float guardPosX = m_guardSprite.getPosition().x;
		float guardPosY = m_guardSprite.getPosition().y;


		switch (m_source.y)
		{
		case UP:
			m_guardSprite.move(0, -currentTime * smartFrame);
			break;
		case DOWN:
			m_guardSprite.move(0, currentTime * smartFrame);
			break;
		case LEFT:
			m_guardSprite.move(-currentTime * smartFrame, 0);
			break;
		case RIGHT:
			m_guardSprite.move(currentTime * smartFrame, 0);
			break;
		}
	}




	switch (m_source.y)
	{
	case UP:
		return DOWN;
		break;
	case DOWN:
		return UP;
		break;
	case LEFT:
		return RIGHT;
		break;
	case RIGHT:
		return LEFT;
		break;
	default:
		return UP;
	}
}








void SmartGuard::setToInitPosition()
{
	m_guardSprite.setPosition(m_InitLocation);



}

void SmartGuard::draw(sf::RenderWindow &m_window, sf::Clock &clock)
{

	m_window.draw(m_guardSprite);

}