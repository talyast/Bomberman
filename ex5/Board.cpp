#include "Board.h"
#include <string>
#include <sstream>
#include "MainMenu.h"
#include "PlayerMenu.h"
#include <fstream>
#include <string>
#include <sstream>
#include "Guard.h"
#include <time.h>
#include "Rock.h"
#include "Gift.h"
#include "Wall.h"
#include "Door.h"
#include "RandomGuard.h"
#include "SmartGuard.h"
#include "Score.h"
#include "Timer.h"
#include "NumOfBomb.h"
#include "Life.h"
#include "Stage.h"


Board::Board(sf::RenderWindow & w, std::vector<std::unique_ptr<toolBar>> & t, sf::Clock & c)
	: m_window(w), m_toolBar(t), m_clock(c)
{

}

void Board::initData(std::vector <std::string>& level, int stage)
{
	m_level = level;
	m_stage = stage+1;
	int rows, cols, time, num_of_bombs; //put in privete of bomb
	std::stringstream(level[0]) >> rows >> cols >> time >> num_of_bombs;
	m_rows = rows;
	m_cols = cols;
	m_initTime = m_time = time;
	m_robot.setNumOfBombs(num_of_bombs);


}



void Board::createLevel(key command, int player)
{
	setBackGroundGame(m_spriteBackBround, m_textureBackGround);
	m_stat = command;

	for (size_t row = 1; row < m_rows + 1; ++row)
		for (size_t col = 0; col < m_cols; ++col)
		{
			char symbol = m_level[row][col];
			sf::Vector2f location = { (float)col * 40 + 200, (float)(row) * 40 + 3 * 35 };

			createObject(symbol, location, player);
		}
	m_initGuardNum = m_Guards.size();
}

void Board::eventHandler(sf::RenderWindow & window)
{
	directions direction;
	key action;

	action = m_robot.eventHandler(m_currentDeltaTime, direction, m_bombs,window );

	if (action == ARROW)
		manageCollision(I_IM_ROBOT, direction, m_robot);
	else if (action == SPACE_RESTARTLEVEL)
		setToSameLevel();
	else if (action == SPACE_ENDGAME)
	{
		m_stat = SPACE_ENDGAME;
		m_robot.resetLife();
		return;
	}
	
	else
		;
}

void Board::timeHandler()
{


	if (passTime.getElapsedTime().asSeconds() > time.asSeconds() && m_time != -1)
	{
		m_time--;
		passTime.restart();
	}
	if (m_time == 0)
	{
		if (m_robot.getLife() > 0)
		{
			m_robot.reduceLife();
			setToSameLevel();
			m_time = m_initTime;
		}
		if (m_robot.getLife() == 0)
			//else
		{
			m_stat = SPACE_ENDGAME;
			return;
			//m_screen = END;
			//openMenu(END);
		}

	}
}





void Board::displayImages(std::vector<std::unique_ptr<toolBar>> & toolBar) 
{
	for (const auto& t_object : toolBar)
		t_object->draw(m_window, m_robot.getScore(), m_robot.getLife(),m_robot.getNumOfBombs(),m_stage, m_time);

	for (const auto& d_object : m_Guards)
		d_object->draw(m_window, m_clock); 


	for (const auto& s_object : m_staticObject)

		s_object->draw(m_window);


	for (const auto& b_object : m_bombs)
		b_object->draw(m_window);

	m_robot.draw(m_window, m_clock);


}

key Board::PlayLevel( )
{
	m_clock.restart();
	while (m_window.isOpen()) //go in the while till the window closes
	{
		timeHandler();
		m_window.clear();

		m_window.draw(m_spriteBackBround);
		m_currentDeltaTime = m_clock.restart().asSeconds();
		displayImages(m_toolBar);
		moveGuards();
		eventHandler(m_window);
		
		manageCollisionForBombs();
		if (m_stat == SPACE_ENDGAME || m_stat == NEXT)
		{
			end_Level();
			return m_stat;
		}
	
	
		m_window.display();

	}
}

void Board::createObject(char symbol, sf::Vector2f location, int player)
{
	switch (checkSymble(symbol))
	{
	case WALL:
		m_staticObject.push_back(std::make_unique<Wall>(location));
		break;

	case ROCK:
		m_staticObject.push_back(std::make_unique<Rock>(location));
		break;

	case GUARD:
		typeGuard type;
		type = chooseTypeGuard();
		if (type == RANDOM)
			m_Guards.push_back(std::make_unique<RandomGuard>(location));
		else
			m_Guards.push_back(std::make_unique<SmartGuard>(location));

			break;

	case DOOR:
		m_staticObject.push_back(std::make_unique<Door>(location));
		break;

	case ROBOT:
		m_robot.initImage(location, player);
		break;
	default:
		break;
	}
}


typeGuard Board::chooseTypeGuard() const
{
	int rand_number;
	rand_number = rand() % 2;
	switch (rand_number)
	{
	case 0:
		return RANDOM;
		break;
	case 1:
		return SMART;
		break;
	default:
		break;
	}
	return SMART;
}


symbols Board::checkSymble(char symble)
{
	if (symble == '#')
		return WALL;
	else if (symble == '!')
		return GUARD;
	else if (symble == '@')
		return ROCK;
	else if (symble == 'D')
		return DOOR;
	else if (symble == '/')
		return ROBOT;
	else
		return VOID;
}

