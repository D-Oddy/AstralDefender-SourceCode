#include "Helpers.h"
#include "WaveHandler.h"

WaveHandler::WaveHandler()
{
	m_currentWave = 0;

	m_gameOver = false;

	m_shields = new Shields();

	for ( int i = 0; i < m_waveNumber; ++i )
	{
		m_waves[i] = new Wave();
	}
}

WaveHandler::~WaveHandler()
{
	for ( int i = 0; i != m_currentWave; ++i )
	{
		safeDelete( m_waves[i] );
	}
	safeDelete( m_shields );
}

void WaveHandler::draw( sf::RenderWindow& window, Player& player )
{
	//Draw all objects
	window.draw( player );
	player.draw( window );
	m_shields->draw( window );
	m_ui.draw( window );
	m_waves[m_currentWave]->draw( window );
}

void WaveHandler::update( float deltaTime, Player& player )
{
	//Update all objects
	Wave* wave = m_waves[m_currentWave];

	//Setting up the UI texts
	sf::String currentWave = "Wave:" + std::to_string( m_currentWave + 1 );
	m_ui.getWaveText().setString( currentWave );

	sf::String lives = "Lives:" + std::to_string( player.getLives() );
	m_ui.getLivesText().setString( lives );
	//End of UI text setup

	for ( int i = 0; i < m_waveSize; ++i )
	{
		player.update( deltaTime, wave->getInvader( i ), m_shields->getShields( i ) );
		wave->update( deltaTime, player, m_shields->getShields( i ) );

		wave->getInvader( i ).setSpeed( wave->getSpeed() );
	}

	player.setSpeed( 40.0f );
	m_shields->update( deltaTime );

	//If the player has lost all their lives or the wave reaches the bottom of the screen
	if ( player.defeated() || wave->reachedPlayer() )
	{
		m_gameOver = true;
	}

	//If the wave has been defeated/ player has won
	if ( wave->defeated() )
	{
		//And the wave number is not the final wave
		if ( m_currentWave < m_waveNumber - 1 ) 
		{
			//Increase the wave number and wave speed
			m_currentWave++;
			m_waves[m_currentWave]->setSpeed(m_waves[m_currentWave]->getSpeed() + 15.0f);
		}
		else 
		{
			m_gameOver = true;
		}	
	}
}