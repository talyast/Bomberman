#pragma once
#include <vector>
#include<SFML/Graphics.hpp>

class Explosion 
{
public:
	Explosion();
	~Explosion();
	void creatExplosion(sf::Vector2f bombLocation);
	void draw(sf::RenderWindow & m_window) const;
private:
	sf::Clock exp;
	sf::Vector2f m_explosionLocation;
	sf::Sprite m_explosionSprite;
	sf::Texture m_explosionTexture;
};

