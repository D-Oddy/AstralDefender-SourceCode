#include "Helpers.h"
#include "LevelManager.h"

LevelManager::LevelManager()
{
	m_currentLevel = 0;

	for ( int i = 0; i < m_levelNumber; ++i )
	{
		m_levels[i] = new Level();
	}

	m_levels[m_currentLevel]->setActive( true );
}

LevelManager::~LevelManager()
{
	for ( int i = 0; i != m_currentLevel; ++i )
	{
		safeDelete( m_levels[i] );
	}
	
	safeDelete( m_levels[m_currentLevel] );
}

void LevelManager::draw( sf::RenderWindow& window, Player& player )
{
	//Call draw the current level
	m_levels[m_currentLevel]->draw( window, player );
}

void LevelManager::update( float deltaTime, Player& player )
{
	Wave* levelWave = m_levels[m_currentLevel]->getWave();

	//Call update on the active level
	m_levels[m_currentLevel]->update( deltaTime, player );

	sf::String currentLevel = "Level:" + std::to_string( m_currentLevel + 1 );
	m_levels[m_currentLevel]->getUi().getLevelText().setString( currentLevel );

	//Setting the speed for each level
	switch ( m_currentLevel ) 
	{
	case 0:
		levelWave->setSpeed( 10.0f );
		player.setSpeed( 50.0f );
		break;
	case 1:
		levelWave->setSpeed( 25.0f );
		player.setSpeed( 40.0f );
		break;
	case 2:
		levelWave->setSpeed( 40.0f );
		player.setSpeed( 30.0f );
		break;
	}
}