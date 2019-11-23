#include "GameController.h"
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
#include "Board.h"

GameController::GameController(): m_board(m_window, m_toolBar, m_clock)
{
	initWindow();
}

void GameController::run()
{
	//initWindow();
	int player = Pmenu.getChosenPlayer();
	char fileName[] = "board.txt";
	std::ifstream file(fileName);

	while (!file.eof())
	{
		std::string line;
		std::vector <std::string> level;

		do
		{
			getline(file, line);
			level.push_back(line);
		} while (!line.empty());

		m_levels.push_back(level);
	}

	//for (const auto &level : m_levels) {
	for (int i = 0; i < m_levels.size(); ++i)//אם זה שווה ל1 אז הוא מתחיל משלב 2
	{
		key key;
		key = UNDEFINED;
		m_board.initData(m_levels[i], i);
		m_board.createLevel( key, player);
		key =m_board.PlayLevel();
		if (key == SPACE_ENDGAME)
		{
			i = -1;
			openMenu(END);
		}
			
	}
	
}

void GameController::initWindow()
{
	creatToolBar();
	if (m_first)
		m_window.create(sf::VideoMode(1200, 1000), "bomberman window");
	menu.initWindow(&m_window);
	m_screen = menu.run();
	openMenu(m_screen);
}


void GameController::openMenu(screens m_screen)
{
	//setBackGroundGame(m_spriteBackBround, m_textureBackGround);

	while (m_screen != GAME) {
		switch (m_screen)
		{
		case START_AGAIN:
		
			return;
		case GAME:

			menu.initWindow(&m_window);
			m_screen = menu.run();
			break;
		case PLAYERS:
			Pmenu.openWindow();
			Pmenu.initWindow(&m_window);
			m_screen = Pmenu.run();
			menu.openWindow();
			m_screen = menu.run();
			break;
		case END:
			endscreen.initWindow(&m_window);
			endscreen.openWindow();
			m_screen = endscreen.run();
			break;
		case EXIT:
			m_window.close();
			exit(EXIT_SUCCESS);
			break;

		}

	}

}

//void GameController::setBackGroundGame(sf::Sprite & m_spriteBackBround, sf::Texture & m_textureBackGround)
//{
//
//	m_textureBackGround.loadFromFile("images/yael.jpg");
//	m_spriteBackBround.setTexture(m_textureBackGround, false);
//	m_spriteBackBround.setOrigin(500.f, 500.f);
//}

void GameController::eventHandler()
{
	sf::Event Event;

	while (m_window.pollEvent(Event))//every event do somthing
	{
		
		switch (Event.type)//types of events
		{
		case sf::Event::Closed://if close the window
			m_window.close();//close
			exit(EXIT_SUCCESS);
			break;
		case sf::Event::KeyPressed://if press escape
			if (Event.key.code == sf::Keyboard::Escape)
			{
				m_window.close();//close
				exit(EXIT_SUCCESS);
				break;
			}
			
			
		}
	}
}


void GameController::creatToolBar()
{

	m_toolBar.push_back(std::make_unique<Score>());
	m_toolBar.push_back(std::make_unique<Life>());
	m_toolBar.push_back(std::make_unique<NumOfBomb>());
	m_toolBar.push_back(std::make_unique<Stage>());
	m_toolBar.push_back(std::make_unique<Timer>());

}

