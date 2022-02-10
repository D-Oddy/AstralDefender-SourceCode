#include "GameEnd.h"

const char* m_endScreenTexture = "assets/graphics/over.png";
const char* m_gameOverFont = "assets/fonts/game_over.ttf";

GameEnd::GameEnd()
{
	//Menu screen setup
	m_endScreen.load( m_endScreenTexture );
	m_endScreen.setPosition( 900, 500 );
	m_endScreen.setScale( 1.8f, 1.35f );
	//End of menu screen setup

	//Title text setup
	m_endText.load( m_gameOverFont );
	m_endText.setString( "Game Over" );
	m_endText.setPosition( 480.0f, -50.0f );
	m_endText.setCharacterSize( 300 );
	m_endText.setStyle( sf::Text::Bold );
	//End of title text setup

	//Score text setup
	m_scoreText.load( m_gameOverFont );
	m_scoreText.setCharacterSize( 200 );
	m_scoreText.setPosition( 580.0f, 300.0f );
	m_scoreText.setStyle( sf::Text::Bold );
	//End of score text setup

	//Menu button setup
	GameText& menuText = m_menuButton.getText();

	menuText.setString( "Menu" );
	menuText.setCharacterSize( 200 );
	menuText.setPosition( 800.0f, 500.0f );

	m_menuButton.setText( menuText );
	m_menuButton.getSprite().setPosition( 900.0f, 670.0f );
	m_menuButton.getSprite().setScale( 0.75f, 0.75f );
	m_menuButton.getHoverSprite().setPosition( 900.0f, 670.0f );
	m_menuButton.getHoverSprite().setScale( 0.75f, 0.75f );
	//End of menu button setup

	m_display = false;
}

GameEnd::~GameEnd()
{
}

void GameEnd::draw( sf::RenderWindow& window )
{
	//Draw all game end menu items if the menu is active
	if (m_display)
	{
		window.draw( m_endScreen );
		window.draw( m_endText );
		window.draw( m_scoreText );

		m_menuButton.draw( window );
		m_menuButton.setActive( true );
	}
	else 
	{
		m_menuButton.setActive( false );
	}
}