#include "Robot.h"
#include "GameController.h"



void Robot::setNumOfBombs(int num_of_bombs)
{
	m_num_of_bombs = num_of_bombs;
}


Robot::Robot()
{

}
void Robot::initImage(sf::Vector2f location, int pic)
{
	m_InitLocation = location;
	if(pic ==1)
		m_texture.loadFromFile("images/robot12.png");
	if (pic == 2)
		m_texture.loadFromFile("images/robot13.png");
	else
		m_texture.loadFromFile("images/robot14.png");
	
	m_location = location;

	

	
	m_roboticSprite.setPosition(location);
	m_roboticSprite.setTexture(m_texture, false);
	
	
}


void Robot::draw(sf::RenderWindow & m_window, sf::Clock &clock)
{
	clock.restart();

	if (keyOn) {
		m_source.x++;
		if (m_source.x * 39 >= m_texture.getSize().x)
			m_source.x = 0;
	}
	if (m_clock.getElapsedTime() > TIME)
	{
		m_roboticSprite.setTextureRect(sf::IntRect(m_source.x * 39, m_source.y * 39, 39,39));
		m_clock.restart();
	}
		
	//m_dinamicSprite.setTextureRect(sf::IntRect( m_source.x * 50,  m_source.y *50, 50, 50));
	m_window.draw(m_roboticSprite);
	keyOn = false;
}

directions Robot::move(directions direction, float currentTime, bool stuck, sf::Vector2f robotPlace)
{
	keyOn = true;
	switch (direction)
	{
	case LEFT:
		if (stuck)
			m_source.y = RIGHT;
		else
			m_source.y = LEFT;
		m_roboticSprite.move( -robotFrame *currentTime, 0 );
		
		return RIGHT;
		break;
	case UP:
		if (stuck)
			m_source.y = DOWN;
		else
			m_source.y = UP;
		m_roboticSprite.move( 0, -robotFrame * currentTime);
		
		return DOWN;
		break;
	case RIGHT:
		if (stuck)
			m_source.y = LEFT;
		else
			m_source.y = RIGHT;
		m_roboticSprite.move(robotFrame*currentTime, 0);
		
		return LEFT;
		break;
	case DOWN:
		if (stuck)
			m_source.y = UP;
		else
			m_source.y = DOWN;
		m_roboticSprite.move( 0, robotFrame*currentTime);
			
		return UP;
		break;

	default:
		break;

	}
	return UP;


}

todo Robot::reduceLife()
{
	m_life--;
	if (m_life <= 0)
		return END_GAME;
	return NOTHING;

}

key Robot::eventHandler(float m_currentDeltaTime, directions &direction, std::vector<std::unique_ptr<Bomb>>& m_bombs, sf::RenderWindow & window)
{
	sf::Vector2f locationb;
	sf::Event Event;
	while (window.pollEvent(Event))//every event do somthing
	{
		//moveGuards();
		switch (Event.type)//types of events
		{
		case sf::Event::Closed://if close the window
			window.close();//close
			exit(EXIT_SUCCESS);
			break;
		case sf::Event::KeyPressed://if press escape
			if (Event.key.code == sf::Keyboard::Escape)
			{
				window.close();//close
				exit(EXIT_SUCCESS);
				break;
			}
		case sf::Event::TextEntered:
			if (Event.text.unicode == 'b')
			{
				if (m_num_of_bombs != 0)
				{
					if (m_num_of_bombs != -1)
					{
						m_num_of_bombs--;
					}
					locationb = { (getRobotSprite().getPosition()) };
					m_bombs.push_back(std::make_unique<Bomb>(locationb));
				}

				return B;

			}

			if (Event.text.unicode == ' ')
			{

				if (reduceLife() != END_GAME)
					return SPACE_RESTARTLEVEL;
				else {
					return SPACE_ENDGAME;
				}

			}
			break;
		}
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{

		direction = LEFT;
		direction = move(direction, m_currentDeltaTime, m_stuck, this->getPosition());
		return ARROW;
		//manageCollision(I_IM_ROBOT, direction, *this);


	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		direction = UP;
		direction = move(direction, m_currentDeltaTime, m_stuck, this->getPosition());
		//	manageCollision(I_IM_ROBOT, direction,*this);
		return ARROW;
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		direction = RIGHT;
		direction = move(direction, m_currentDeltaTime, m_stuck, this->getPosition());
		//	manageCollision(I_IM_ROBOT, direction, *this);
		return ARROW;
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		direction = DOWN;
		direction = move(direction, m_currentDeltaTime, m_stuck, this->getPosition());
		//	manageCollision(I_IM_ROBOT, direction, *this);
		return ARROW;
	}


	//else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
	//{
	//	sf::Vector2f locationb;
	//	if (m_num_of_bombs != 0)
	//	{
	//		m_num_of_bombs--;
	//		locationb = { (getRobotSprite().getPosition()) };
	//		m_bombs.push_back(std::make_unique<Bomb>(locationb));
	//	}
	//	return b;
	//}



	//else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	//{

	//	if (reduceLife() != END_GAME) {
	//		//setToSameLevel();
	//		return space_restartlevel;
	//	}
	//	else {
	//		/*m_screen = END;
	//		openMenu(END);*/
	//		return space_endgame;
	//	}
	//	
	//}
	return UNDEFINED;
}

//void Robot::createBomb(std::vector<std::unique_ptr<Bomb>>& m_bombs)
//{
//	m_num_of_bombs--;
//	m_bombs.push_back(std::make_unique<Bomb>(this->getPosition()));
//}

todo Robot::handleCollision(Objects & Obj)
{
	return (Obj.handleCollision(*this));
	
}

todo Robot::handleCollision(Door & Obj)
{
	//nextlevel
	return NEXT_LEVEL;
}

todo Robot::handleCollision(Robot & Obj)
{
	return NOTHING;
}

todo Robot::handleCollision(Guard & Obj)
{
	//reduce life 
	//start again
	return ROBOT_DIED;
}

todo Robot::handleCollision(Bomb & Obj)
{
	return ROBOT_DIED;
}

todo Robot::handleCollision(Wall & Obj)
{
	//move(RIGHT, currentTime, stuck, clock);
	return MOVE_BACK;
}

//todo Robot::handleCollision(Gift & Obj)
//{//handle gift
//	return GOT_GIFT;
//}

todo Robot::handleCollision(Rock & Obj)
{//move back
	return NOTHING;
}

//todo Robot::handleCollision(SmartGuard & Obj)
//{//die
//	return ROBOT_DIED;
//	
//}
//
//todo Robot::handleCollision(RandomGuard & Obj)
//{
//	//die
//	return ROBOT_DIED;
//	
//}

void Robot::setToInitPosition()
{
	m_roboticSprite.setPosition(m_InitLocation);
}

