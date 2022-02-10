#ifndef PAUSE_H
#define PAUSE_H

#include <SFML/Graphics/RenderWindow.hpp>

#include "GameSprite.h"
#include "GameText.h"
#include "MenuItem.h"

class Pause 
{
private:
	GameSprite m_pauseScreen;
	GameText   m_pauseText;

	MenuItem   m_playButton;
	MenuItem   m_menuButton;

	bool m_display;					//is the pause menu being displayed?

public:
	Pause();
	~Pause();

	//-------------------------------------------------------
	// Function Name	: getPlayButton
	// Parameters		: none
	// Returns			: m_playButton
	// Purpose			: accessing the 'play' button
	//-------------------------------------------------------
	MenuItem& getPlayButton() { return m_playButton; }

	//-------------------------------------------------------
	// Function Name	: getMenuButton
	// Parameters		: none
	// Returns			: m_menuButton
	// Purpose			: accessing the 'menu' button
	//-------------------------------------------------------
	MenuItem& getMenuButton() { return m_menuButton; }

	//-------------------------------------------------------
	// Function Name	: getDisplay
	// Parameters		: none
	// Returns			: m_display
	// Purpose			: accessing the display bool value
	//-------------------------------------------------------
	bool getDisplay() { return m_display; }

	//-------------------------------------------------------
	// Function Name	: setDisplay
	// Parameters		: bool isDisplayed
	// Returns			: none
	// Purpose			: changing the display bool value
	//-------------------------------------------------------
	void setDisplay( bool isDisplayed ) { m_display = isDisplayed; }

	//-------------------------------------------------------
	// Function Name	: draw
	// Parameters		: sf::RenderWindow& window
	// Returns			: none
	// Purpose			: drawing the pause menu
	//-------------------------------------------------------
	void draw( sf::RenderWindow& window );
};
#endif // !PAUSE_H