void Board::setBackGroundGame(sf::Sprite & m_spriteBackBround, sf::Texture & m_textureBackGround)
{

	m_textureBackGround.loadFromFile("images/yael.jpg");
	m_spriteBackBround.setTexture(m_textureBackGround, false);
	m_spriteBackBround.setOrigin(500.f, 500.f);
}



todo Board::robotCollide()
{
	for (const auto& other : m_staticObject)
	{
		if (m_robot.getRobotSprite().getGlobalBounds().intersects(other->getStaticSprite().getGlobalBounds()))
			return(m_robot.handleCollision(*other));

	}
	for (const auto& other : m_Guards)
	{

		if (m_robot.getRobotSprite().getGlobalBounds().intersects(other->getDynamicSprite().getGlobalBounds()))
			return(m_robot.handleCollision(*other));
	}
	return todo::NOTHING;
}


todo Board::guardCollide(DynamicObject& obj)
{
	for (const auto& other : m_staticObject)
	{

		if (obj.getDynamicSprite().getGlobalBounds().intersects(other->getStaticSprite().getGlobalBounds()))
			return(obj.handleCollision(*other));

	}

	if (obj.getDynamicSprite().getGlobalBounds().intersects(m_robot.getRobotSprite().getGlobalBounds()))
		return (obj.handleCollision(m_robot));


	return NOTHING;

}


void Board::manageCollision(WhoImI identity, directions direction, DynamicObject &obj)
{
	sf::Vector2f robotLocation = m_robot.getPosition();
	switch (checkCollisions(identity, obj))
	{
	case NOTHING:
		break;
	case MOVE_BACK:
		if (identity == I_IM_ROBOT)
			m_robot.move(direction, m_currentDeltaTime, true, robotLocation); //moves back
		else if (identity == I_IM_GUARD)
			obj.move(direction, m_currentDeltaTime, true, robotLocation);
		break;
	case ROBOT_DIED:
		todo O;
		O = m_robot.reduceLife();
		
		if (O == END_GAME) {
			m_stat= SPACE_ENDGAME;
			m_robot.resetLife();
			m_robot.resetscore();
		
		}
		else
			setToSameLevel();
		break;
	case GUARD_DIED: 
		break;
	case NEXT_LEVEL:
		m_stat = NEXT;
		m_robot.setScore(20 * m_initGuardNum);
		break;
	/*case GOT_GIFT:
		break;*/

	case DELETE:
		break;
	case END_GAME:
		break;

		default:
			break;
	}

}

todo Board::checkCollisions(WhoImI identity, DynamicObject& obj)
{
	if (identity == I_IM_ROBOT)
		return (robotCollide());
	if (identity == I_IM_GUARD)
		return (guardCollide(obj));

	return NOTHING;
}

void Board::moveGuards()
{

	sf::Vector2f robotLocation = m_robot.getPosition();
	for (const auto& otherObject : m_Guards)
	{
		directions direction = otherObject->move(m_direction, m_currentDeltaTime, false, robotLocation);

		manageCollision(I_IM_GUARD, direction, *otherObject);
	}
}
void Board::manageCollisionForBombs()
{
	{
		todo command = NOTHING;

		for (size_t i = 0; i < m_bombs.size(); ++i)
		{
			bool exploded = false;
			if (m_bombs[i]->check())
			{

				{

					sf::Vector2f bombLocation = m_bombs[i]->getBombsSprite().getPosition();
					sf::FloatRect explosionGlobalBounds(bombLocation.x - PIXEL_SIZE, bombLocation.y - PIXEL_SIZE, PIXEL_SIZE * 3, PIXEL_SIZE * 3);
					for (int j = 0; j < m_staticObject.size(); ++j)
					{
						if (explosionGlobalBounds.intersects(m_staticObject[j]->getStaticSprite().getGlobalBounds()))
						{

							command = m_bombs[i]->handleCollision(*m_staticObject[j]);
							if (command == DELETE)
							{

								m_staticObject.erase(m_staticObject.begin() + j);
								j--;

							}

						}

					}

					for (int m = 0; m < m_Guards.size(); ++m)
					{


						if (explosionGlobalBounds.intersects(m_Guards[m]->getDynamicSprite().getGlobalBounds()))
						{

							command = m_bombs[i]->handleCollision(*m_Guards[m]);
							if (command == GUARD_DIED)
							{
								//m_score += 5 * m_initGuardNum;
								m_robot.setScore(5 * m_initGuardNum);
								m_Guards.erase(m_Guards.begin() + m);
								m--;

							}

						}
					}

					if (explosionGlobalBounds.intersects(m_robot.getRobotSprite().getGlobalBounds()))
					{
						if (m_bombs[i]->handleCollision(m_robot) == ROBOT_DIED)
							if (m_robot.reduceLife() == END_GAME) {
								//m_life--;

								m_stat= SPACE_ENDGAME;
								m_robot.resetLife();
							///	openMenu(END);
							}
							else
								setToSameLevel();
						//return;
					}

				}

			}

			if (m_bombs[i]->checlExplosion())
			{
				m_bombs.erase(m_bombs.begin() + i);
				i--;
			}

		}
	}
}

void Board::end_Level()
{

	m_Guards.clear();
	m_staticObject.clear();
	m_bombs.clear();

}


void Board::setToSameLevel()
{
	m_time = 30;
	m_robot.setToInitPosition();
	for (const auto& other : m_Guards)
	{

		other->setToInitPosition();
	}
}

