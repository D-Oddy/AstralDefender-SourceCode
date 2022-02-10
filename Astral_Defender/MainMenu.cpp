#include <SFML\Window\Keyboard.hpp>

#include "MainMenu.h"

const char* m_menuTexture = "assets/graphics/menu.png";
const char* m_titleFont = "assets/fonts/ka1.ttf";
const char* m_titleFont2 = "assets/fonts/DYMAXION.ttf";

MainMenu::MainMenu()
{
	//Main Menu setup
	//Title scree setup
	m_titleScreen.load( m_menuTexture );
	m_titleScreen.setPosition( 900, 500 );
	m_titleScreen.setScale( 1.8f, 1.35f );

	//Title text setup
	m_titleText.load( m_titleFont );
	m_titleText.setString( "Astral" );
	m_titleText.setCharacterSize( 100 );
	m_titleText.setPosition( 520.0f, 50.0f );
	m_titleText.setFillColor( sf::Color( 0x22267bff ) );
	m_titleText.setOutlineThickness( 1.5f );
	m_titleText.setOutlineColor( sf::Color::Cyan );

	m_titleText2.load( m_titleFont2 );
	m_titleText2.setString( "defender" );
	m_titleText2.setCharacterSize( 100 );
	m_titleText2.setPosition( 820.0f, 130.0f );
	m_titleText2.setRotation( -10.0f );
	m_titleText2.setFillColor( sf::Color( 0xea168eff ) );
	//End of title text setup

	//Arcade button setup
	GameText& arcadeText = m_arcadeButton.getText();

	arcadeText.setString( "Arcade" );
	arcadeText.setCharacterSize( 200 );
	arcadeText.setPosition( 560.0f, 200.0f );

	m_arcadeButton.getSprite().setPosition( 700.0f, 370.0f );
	m_arcadeButton.getSprite().setScale( 0.75f, 0.95f );
	m_arcadeButton.getHoverSprite().setPosition( 700.0f, 370.0f );
	m_arcadeButton.getHoverSprite().setScale( 0.75f, 0.95f );
	//End of arcade button setup

	//Levels button setup
	GameText& levelsText = m_levelsButton.getText();

	levelsText.setString( "Levels" );
	levelsText.setCharacterSize( 200 );
	levelsText.setPosition( 970.0f, 200.0f );
	
	m_levelsButton.getSprite().setPosition( 1100.0f, 370.0f );
	m_levelsButton.getSprite().setScale( 0.75f, 0.95f );
	m_levelsButton.getHoverSprite().setPosition( 1100.0f, 370.0f );
	m_levelsButton.getHoverSprite().setScale( 0.75f, 0.95f );
	//End of levels buttin setup

	//Settings button setup
	GameText& settingsText = m_settingsButton.getText();

	settingsText.setString( "Settings" );
	settingsText.setCharacterSize( 300 );
	settingsText.setPosition( 670.0f, 300.0f );

	m_settingsButton.getSprite().setPosition( 900.0f, 560.0f );
	m_settingsButton.getSprite().setScale( 1.25f, 0.95f );
	m_settingsButton.getHoverSprite().setPosition( 900.0f, 560.0f );
	m_settingsButton.getHoverSprite().setScale( 1.25f, 0.95f );
	//End of settings button setup

	m_display = true;
}

MainMenu::~MainMenu()
{
}

void MainMenu::draw( sf::RenderWindow& window )
{
	//Draw title screen and text
	window.draw( m_titleScreen );
	window.draw( m_titleText );
	window.draw( m_titleText2 );

	if ( m_display ) 
	{
		//Draw title screen buttons
		m_arcadeButton.draw( window );
		m_levelsButton.draw( window );
		m_settingsButton.draw( window );

		m_arcadeButton.setActive( true );
		m_levelsButton.setActive( true );
		m_settingsButton.setActive( true );
	}
	else 
	{
		//Stop displaying main menu buttons
		m_levelsButton.setActive( false );
		m_arcadeButton.setActive( false );
		m_settingsButton.setActive( false );
	}

	//dDraw levels menu
	m_levelsMenu.draw( window );

	//Draw settings menu
	m_settingsMenu.draw( window );
}

void MainMenu::update( sf::RenderWindow& window )
{
	if ( m_levelsButton.pressed( window ) )
	{
		//Set display settings 
		m_display = false;
		m_levelsMenu.setDisplay( true );
	}

	//If the settings button is pressed
	if (m_settingsButton.pressed( window ))
	{
		//Set display settings 
		m_display = false;
		m_settingsMenu.setDisplay( true );
	}

	m_settingsMenu.update( window );

	//If any back button is pressed
	if ( m_settingsMenu.getBackButton().pressed( window ) || m_levelsMenu.getBackButton().pressed( window ) )
	{
		//Display main meun
		m_display = true;

		//Stop displaying other menus
		m_settingsMenu.setDisplay( false );
		m_settingsMenu.getBackButton().setActive( false );

		m_levelsMenu.setDisplay( false );
		m_levelsMenu.getBackButton().setActive( false );
	}
}