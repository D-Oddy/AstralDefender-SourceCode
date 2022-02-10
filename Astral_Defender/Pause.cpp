#include "Pause.h"

const char* m_pauseScreenTexture = "assets/graphics/over.png";
const char* m_pauseFont = "assets/fonts/game_over.ttf";

Pause::Pause()
{
	//Menu screen setup
	m_pauseScreen.load( m_pauseScreenTexture );
	m_pauseScreen.setPosition( 900, 500 );
	m_pauseScreen.setScale( 1.8f, 1.35f );
	//End of menu screen setup

	//Title text setup
	m_pauseText.load( m_pauseFont );
	m_pauseText.setString( "Paused" );
	m_pauseText.setCharacterSize( 300 );
	m_pauseText.setPosition( 600.0f, -50.0f );
	//End of title text setup

	//Play button setup
	GameText& playText = m_playButton.getText();

	playText.setString( "Play <" );
	playText.setCharacterSize( 200 );
	playText.setPosition( 800.0f, 300.0f );

	m_playButton.setText( playText );
	m_playButton.getSprite().setPosition( 900.0f, 470.0f );
	m_playButton.getSprite().setScale( 0.75f, 0.75f );
	m_playButton.getHoverSprite().setPosition( 900.0f, 470.0f );
	m_playButton.getHoverSprite().setScale( 0.75f, 0.75f );
	//End of Play button setup

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

Pause::~Pause()
{
}

void Pause::draw( sf::RenderWindow& window )
{
	//Draw all pause menu items if the menu is active
	if ( m_display ) 
	{
		window.draw( m_pauseScreen );
		window.draw( m_pauseText );

		m_playButton.draw( window );
		m_menuButton.draw( window );

		m_playButton.setActive( true );
		m_menuButton.setActive( true );
	}
	else 
	{
		m_playButton.setActive( false );
		m_menuButton.setActive( false );
	}
}