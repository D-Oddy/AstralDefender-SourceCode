#include <SFML\Window\Keyboard.hpp>

#include "GameMenus.h"

GameMenus::GameMenus()
{
}

GameMenus::~GameMenus()
{
}

void GameMenus::draw( sf::RenderWindow& window )
{
	m_gameEndMenu.draw( window );
	m_pauseMenu.draw( window );
}

void GameMenus::update( sf::RenderWindow& window )
{
	//Pause the game is p is pressed
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::P ) )
	{
		m_pauseMenu.setDisplay( true );
	}

	//Resume is play button is pressed
	if ( m_pauseMenu.getPlayButton().pressed( window ) )
	{
		m_pauseMenu.setDisplay( false );
	}
}