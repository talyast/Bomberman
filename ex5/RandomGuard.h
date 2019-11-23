#pragma once
#include "Guard.h"
#include <memory>
class RandomGuard:public Guard
{
public:
	RandomGuard(sf::Vector2f location);
	
	void setToInitPosition();
	void draw(sf::RenderWindow &m_window, sf::Clock &clock);
	void setFrequencyOfchange();
	directions move(directions direction, float currentTime, bool stuck, sf::Vector2f robotPlace);

	
private:
	sf::Vector2f m_location;
	sf::Vector2f m_InitLocation;
	int m_changeMove= 60;//for random*2
	int m_step = 0;//for random*2

	sf::Clock passTime;
	sf::Time time = sf::seconds(1);

	sf::Clock animationClock;
	sf::Time animationTime = sf::seconds(0);

	sf::Time sequence;
	
};

