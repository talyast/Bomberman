#include "RandomGuard.h"
#include "GameController.h"

RandomGuard::RandomGuard(sf::Vector2f location)
	:m_location(location), m_InitLocation(location)
{
	m_texture.loadFromFile("images/guard.png");
	m_guardSprite.setPosition(m_location);
	m_guardSprite.setTexture(m_texture, false);
	setFrequencyOfchange();
}


directions RandomGuard::move(directions direction, float currentTime, bool stuck, sf::Vector2f robotPlace)
{

	if (animationClock.getElapsedTime().asSeconds() > animationTime.asSeconds())
	{
		animationTime = sf::seconds(0.1);
		m_source.x++;
		if (m_source.x * 39 >= m_texture.getSize().x)
			m_source.x = 0;

		m_guardSprite.setTextureRect(sf::IntRect(m_source.x * 39, m_source.y * 39, 39, 39));
		animationClock.restart();
	}


	if (stuck || passTime.getElapsedTime().asSeconds() > time.asSeconds())// || m_clock.getElapsedTime() > sf::seconds())
	{
		time = sequence;

		//m_clock.restart();
		passTime.restart();
	
		int rand_number;
		
		rand_number = rand() % 4;

		if (stuck)
			rand_number = direction;
		switch (rand_number)
		{
		case 3: //up
		{

			m_source.y = UP;
			//m_guardSprite.move(0, -currentTime * randomFrame);
		}
		break;

		case 0: //down
		{
			m_source.y = DOWN;
		//	m_guardSprite.move(0, currentTime *randomFrame);
		}
		break;

		case 2: //right

		{
			m_source.y = RIGHT;
			//m_guardSprite.move(currentTime *randomFrame, 0);
		}
		break;

		case 1: //LEFT

		{
			m_source.y = LEFT;
			//m_guardSprite.move(-currentTime * randomFrame, 0);

		}
		break;
		}
	}

	switch (m_source.y)
	{
	case UP:
		m_guardSprite.move(0, -currentTime * randomFrame);
		return DOWN;
		break;
	case DOWN:
		m_guardSprite.move(0, currentTime *randomFrame);
		return UP;
		break;
	case LEFT:
		m_guardSprite.move(-currentTime * randomFrame, 0);
		return RIGHT;
		break;
	case RIGHT:
		m_guardSprite.move(currentTime *randomFrame, 0);
		return LEFT;
		break;
	default:
		return UP;
	}
}



void RandomGuard::setToInitPosition()
{
	m_guardSprite.setPosition(m_InitLocation);
}

void RandomGuard::draw(sf::RenderWindow &m_window, sf::Clock &clock)
{
	m_window.draw(m_guardSprite);
}

void RandomGuard::setFrequencyOfchange()
{

	int time = (rand() % 3) + 1;
	switch (time)
	{
	case 1:
		sequence = sf::seconds(1);
		break;
	case 2:
		sequence = sf::seconds(3);
		break;
	case 3:
		sequence = sf::seconds(5);
		break;
	default:
		break;
	}
}