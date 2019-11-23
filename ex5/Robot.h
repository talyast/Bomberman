#pragma once
#include "DynamicObject.h"
#include "PlayerMenu.h"


class Robot: public DynamicObject
{
public:

	
	Robot();
	void initImage(sf::Vector2f location, int pic);
	void draw(sf::RenderWindow &m_window, sf::Clock &clock);
	void resetLife() { m_life = 3; };
	void resetscore() { m_score = 0; };
	void setNumOfBombs(int num_of_bombs);
	void setToInitPosition();
	void setScore(int num) { m_score += num; };//for tool bar

	directions move(directions direction, float currentTime, bool stuck, sf::Vector2f robotPlace) override;
	todo reduceLife();
	key eventHandler(float m_currentDeltaTime, directions &direction, std::vector<std::unique_ptr<Bomb>>& m_bombs,
		sf::RenderWindow & window);
	sf::Vector2f getPosition() { return m_roboticSprite.getPosition(); };
	sf::Vector2f getInitLocation() { return m_InitLocation; };

	
	int getLife() const { return m_life; };
	int getNumOfBombs() const { return m_num_of_bombs; };//for tool bar
	int getScore() const { return m_score; }; //for tool bar

	//double dispach
	virtual todo handleCollision(Objects &Obj)override;
	virtual todo handleCollision(Door &Obj)override;
	virtual todo handleCollision(Robot &Obj)override;
    virtual todo handleCollision(Guard &Obj)override;
	virtual todo handleCollision(Bomb &Obj) override;
	virtual todo handleCollision(Wall &Obj)override;
	//virtual todo handleCollision(Gift &Obj)override;
	virtual todo handleCollision(Rock &Obj)override;
	
private:

	int m_life = 3;
	sf::Vector2f m_location;
	sf::Vector2f m_InitLocation;
	sf::Texture  m_texture;
	sf::Vector2i m_source;
	bool keyOn = false;
	int m_score = 0;
	int m_num_of_bombs=0;

};

