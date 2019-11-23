#pragma once
#include "Objects.h"


class DynamicObject : public Objects
{
public:
	DynamicObject();
	~DynamicObject();
	virtual directions move(directions direction, float currentTime, bool stuc, sf::Vector2f robotPlacek) = 0;
	virtual void draw(sf::RenderWindow &m_window,sf::Clock &clock) = 0;
	sf::Sprite getDynamicSprite() { return m_guardSprite; };
	sf::Sprite getRobotSprite() { return m_roboticSprite; };

protected:
	sf::Sprite m_guardSprite;
	sf::Sprite m_roboticSprite;
	sf::Clock m_timer;

	bool m_stuck = false;
};

