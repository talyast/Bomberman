#pragma once
#include "DynamicObject.h"
#include "GameController.h"
#include <vector>

class Guard:public DynamicObject
{
public:
	
	Guard();
	
	//double dispach
	virtual todo handleCollision(Objects &Obj)override;
	virtual todo handleCollision(Door &Obj)override { return MOVE_BACK; };
	virtual todo handleCollision(Robot &Obj)override { return ROBOT_DIED; };
	virtual todo handleCollision(Guard &Obj)override { return NOTHING ; };
	virtual todo handleCollision(Bomb &Obj) override {return GUARD_DIED; };
	virtual todo handleCollision(Wall &Obj)override { return MOVE_BACK; };
	//virtual todo handleCollision(Gift &Obj)override { return NOTHING ; };
	virtual todo handleCollision(Rock &Obj)override { return MOVE_BACK; };


protected:
	
	sf::Texture m_texture;
	sf::Vector2i m_source;

};

