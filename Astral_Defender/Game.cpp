#include <SFML/Graphics.hpp>

#include "Game.h"
#include "Helpers.h"

const char* m_bgTexture = "assets/graphics/background.png";
const char* m_musicAudio = "assets/audio/bgMusic.wav";


Game::Game()
{
	m_background.load( m_bgTexture );
	m_background.setPosition( 900, 500 );
	m_background.setScale( 1.7f, 1.25f );

	m_music.load( m_musicAudio );
	m_music.play();

	m_levelManager = new LevelManager();
	m_waveHandler = new WaveHandler();

	m_state = State::Menu;
}

Game::~Game()
{
	safeDelete( m_levelManager );
	safeDelete( m_waveHandler );
}

void Game::handleWindowsEvents()
{
	sf::Event event;
	while ( m_window.pollEvent( event ) )
	{
		if ( event.type == sf::Event::Closed )
			m_window.close();
	}
}

void Game::run()
{
	m_window.create( sf::VideoMode( 1800, 1000 ), "ASTRAL DEFENDER" );

	m_clock.restart();

	while ( m_window.isOpen() )
	{
		// To keep the Window alive in the OS
		handleWindowsEvents();

		auto deltaTime = m_clock.restart().asSeconds();

		// Clear the Screen
		m_window.clear();

		GameEnd& endMenu = m_gameMenus.getGameEnd();		//Menu getter references
		Pause& pauseMenu = m_gameMenus.getPause();			

		m_window.draw( m_background );						//Draw the galaxy image background

		//Game state management//
		switch ( m_state )
		{
		case State::Menu:
		{
			menu();											//Main menu state
		}
		break;
		case State::Levels:
		{
			levelMode( deltaTime );							//start the game in level mode
		}
		break;
		case State::Arcade:
		{
			arcadeMode( deltaTime );						//start the game in arcade mode
		}
		}
		//End of game state management//

		//Draw and update the game menus (pause and end screen) 
		m_gameMenus.draw( m_window );
		m_gameMenus.update( m_window );

		//Return to main menu if menu button is pressed
		if ( endMenu.getMenuButton().pressed( m_window ) || pauseMenu.getMenuButton().pressed( m_window ) )
		{
			endMenu.setDisplay( false );
			pauseMenu.setDisplay( false );
			m_state = State::Menu;
		}

		//Settings management//
		if ( endMenu.getDisplay() || pauseMenu.getDisplay() )
		{
			m_music.setVolume( 25.0f );										//Lower the volume while in the end or pause menu
		}
		else
		{
			m_music.setVolume( m_mainMenu.getSettings().getVolume() );		//Set volume back to normal
		}

		if ( m_mainMenu.getSettings().getInvert() )
		{
			m_player.setInvert( true );
		}
		else
		{
			m_player.setInvert( false );
		}
		//End of settings management//

		// Finally, show what we've drawn
		m_window.display();
	}
}

void Game::menu()
{
	//Draw and update the main menu
	m_mainMenu.draw( m_window );
	m_mainMenu.update( m_window );

	if ( m_mainMenu.getArcadeButton().pressed( m_window ) )
	{
		//Start the game in arcade mode
		m_state = State::Arcade;
	}

	for ( int i = 0; i < m_levelNumber; i++ )
	{
		if ( m_mainMenu.getLevels().getLevelButton( i ).pressed( m_window ) )
		{
			//Start the game in level mode (start level corresponding to button pressed)
			m_levelManager->setCurrentLevel( i );
			m_state = State::Levels;
		}
	}
}

void Game::levelMode( float deltaTime )
{
	GameEnd& endScreen = m_gameMenus.getGameEnd();

	//// Render all objects
	m_levelManager->draw( m_window, m_player );

	//// Update all objects
	if ( !m_gameMenus.getPause().getDisplay() && !endScreen.getDisplay() )
	{
		m_levelManager->update( deltaTime, m_player );
	}

	for ( int i = 0; i < m_levelNumber; ++i )
	{
		if ( !m_levelManager->getLevel()->getActive() )
		{
			//Set up end screen
			endScreen.setDisplay( true );

			if ( m_levelManager->getLevel()->getComplete() )
			{
				endScreen.getEndText().setString( "Level complete" );
			}
			else
			{
				endScreen.getEndText().setString( "Level Failed" );
			}
		}
		else
		{
			endScreen.setDisplay( false );
		}
	}
}

void Game::arcadeMode( float deltaTime )
{
	GameEnd& endScreen = m_gameMenus.getGameEnd();

	//// Render all objects
	m_waveHandler->draw( m_window, m_player );

	//// Update all objects
	if ( !m_gameMenus.getPause().getDisplay() && !endScreen.getDisplay() )
	{
		m_waveHandler->update( deltaTime, m_player );
	}

	sf::String score = "Score:" + std::to_string( m_player.getScoreManager().getScore() );
	m_waveHandler->getUi().getScoreText().setString( score );

	if ( m_waveHandler->getGameOver() )
	{
		//Set up end screen
		endScreen.getEndText().setString( "Game Over" );
		endScreen.getScoreText().setString( score );
		endScreen.setDisplay( true );
	}
	else
	{
		endScreen.setDisplay( false );
	}
}