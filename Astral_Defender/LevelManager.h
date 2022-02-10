#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include "Level.h"

const int m_levelNumber = 3;

class LevelManager
{
private:
	Level*  m_levels[m_levelNumber];

	int		m_currentLevel;				//the current active level number

public:
	LevelManager();
	~LevelManager();

	//-------------------------------------------------------
	// Function Name	: getLevel
	// Parameters		: none
	// Returns			: m_levels[m_currentLevel]
	// Purpose			: accessing the current level
	//-------------------------------------------------------
	Level* getLevel() { return m_levels[m_currentLevel]; }

	//-------------------------------------------------------
	// Function Name	: getCurrentLevel
	// Parameters		: m_currentLevel
	// Returns			: none
	// Purpose			: accessing the current level number
	//-------------------------------------------------------
	int getCurrentLevel() { return m_currentLevel; }

	//-------------------------------------------------------
	// Function Name	: setCurrentLevel
	// Parameters		: int level
	// Returns			: none
	// Purpose			: changing the current level number
	//-------------------------------------------------------
	void setCurrentLevel( int level ) { m_currentLevel = level; }

	//-------------------------------------------------------
	// Function Name	: draw
	// Parameters		: sf::RenderWindow&, Player& player
	// Returns			: none
	// Purpose			: drawing the level and all it's objects
	//-------------------------------------------------------
	void draw( sf::RenderWindow& window, Player& player );

	//-------------------------------------------------------
	// Function Name	: update
	// Parameters		: float deltaTime, Player& player
	// Returns			: none
	// Purpose			: updating the level and all it's objects
	//-------------------------------------------------------
	void update( float deltaTime, Player& player );
};
#endif // !