#ifndef GAMEMENUS_H
#define GAMEMENUS_H

#include <SFML/Graphics/RenderWindow.hpp>

#include "GameEnd.h"
#include "MainMenu.h"
#include "LevelSelect.h"
#include "Pause.h"
#include "Settings.h"

class GameMenus
{
private:
	GameEnd			m_gameEndMenu;

	Pause			m_pauseMenu;

	Settings		m_settingsMenu;

public:
	GameMenus();
	~GameMenus();

	//-------------------------------------------------------
	// Function Name	: getGameEnd
	// Parameters		: none
	// Returns			: m_gameEndMenu
	// Purpose			: accessing the end menu
	//-------------------------------------------------------
	GameEnd& getGameEnd() { return m_gameEndMenu; }

	//-------------------------------------------------------
	// Function Name	: getPause
	// Parameters		: none
	// Returns			: m_pauseMenu
	// Purpose			: accessing the pause menu
	//-------------------------------------------------------
	Pause& getPause() { return m_pauseMenu; }

	//-------------------------------------------------------
	// Function Name	: draw
	// Parameters		: sf::RenderWindow& window
	// Returns			: none
	// Purpose			: drawing the game's menus
	//-------------------------------------------------------
	void draw( sf::RenderWindow& window );

	//-------------------------------------------------------
	// Function Name	: update
	// Parameters		: sf::RenderWindow& window
	// Returns			: none
	// Purpose			: updating the game's menus
	//-------------------------------------------------------
	void update( sf::RenderWindow& window );
};
#endif // !GAMEMENUS_H