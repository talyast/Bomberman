#pragma once
#include"Objects.h"

class StaticObject: public Objects
{
public:
	StaticObject();
	~StaticObject();
	sf::Sprite getStaticSprite() { return m_staticSprite; };

	virtual void setToInitPosition() = 0;
	virtual void draw(sf::RenderWindow &m_window) = 0;

protected:
	sf::Sprite m_staticSprite;
};

