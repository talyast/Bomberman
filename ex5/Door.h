#pragma once
#include "StaticObject.h"
class Door :public StaticObject
{
public:
	Door(sf::Vector2f location);
	void draw(sf::RenderWindow &m_window);

	//double dispach
	virtual todo handleCollision(Objects &Obj)override;
	virtual todo handleCollision(Door &Obj)override;
	virtual todo handleCollision(Robot &Obj)override;
	virtual todo handleCollision(Bomb &Obj) override;
	virtual todo handleCollision(Guard &Obj)override;
	virtual todo handleCollision(Wall &Obj)override;
	//virtual todo handleCollision(Gift &Obj)override;
	virtual todo handleCollision(Rock &Obj)override;
	

	void setToInitPosition();
private:
	sf::Vector2f m_location;
	sf::Texture  m_texture;
	bool m_opedDoor=false;
	sf::Vector2i m_source;
};

