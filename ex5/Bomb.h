#pragma once
#include "StaticObject.h"
#include "Explosion.h"
class Bomb: public StaticObject
{
public:
	Bomb(sf::Vector2f location);

	void draw(sf::RenderWindow &m_window);
	void setToInitPosition();
	sf::Sprite getBombsSprite() { return m_bombSprite; };
	bool check();
	bool checlExplosion();
	
	//double dispach
	virtual todo handleCollision(Objects &Obj)override;
	virtual todo handleCollision(Door &Obj)override;
	virtual todo handleCollision(Robot &Obj)override;
	virtual todo handleCollision(Bomb &Obj)override;
	virtual todo handleCollision(Guard &Obj)override;
	virtual todo handleCollision(Wall &Obj)override;
	//virtual todo handleCollision(Gift &Obj)override;
	virtual todo handleCollision(Rock &Obj)override;
	
	
private:

	sf::Sprite m_bombSprite;
	sf::Texture  m_texture;
	sf::Vector2i m_source;
	sf::Clock m_timer;

	bool m_exploded = true;
	bool m_time_passed = false;

	sf::Vector2f m_bombLocation;
	
	Explosion m_explosion;


	
};

