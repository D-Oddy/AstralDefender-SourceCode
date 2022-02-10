#ifndef UI_H
#define UI_H

#include <SFML/Graphics/RenderWindow.hpp>

#include "GameText.h"
#include "ScoreManager.h"

class UI 
{
private:
	GameText   m_livesText;			//Text object showing the player's lives
	GameText   m_scoreText;			//Text object showing the player's score
	GameText   m_aliveText;			//Text object showing the amount of invaders left 
	GameText   m_levelText;			//Text object showing the current level number
	GameText   m_waveText;			//Text object showing the current wave number

public:
	UI();
	~UI();

	//Getter functions for all of the game's UI elements, so that they can easily be accessed and modified where necessary

	//-------------------------------------------------------
	// Function Name	: getLivesText
	// Parameters		: none
	// Returns			: m_livesText
	// Purpose			: accessing the 'lives' game text
	//-------------------------------------------------------
	GameText& getLivesText() { return m_livesText; }

	//-------------------------------------------------------
	// Function Name	: getScoreText
	// Parameters		: none
	// Returns			: m_scoreText
	// Purpose			: accessing the 'score' game text
	//-------------------------------------------------------
	GameText& getScoreText() { return m_scoreText; }

	//-------------------------------------------------------
	// Function Name	: getAliveText
	// Parameters		: none
	// Returns			: m_aliveText
	// Purpose			: accessing the 'alive' game text
	//-------------------------------------------------------
	GameText& getAliveText() { return m_aliveText; }

	//-------------------------------------------------------
	// Function Name	: getLevelText
	// Parameters		: none
	// Returns			: m_levelText
	// Purpose			: accessing the 'level' game text
	//-------------------------------------------------------
	GameText& getLevelText() { return m_levelText; }

	//-------------------------------------------------------
	// Function Name	: getWaveText
	// Parameters		: none
	// Returns			: m_waveText
	// Purpose			: accessing the 'wave' game text
	//-------------------------------------------------------
	GameText& getWaveText()  { return m_waveText; }

	//-------------------------------------------------------
	// Function Name	: draw
	// Parameters		: sf::RenderWindow& window
	// Returns			: none
	// Purpose			: drawing the game's UI
	//-------------------------------------------------------
	void draw( sf::RenderWindow& window );
};
#endif //!UI_H