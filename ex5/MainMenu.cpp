#include "MainMenu.h"





screens MainMenu::run()
{
	
	while (m_window->isOpen() && m_isOpen)
	{
		
		m_window->clear();
		
		m_window->draw(m_spriteBackGround);
		m_window->draw(m_sprite);
		m_window->draw(m_sprite2);
		m_window->draw(m_sprite3);
		
		
		screens screen = eventHandler();
		if (screen == PLAYERS)
			return PLAYERS;
		if (screen != IGNORE)
		return screen;
			
			m_window->display();
		
	}
	return EXIT;
}

MainMenu::MainMenu()
{
	loadImages();

}


void MainMenu::loadImages()
{
	
	m_textureStart.loadFromFile("images/start game.png");
	m_sprite.setPosition({ 300.f ,200.f });
	m_sprite.setTexture(m_textureStart, false);
	m_textureChoosePlayer.loadFromFile("images/select player.png");
	m_sprite2.setPosition({ 290.f ,390.f });
	m_sprite2.setTexture(m_textureChoosePlayer, false);
	m_textureExit.loadFromFile("images/exit.png");
	m_sprite3.setPosition({ 300.f ,580.f });
	m_sprite3.setTexture(m_textureExit, false);
}


screens MainMenu::eventHandler()
{
	sf::Event Event;
	while (m_window->pollEvent(Event))//every event do somthing
	{
		if (m_sprite.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*m_window)))
		{
			m_sprite.setColor(sf::Color(225, 255, 255, 220));
		}
		else
		{
			m_sprite.setColor(sf::Color(sf::Color::White));
		}
		if (m_sprite2.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*m_window)))
		{
			m_sprite2.setColor(sf::Color(225, 255, 255, 220));
		}
		else
		{
			m_sprite2.setColor(sf::Color(sf::Color::White));
		}
		if (m_sprite3.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*m_window)))
		{
			m_sprite3.setColor(sf::Color(225, 255, 255, 220));
		}
		else
		{
			m_sprite3.setColor(sf::Color(sf::Color::White));
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
				//if (m_sprite.getGlobalBounds().contains(sf::Mouse::getPosition(m_window).x,)
					//m_sprite.setColor(sf::Color(225, 255, 255, 200));
				if (m_sprite.getGlobalBounds().contains
				(m_window->mapPixelToCoords({ Event.mouseButton.x, Event.mouseButton.y })))
				{
					
					m_isOpen = false;
					return screens::GAME;
				}
				else if (m_sprite2.getGlobalBounds().contains
				(m_window->mapPixelToCoords({ Event.mouseButton.x, Event.mouseButton.y })))
				{
					m_isOpen = false;
					return screens::PLAYERS;
				}
				else if (m_sprite3.getGlobalBounds().contains
				(m_window->mapPixelToCoords({ Event.mouseButton.x, Event.mouseButton.y })))
				{
					return screens::EXIT;
				}
			
			break;
		}
	}
	return screens::IGNORE;
}
//void MainMenu::setBackGround(sf::Sprite & m_spriteBackBround, sf::Texture & m_textureBackGround)
//{
//
//	m_textureBackGround.loadFromFile("images/robotbr.jpg");
//	m_spriteBackBround.setTexture(m_textureBackGround, false);
//	m_spriteBackBround.setOrigin(500.f, 500.f);
//}




