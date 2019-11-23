#pragma once
#include <vector>
#include <string>
#include <string>
#include "DynamicObject.h"
#include "StaticObject.h"
#include "Robot.h"
#include "Bomb.h"
#include "Explosion.h"
#include "Macros.h"
#include "toolBar.h"

class GameController;
class Board
{
public:
	Board(sf::RenderWindow & w, std::vector<std::unique_ptr<toolBar>> & t, sf::Clock & c);
	void eventHandler(sf::RenderWindow & window);
	void timeHandler();
	void initData(std::vector <std::string>& level, int data);
	void createObject(char symble, sf::Vector2f location, int player);
	void createLevel(key command, int player);
	key PlayLevel();
private:
	
	
	void setToSameLevel();
	void moveGuards();
	void manageCollision(WhoImI identity, directions direction, DynamicObject &obj);
	void manageCollisionForBombs();
	void setBackGroundGame(sf::Sprite & m_spriteBackBround, sf::Texture & m_textureBackGround);
	void displayImages(std::vector<std::unique_ptr<toolBar>> &toolBar);
	//void timeLimitHandler(sf::Clock  passTime, sf::Time time);
	void end_Level();


	typeGuard chooseTypeGuard()const;
	
	todo checkCollisions(WhoImI identity, DynamicObject& obj);
	todo guardCollide(DynamicObject& obj);
	todo robotCollide();
	
	symbols checkSymble(char symble);
	
	
	std::vector<std::unique_ptr<toolBar>> & m_toolBar;
	std::vector<std::unique_ptr<DynamicObject>> m_Guards;
	std::vector<std::unique_ptr<StaticObject>> m_staticObject;
	std::vector<std::unique_ptr<Bomb>> m_bombs;
	std::vector <std::string> m_level;


	sf::RenderWindow & m_window;
	sf::Clock &m_clock;
	sf::Time time = sf::seconds(1);
	sf::Clock m_expTime;
	sf::Clock passTime;

	key m_stat;

	int m_rows;
	int m_cols;
	int m_time;
	int m_initTime;
	size_t m_initGuardNum;
	int m_stage=0;

	Robot m_robot;

	float m_currentDeltaTime;

	bool m_end = false;
	bool m_first = true;

	directions m_direction;

	sf::Texture m_textureBackGround;//dont know if needed also here and alse in GC.
	sf::Sprite m_spriteBackBround;//dont know if needed also here and alse in GC.

};

