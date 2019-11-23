#include "EndScreen.h"
#include "MainMenu.h"

screens EndScreen::run()
{
	setBackGround();
	while (m_window->isOpen() && m_isOpen)
	{
		m_window->clear();
		m_window->draw(m_spriteBackGround);
		m_window->draw(m_spriteExit);
		m_window->draw(m_spritePlayeAgain);
		//m_window->draw(m_spritePlayer2);
		screens screen = eventHandler();
		if (screen == GAME)
			return GAME;
		if (screen != IGNORE)
			return screen; //ma ze?
		m_window->display();
	}
	return EXIT;
}

EndScreen::EndScreen()
{
	loadImages();

}
void EndScreen::setBackGround()
{

	m_textureBackGround.loadFromFile("images/gameover.jpg");
	m_spriteBackGround.setTexture(m_textureBackGround, false);
	m_spriteBackGround.setOrigin(100.f, 100.f);

}
void EndScreen::loadImages()
{
	
	m_texturePlayAgain.loadFromFile("images/try again.png");
	m_spritePlayeAgain.setPosition({ 450.f ,370.f });
	m_textureExit.loadFromFile("images/exit.png");
	m_spriteExit.setPosition({ 470.f ,610.f });
	m_texturePlayAgain.setSmooth(true);
	m_textureExit.setSmooth(true);
	m_spritePlayeAgain.setTexture(m_texturePlayAgain, false);
	m_spriteExit.setTexture(m_textureExit, false);
}


screens EndScreen::eventHandler()
{
	sf::Event Event;
	while (m_window->pollEvent(Event))//every event do somthing
	{
		if (m_spritePlayeAgain.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*m_window)))
		{
			m_spritePlayeAgain.setColor(sf::Color(225, 255, 255, 128));
		}
		else
		{
			m_spritePlayeAgain.setColor(sf::Color(sf::Color::White));
		}
		if (m_spriteExit.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*m_window)))
		{
			m_spriteExit.setColor(sf::Color(225, 255, 255, 128));
			//m_spritePlayer2.setColor(sf::Color::Black);
		}
		else
		{
			m_spriteExit.setColor(sf::Color(sf::Color::White));
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

				if (m_spritePlayeAgain.getGlobalBounds().contains
				(m_window->mapPixelToCoords({ Event.mouseButton.x, Event.mouseButton.y })))
				{
					return screens::START_AGAIN;
				}
				else if (m_spriteExit.getGlobalBounds().contains
				(m_window->mapPixelToCoords({ Event.mouseButton.x, Event.mouseButton.y })))
				{
					return screens::EXIT;
				}
			break;
		}
	}
	return screens::IGNORE;
}