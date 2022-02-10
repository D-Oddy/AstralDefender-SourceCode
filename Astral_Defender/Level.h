#ifndef LEVEL_H
#define LEVEL_H

#include "Player.h"
#include "Shields.h"
#include "UI.h"
#include "Wave.h"

class Level
{
private:
	Shields* 	m_shields;
	UI		    m_ui;
	Wave*		m_wave;			

	bool		m_active;			//is the level active (currently being played)?
	bool		m_complete;		//is the level complete/won

public:
	Level();
	~Level();

	Wave* getWave() { return m_wave; }

	//-------------------------------------------------------
	// Function Name	: getUi
	// Parameters		: none
	// Returns			: return m_ui
	// Purpose			: accessing the level's UI components
	//-------------------------------------------------------
	UI& getUi() { return m_ui; }

	//-------------------------------------------------------
	// Function Name	: getComplete
	// Parameters		: none
	// Returns			: m_complete
	// Purpose			: accessing whether a specified level is complete/won
	//-------------------------------------------------------
	bool getComplete() { return m_complete; }

	//-------------------------------------------------------
	// Function Name	: getActive
	// Parameters		: none
	// Returns			: m_active
	// Purpose			: accessing whether a specified level is active
	//-------------------------------------------------------
	bool getActive() { return m_active; }

	//-------------------------------------------------------
	// Function Name	: setActive
	// Parameters		: bool isLevelActive
	// Returns			: none
	// Purpose			: changing whether a specified level is active
	//-------------------------------------------------------
	void setActive( bool isLevelActive ) { m_active = isLevelActive; }

	//-------------------------------------------------------
	// Function Name	: draw
	// Parameters		: sf::RenderWindow& window, Player& player
	// Returns			: none
	// Purpose			: draw the level
	//-------------------------------------------------------
	void draw( sf::RenderWindow& window, Player& player );

	//-------------------------------------------------------
	// Function Name	: update
	// Parameters		: float deltaTime, Player& player
	// Returns			: none
	// Purpose			: updating the level
	//-------------------------------------------------------
	void update( float deltaTime, Player& player );

	void reset();
};
#endif // !LEVEL_H