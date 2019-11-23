#pragma once
#include "Guard.h"
#include <memory>
#include <math.h>
class SmartGuard:public Guard
{
public:
	SmartGuard(sf::Vector2f location);
	~SmartGuard();
	directions move(directions direction, float currentTime, bool stuck, sf::Vector2f robotPlace);
	
	void setToInitPosition();
	void draw(sf::RenderWindow &m_window, sf::Clock &clock);

private:
	
	sf::Vector2f m_location;
	sf::Vector2f m_InitLocation;
	sf::Clock passTime;
	sf::Time time = sf::seconds(0); //= sf::seconds(0.1);


};

