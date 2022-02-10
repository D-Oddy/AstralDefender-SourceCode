#ifndef GAMEEND_H
#define GAMEEND_H

#include <SFML/Graphics/RenderWindow.hpp>

#include "GameSprite.h"
#include "GameText.h"
#include "MenuItem.h"

class GameEnd
{
private:
	GameSprite m_endScreen;
	GameText   m_endText;

	GameText   m_scoreText;

	MenuItem   m_menuButton;

	bool m_display;					//is the menu currently being displayed 

public:
	GameEnd();
	~GameEnd();

	//-------------------------------------------------------
	// Function Name	: getEndText
	// Parameters		: none
	// Returns			: m_endText
	// Purpose			: accessing the end menu's top text
	//-------------------------------------------------------
	GameText& getEndText() { return m_endText; }

	//-------------------------------------------------------
	// Function Name	: getScoreText
	// Parameters		: none
	// Returns			: m_scoreText
	// Purpose			: accessing the end menu's score text
	//-------------------------------------------------------
	GameText& getScoreText() { return m_scoreText; }

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
	// Purpose			: drawing the game end menu
	//-------------------------------------------------------
	void draw( sf::RenderWindow& window );
};
#endif // !GAMEOVER_H