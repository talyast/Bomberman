#include "Explosion.h"
#include "Macros.h"


Explosion::Explosion()

{
	
}


Explosion::~Explosion()
{
}

void Explosion::creatExplosion(sf::Vector2f bombLocation)
{
	m_explosionLocation = { bombLocation.x - PIXEL_SIZE,bombLocation.y - PIXEL_SIZE };
	m_explosionTexture.loadFromFile("images/Explosion.png");
	m_explosionSprite.setPosition(m_explosionLocation);
	m_explosionSprite.setTexture(m_explosionTexture, false);
	
}

void Explosion::draw(sf::RenderWindow & m_window) const
{
	
		m_window.draw(m_explosionSprite);


}

