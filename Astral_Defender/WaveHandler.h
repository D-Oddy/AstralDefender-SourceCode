#ifndef WAVEHANDLER_H
#define WAVEHANDLER_H

#include <SFML/Graphics/RenderWindow.hpp>

#include "Player.h"
#include "Shields.h"
#include "UI.h"
#include "Wave.h"

const int m_waveNumber = 10;		//amount of waves in total

class WaveHandler
{
private:
	Shields* 	m_shields;
	UI			m_ui;
	Wave*		m_waves[m_waveNumber]; 

	int			m_currentWave;			//current/active wave number

	bool		m_gameOver;				//has the game ended?

public:
	WaveHandler();
	~WaveHandler();

	//-------------------------------------------------------
	// Function Name	: getCurrentWave
	// Parameters		: none
	// Returns			: m_currentWave
	// Purpose			: accessing the current wave number
	//-------------------------------------------------------
	int getCurrentWave() { return m_currentWave; }

	//-------------------------------------------------------
	// Function Name	: getGameOver
	// Parameters		: none
	// Returns			: m_gameOver
	// Purpose			: accessing whether the game has ended
	// See also			: m_player.defeated()
	//-------------------------------------------------------
	bool getGameOver() { return m_gameOver; }

	//-------------------------------------------------------
	// Function Name	: getUi
	// Parameters		: none
	// Returns			: m_ui
	// Purpose			: accessing the UI
	//-------------------------------------------------------
	UI& getUi() { return m_ui; }

	//-------------------------------------------------------
	// Function Name	: draw
	// Parameters		: sf::RenderWindow& window, Player& player
	// Returns			: none
	// Purpose			: drawing the wave handler drawables
	//-------------------------------------------------------
	void draw( sf::RenderWindow& window, Player& player );

	//-------------------------------------------------------
	// Function Name	: update
	// Parameters		: float deltaTime, Player& player
	// Returns			: none
	// Purpose			: updating the wave handler
	//-------------------------------------------------------
	void update( float deltaTime, Player& player );
};
#endif // !WAVEHANDLER_H