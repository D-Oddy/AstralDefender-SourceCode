#include "Level.h"

Level::Level()
{
	m_complete = false;

	m_active = true;

	m_shields = new Shields();

	m_wave = new Wave();
}

Level::~Level()
{
	safeDelete( m_shields );
	safeDelete( m_wave );
}

void Level::draw( sf::RenderWindow& window, Player& player )
{
	if (m_active)
	{
		window.draw( player );
		player.draw( window );
		m_shields->draw( window );
		m_ui.draw( window );
		m_wave->draw( window );
	}
}

void Level::update( float deltaTime, Player& player )
{
	if (m_active)
	{
		for (int i = 0; i < m_waveSize; ++i)
		{
			player.update( deltaTime, m_wave->getInvader( i ), m_shields->getShields( i ) );
			m_wave->update( deltaTime, player, m_shields->getShields( i ) );

			m_wave->getInvader( i ).setSpeed( m_wave->getSpeed() );
		}

		m_shields->update( deltaTime );

		//If the player has won
		if (m_wave->defeated())
		{
			//Set the current level to be inactive
			m_active = false;
			m_complete = true;
		}

		//If the invaders have won
		if (player.defeated() || m_wave->reachedPlayer()) 
		{
			//Set the current level to be inactive
			m_active = false;
			m_complete = false;
		}

		sf::String enemies = "Invaders:" + std::to_string( m_wave->getAlive() );
		m_ui.getAliveText().setString( enemies );

		sf::String lives = "Lives:" + std::to_string( player.getLives() );
		m_ui.getLivesText().setString( lives );
	}
}

void Level::reset()
{
}
