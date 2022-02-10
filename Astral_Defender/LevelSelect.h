#ifndef LEVELSELECT_H
#define LEVELSELECT_H

#include <SFML/Graphics/RenderWindow.hpp>

#include "GameSprite.h"
#include "GameText.h"
#include "MenuItem.h"
#include "LevelManager.h"

class LevelSelect
{
private:
	GameText	m_endText;

	MenuItem	m_levelButtons[m_levelNumber];
	MenuItem	m_backButton;

	float	m_x;								//x coordinate used for buttons
	float	m_y;								//y coordinate used for buttons

	float	m_buttonSpacing;					//space inbetween each button's x coordinate

	bool	m_display;							//is the levels menu being displayed?

public:
	LevelSelect();
	~LevelSelect();

	//-------------------------------------------------------
	// Function Name	: getLevelButton
	// Parameters		: int index
	// Returns			: m_levelButtons[index]
	// Purpose			: access a specified number of level selection buttons
	//-------------------------------------------------------
	MenuItem& getLevelButton( int index ) { return m_levelButtons[index]; }

	//-------------------------------------------------------
	// Function Name	: getBackButtton
	// Parameters		: none
	// Returns			: m_backButton
	// Purpose			: access the back button
	//-------------------------------------------------------
	MenuItem& getBackButton() { return m_backButton; }

	//-------------------------------------------------------
	// Function Name	: setDisplay
	// Parameters		: bool isDisplayed
	// Returns			: none
	// Purpose			: changing whether the levels menu is being displayed or not
	//-------------------------------------------------------
	void setDisplay( bool isDisplayed ) { m_display = isDisplayed; }

	//-------------------------------------------------------
	// Function Name	: draw
	// Parameters		: sf::RenderWindow& window
	// Returns			: none
	// Purpose			: drawing the levels menu items
	//-------------------------------------------------------
	void draw( sf::RenderWindow& window );
};
#endif // !LEVELSELECT_H