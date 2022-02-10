#ifndef SETTINGS_H
#define SETTINGS_H

#include <SFML/Graphics/RenderWindow.hpp>

#include "GameSprite.h"
#include "GameText.h"
#include "MenuItem.h"

class Settings
{
private:
	GameSprite  m_menuBackground;
	GameSprite  m_volButtons;

	GameText    m_menuTitleText;
	GameText    m_volumeText;
	GameText	m_invertText;

	MenuItem	m_volUpButton;
	MenuItem	m_volDownButton;
	MenuItem	m_invertButton;
	MenuItem	m_backButton;

	float	m_volume;			//the current volume value of the game audio
	bool	m_invert;			//are the controls currently inverted?
	bool	m_display;			//is the settings menu being displayed?

public:
	Settings();
	~Settings();

	//-------------------------------------------------------
	// Function Name	: getBackButtton
	// Parameters		: none
	// Returns			: m_backButton
	// Purpose			: access the back button
	//-------------------------------------------------------
	MenuItem& getBackButton() { return m_backButton; }

	//-------------------------------------------------------
	// Function Name	: getVolume
	// Parameters		: none
	// Returns			: m_volume
	// Purpose			: accessing the volume value
	//-------------------------------------------------------
	float getVolume() { return m_volume; }

	//-------------------------------------------------------
	// Function Name	: setVolume
	// Parameters		: float vol
	// Returns			: none
	// Purpose			: setting the volume value
	//-------------------------------------------------------
	void setVolume( float vol ) { m_volume = vol; }

	//-------------------------------------------------------
	// Function Name	: getInvert
	// Parameters		: none
	// Returns			: m_invert
	// Purpose			: access whether the controls are inverted or not
	//-------------------------------------------------------
	bool getInvert() { return m_invert; }

	//-------------------------------------------------------
	// Function Name	: getDisplay
	// Parameters		: none
	// Returns			: m_display
	// Purpose			: access whether the settings menu is displayed or not
	//-------------------------------------------------------
	bool getDisplay() { return m_display; }

	//-------------------------------------------------------
	// Function Name	: setDisplay
	// Parameters		: bool isDisplayed
	// Returns			: none
	// Purpose			: change whether the settings menu is displayed or not
	//-------------------------------------------------------
	void setDisplay( bool isDisplayed ) { m_display = isDisplayed; }

	//-------------------------------------------------------
	// Function Name	: draw
	// Parameters		: sf::RenderWindow& window 
	// Returns			: none
	// Purpose			: draw the settings menu
	//-------------------------------------------------------
	void draw( sf::RenderWindow& window );

	//-------------------------------------------------------
	// Function Name	: update
	// Parameters		: sf::RenderWindow& window 
	// Returns			: none
	// Purpose			: update the settings menu
	//-------------------------------------------------------
	void update( sf::RenderWindow& window );

	//-------------------------------------------------------
	// Function Name	: toggleInvert
	// Parameters		: none
	// Returns			: none
	// Purpose			: toggling the inversion of the controls
	//-------------------------------------------------------
	void toggleInvert();
};
#endif // !SETTINGS_H