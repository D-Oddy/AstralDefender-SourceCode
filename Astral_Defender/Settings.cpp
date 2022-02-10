#include <SFML\Window\Keyboard.hpp>

#include "Settings.h"

const char* m_subMenuTexture = "assets/graphics/over.png";
const char* m_settingsFont = "assets/fonts/game_over.ttf";
const char* m_volButtonTexture = "assets/graphics/arrow.png";

Settings::Settings()
{
	//Menu screen and text setup
	m_menuBackground.load( m_subMenuTexture );
	m_menuBackground.setPosition( 900, 500 );
	m_menuBackground.setScale( 1.8f, 1.35f );

	m_menuTitleText.load( m_settingsFont );
	m_menuTitleText.setString( "Settings" );
	m_menuTitleText.setCharacterSize( 300 );
	m_menuTitleText.setPosition( 500.0f, -50.0f );

	m_volumeText.load( m_settingsFont );
	m_volumeText.setCharacterSize( 200 );
	m_volumeText.setPosition( 500.0f, 200.0f );

	m_invertText.load( m_settingsFont );
	m_invertText.setString( "Inversion:" );
	m_invertText.setCharacterSize( 200 );
	m_invertText.setPosition( 500.0f, 400.0f );
	//End of menu screen and text setup

	//Settings buttons setup
	m_volButtons.load( m_volButtonTexture );

	m_volUpButton.setSprite( m_volButtons );
	m_volUpButton.getSprite().setPosition( 950.0f, 320.0f );
	m_volUpButton.getHoverSprite().load( m_volButtonTexture );
	m_volUpButton.getHoverSprite().setPosition( 950.0f, 320.0f );

	m_volDownButton.setSprite( m_volButtons );
	m_volDownButton.getSprite().setPosition( 950.0f, 420.0f );
	m_volDownButton.getSprite().setRotation( 180.0f );
	m_volDownButton.getHoverSprite().load( m_volButtonTexture );
	m_volDownButton.getHoverSprite().setPosition( 950.0f, 420.0f );
	m_volDownButton.getHoverSprite().setRotation( 180.0f );

	m_invertButton.getSprite().setPosition( 970.0f, 570.0f );
	m_invertButton.getSprite().setScale( 0.50f, 0.70f );
	m_invertButton.getHoverSprite().setPosition( 970.0f, 570.0f );
	m_invertButton.getHoverSprite().setScale( 0.50f, 0.70f );

	GameText& invertText = m_invertButton.getText();

	invertText.setString( "Off" );
	invertText.setCharacterSize( 200 );
	invertText.setPosition( 900.0f, 400.0f );

	GameText& backText = m_backButton.getText();

	backText.setString( "> Back" );
	backText.setCharacterSize( 200 );
	backText.setPosition( 500.0f, 600.0f );

	m_backButton.getSprite().setPosition( 650.0f, 770.0f );
	m_backButton.getSprite().setScale( 0.75f, 0.75f );
	m_backButton.getHoverSprite().setPosition( 650.0f, 770.0f );
	m_backButton.getHoverSprite().setScale( 0.75f, 0.75f );
	//End of settings button setup

	m_volume = 50;
	m_invert = false;
	m_display = false;
}

Settings::~Settings()
{
}

void Settings::draw( sf::RenderWindow& window )
{
	//Draw all settings menu items if menu is active
	if ( m_display )
	{
		window.draw( m_menuBackground );
		window.draw( m_menuTitleText );
		window.draw( m_volumeText );
		window.draw( m_invertText );

		m_volUpButton.draw( window );
		m_volDownButton.draw( window );
		m_invertButton.draw( window );
		m_backButton.draw( window );

		m_backButton.setActive( true );
	}
	else 
	{
		m_backButton.setActive( false );
	}
}

void Settings::update( sf::RenderWindow& window )
{
	int vol = static_cast<int>( m_volume * 2 );

	m_volumeText.setString( "Volume: " + std::to_string( vol ) );

	//Update all menu items if menu is active
	if ( m_display )
	{
		if ( m_volUpButton.pressed( window ) && m_volume < 50.0f )
		{
			m_volume = m_volume + 0.05f;
		}

		if ( m_volDownButton.pressed( window ) && m_volume > 0.0f )
		{
			m_volume = m_volume - 0.05f;
		}

		if ( m_invertButton.pressed( window ) )
		{
			toggleInvert();
		}
	}
}

void Settings::toggleInvert()
{
	GameText& invertText = m_invertButton.getText();

	if ( m_invert == true )
	{
		m_invert = false;
		invertText.setString( "Off" );
	}
	else if ( m_invert == false )
	{
		m_invert = true;
		invertText.setString( "On" );
	}
}