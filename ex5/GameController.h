#pragma once
#include <vector> //took to board
#include <string>//took to board
#include "Board.h"
#include <SFML/Graphics.hpp>
#include "Menus.h"
#include "MainMenu.h"
#include "Macros.h"
#include "toolBar.h"
#include "EndScreen.h"

class GameController
{
public:
	GameController();
	void run();
	void openMenu(screens m_screen);
	
	void creatToolBar();
	void initWindow();

private:
	screens command;
	screens m_screen;

	PlayerMenu Pmenu;
	EndScreen endscreen;

	//void setBackGroundGame(sf::Sprite &m_spriteBackBround, sf::Texture &m_textureBackGround);
	void eventHandler();
	
	std::vector<std::unique_ptr<toolBar>> m_toolBar;
	sf::RenderWindow m_window;
	sf::Texture m_texture;
	sf::Texture m_textureStart;
	sf::Texture m_textureChoosePlayer;
	std::vector <std::vector <std::string>> m_levels;

	Board m_board;
	
	MainMenu m_menu;
	MainMenu menu;

	bool player1 = false;
	bool player2 = false;
	sf::Clock m_clock;
	
	sf::Texture m_textureBackGround;//dont know if needed also here and alse in GC.
	sf::Sprite m_spriteBackBround;//dont know if needed also here and alse in GC.

	sf::Vector2f m_bombLocation;

	int m_stage = 0; //needed here too?
	bool m_first = true;

	
};



	


