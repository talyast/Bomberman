#pragma once
#include <vector>
#include <memory>
#include<SFML/Graphics.hpp>
#include "Macros.h"
class Robot;
class Guard;
class Door;
class Wall;
class Gift;
class Bomb;
class RandomGuard;
class SmartGuard;
class Rock;
class Objects
{
public:
	Objects();
	//double dispach
	virtual todo handleCollision(Objects &Obj)=0;
	virtual todo handleCollision(Door &Obj)=0;
	virtual todo handleCollision(Robot &Obj)=0;
	virtual todo handleCollision(Bomb &Obj) = 0;
	virtual todo handleCollision(Guard &Obj)=0;
	virtual todo handleCollision(Wall &Obj)=0;
	//virtual todo handleCollision(Gift &Obj)=0;
	virtual todo handleCollision(Rock &Obj)=0;


	virtual void setToInitPosition() = 0;
	
protected:
	sf::Clock m_clock;
	const sf::Time TIME = sf::seconds(0.15f);
	const float randomFrame =90,smartFrame=3000, robotFrame = 400;

};
