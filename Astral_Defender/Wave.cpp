#include "Wave.h"

Wave::Wave()
{
	m_aliveInvaders = m_waveSize;

	m_x = 500.0f;
	m_y = 160.0f;

	m_colSpacing = 100.0f;
	m_rowSpacing = 81.0f;

	m_speed = 10.0f;

	int columnCount = 4;
	int rowCount = 2;

	for ( int i = 0; i < m_waveSize; ++i )
	{
		m_invaders[i].setPosition( m_x, m_y );

		m_x = m_x + m_colSpacing;
	}
}

Wave::~Wave()
{
}

void Wave::draw( sf::RenderWindow& window )
{
	//Call draw on all active invaders
	for ( int i = 0; i < m_waveSize; ++i )
	{
		//Define variables to use as a references to all invaders 
		Invader& invader = m_invaders[i];

		if ( invader.getActive() )
		{
			window.draw( invader );
		}
		invader.draw( window );
	}
}

void Wave::update( float deltaTime, Collidable& collider, Collidable& collider1 )
{
	movement( deltaTime );

	//Call update on all invaders
	for ( int i = 0; i < m_waveSize; ++i )
	{
		Invader& invader = m_invaders[i];

		invader.update( deltaTime, collider, collider1 );

		//Only call shoot on every other active invader so that there aren't too many bullets ( stops the game being too difficult )
		//If the invader index number is even
		if ( i % 2 == 0 && invader.getActive() )
		{
			invader.shooting();
		}

		if ( invader.getCollided() )
		{
			//Depleat invader's health and stop colliding
			invader.takeDamage();
			invader.setCollided( false );

			//Increase speed slightly and decrease alive invaders
			m_aliveInvaders = m_aliveInvaders - 1;
			m_speed			= m_speed + 2.5f;
		}
	}
}

void Wave::movement( float deltaTime )
{
	//Handle movement for rows of invaders
	for ( int i = 0; i < m_waveSize; ++i )
	{
		Invader& invader = m_invaders[i];

		//If an invader has reached an edge of the play area, 
		if ( m_invaders[i].getSides() )
		{
			//increase its y coordinate( move it downward )
			invader.setPosition( invader.getPosition().x, invader.getPosition().y + m_rowSpacing );
		}
	}
}

bool Wave::reachedPlayer()
{
	for ( int i = 0; i < m_waveSize; ++i )
	{
		Invader& invader = m_invaders[i];

		//Set any invader to inactive if it has reached the bottom/the player
		if ( invader.getBottom() )
		{
			invader.setActive( false );

			//The wave has reached the player
			return true;
		}
	}
	//The wave has not reached the player
	return false;
}

bool Wave::defeated()
{
	//Set the wave to be defeated if the number of alive invaders is less than or equal to 0
	//Function is a bool so that the value can be accessed when determining when the game has ended
	if ( m_aliveInvaders <= 0 )
	{
		//Wave has been defeated
		return true;
	}
	//Wave has not been defeated
	return false;
}

void Wave::reset()
{
}
