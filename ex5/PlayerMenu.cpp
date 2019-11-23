#include "PlayerMenu.h"
#include "MainMenu.h"

screens PlayerMenu::run()
{
	setBackGround();
	 while (m_window->isOpen() && m_isOpen)
	 {
		 m_window->clear();
		 m_window->draw(m_spriteBackGround);
		 m_window->draw(m_spritePlayer1);
		 m_window->draw(m_spritePlayer2);
		 m_window->draw(m_spritePlayer3);
		 screens screen = eventHandler();
		 if (screen == GAME)
			 return GAME;
		 if (screen != IGNORE)
			 return screen; //ma ze?
		 m_window->display();
	 }
	 return EXIT;
}

PlayerMenu::PlayerMenu()
{
	loadImages();

}
int PlayerMenu::getChosenPlayer()
{
	if (m_player1)
		return 1;
	if (m_player2)
		return 2;
	else
		return 3;
	return 1;
	
}

void PlayerMenu::setBackGround()
{

	m_textureBackGround.loadFromFile("images/background2.jpg");
	m_spriteBackGround.setTexture(m_textureBackGround, false);
	m_spriteBackGround.setOrigin(500.f, 500.f);

}

void PlayerMenu::loadImages()
{
	m_texturePlayer1.loadFromFile("images/player1.jpg");
	m_spritePlayer1.setPosition({ 260.f ,250.f });
	m_texturePlayer2.loadFromFile("images/player2.png");
	m_spritePlayer2.setPosition({ 500.f ,250.f });
	m_texturePlayer3.loadFromFile("images/player3.png");
	m_spritePlayer3.setPosition({ 740.f ,250.f });
	m_texturePlayer1.setSmooth(true);
	m_texturePlayer2.setSmooth(true);
	m_texturePlayer3.setSmooth(true);
	m_spritePlayer1.setTexture(m_texturePlayer1, false);
	m_spritePlayer2.setTexture(m_texturePlayer2, false);
	m_spritePlayer3.setTexture(m_texturePlayer3, false);
}


screens PlayerMenu::eventHandler()
{
	sf::Event Event;
	while (m_window->pollEvent(Event))//every event do somthing
	{
		if (m_spritePlayer1.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*m_window)))
		{
			m_spritePlayer1.setColor(sf::Color(225, 255, 255, 220));
		}
		else
		{
			m_spritePlayer1.setColor(sf::Color(sf::Color::White));
		}
		if (m_spritePlayer2.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*m_window)))
		{
			m_spritePlayer2.setColor(sf::Color(225, 255, 255, 220));
			//m_spritePlayer2.setColor(sf::Color::Black);
		}
		else
		{
			m_spritePlayer2.setColor(sf::Color(sf::Color::White));
		}
		if (m_spritePlayer3.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*m_window)))
		{
			m_spritePlayer3.setColor(sf::Color(225, 255, 255, 220));
		}
		else
		{
			m_spritePlayer3.setColor(sf::Color(sf::Color::White));
		}
		switch (Event.type)//types of events
		{
		case sf::Event::Closed://if close the window
			m_window->close();//close
			return screens::EXIT;
			break;
		case sf::Event::KeyPressed://if press escape
			if (Event.key.code == sf::Keyboard::Escape)
				m_window->close();//close
	
			break;
		
		case sf::Event::MouseButtonReleased:
			if (Event.mouseButton.button == sf::Mouse::Button::Left)
				
				if (m_spritePlayer1.getGlobalBounds().contains
				(m_window->mapPixelToCoords({ Event.mouseButton.x, Event.mouseButton.y })))
				{
					m_player1 = true;
					m_isOpen = false;
				
					return screens::GAME;
				}
				else if (m_spritePlayer2.getGlobalBounds().contains
				(m_window->mapPixelToCoords({ Event.mouseButton.x, Event.mouseButton.y })))
				{
					m_player2 = true;
					m_isOpen = false;
					return screens::GAME;
				}
				else if (m_spritePlayer3.getGlobalBounds().contains
				(m_window->mapPixelToCoords({ Event.mouseButton.x, Event.mouseButton.y })))
				{
					m_player3 = true;
					m_isOpen = false;
					return screens::GAME;
				}
			break;
		}
	}
	return screens::IGNORE;
}