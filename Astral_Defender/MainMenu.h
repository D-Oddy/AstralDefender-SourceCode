#ifndef MAINMENU_H
#define MAINMENU_H

#include <SFML/Graphics/RenderWindow.hpp>

#include "GameSprite.h"
#include "GameText.h"
#include "LevelSelect.h"
#include "MenuItem.h"
#include "Settings.h"

class MainMenu
{
private:
	GameSprite		m_titleScreen;
	GameText		m_titleText;
	GameText		m_titleText2;

	MenuItem		m_arcadeButton;
	MenuItem		m_levelsButton;
	MenuItem		m_settingsButton;

	LevelSelect		m_levelsMenu;
	Settings		m_settingsMenu;

	bool m_display;					//is the menu displayed?

public:
	MainMenu();
	~MainMenu();

	//-------------------------------------------------------
	// Function Name	: getArcadeButtton
	// Parameters		: none
	// Returns			: m_arcadeButton
	// Purpose			: access the button for arcade mode
	//-------------------------------------------------------
	MenuItem& getArcadeButton() { return m_arcadeButton; }

	//-------------------------------------------------------
	// Function Name	: getLevelsButtton
	// Parameters		: none
	// Returns			: m_levelsButton
	// Purpose			: access the button for levels mode
	//-------------------------------------------------------
	MenuItem& getLevelsButton() { return m_levelsButton; }

	//-------------------------------------------------------
	// Function Name	: getLevels
	// Parameters		: none
	// Returns			: m_levelsMenu
	// Purpose			: accessing the levels menu
	//-------------------------------------------------------
	LevelSelect& getLevels() { return m_levelsMenu; }

	//-------------------------------------------------------
	// Function Name	: getSettings
	// Parameters		: none
	// Returns			: m_settingsMenu
	// Purpose			: accessing the settings menu
	//-------------------------------------------------------
	Settings& getSettings() { return m_settingsMenu; }

	//-------------------------------------------------------
	// Function Name	: draw
	// Parameters		: sf::RenderWindow& window
	// Returns			: none
	// Purpose			: draw the main menu
	//-------------------------------------------------------
	void draw( sf::RenderWindow& window );

	//-------------------------------------------------------
	// Function Name	: update
	// Parameters		: sf::RenderWindow& window
	// Returns			: none
	// Purpose			: update the main menu
	//-------------------------------------------------------
	void update( sf::RenderWindow& window );
};
#endif // !MAINMENU_H