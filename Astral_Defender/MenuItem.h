#ifndef MENUITEM_H
#define MENUITEM_H

#include <SFML/Graphics/RenderWindow.hpp>

#include "GameSprite.h"
#include "GameText.h"

class MenuItem
{
private:
	GameSprite m_itemSprite;	//the default sprite of the item
	GameSprite m_hoverSprite;	//the sprite of the item when the mouse is hovering over it

	GameText   m_itemText;		//the text displayed on the item/button

	bool m_active;				//is the item available for use?

public:
	MenuItem();
	~MenuItem();

	//-------------------------------------------------------
	// Function Name	: getSpite
	// Parameters		: none
	// Returns			: m_itemSprite
	// Purpose			: accessing the sprite of the menu item
	//-------------------------------------------------------
	GameSprite& getSprite() { return m_itemSprite; }

	//-------------------------------------------------------
	// Function Name	: setSpite
	// Parameters		: GameSprite& buttonSprite
	// Returns			: none
	// Purpose			: setting the sprite of the menu item
	//-------------------------------------------------------
	void setSprite( GameSprite& buttonSprite ) { m_itemSprite = buttonSprite; }

	//-------------------------------------------------------
	// Function Name	: getHoverSpite
	// Parameters		: none
	// Returns			: m_hoverSprite
	// Purpose			: accessing the sprite of the menu item when the mouse is hovering on it
	//-------------------------------------------------------
	GameSprite& getHoverSprite() { return m_hoverSprite; }

	//-------------------------------------------------------
	// Function Name	: setHoverSpite
	// Parameters		: GameSprite& hoverSprite
	// Returns			: none
	// Purpose			: setting the sprite of the menu item when the mouse is hovering on it
	//-------------------------------------------------------
	void setHoverSprite( GameSprite& hoverSprite ) { m_hoverSprite = hoverSprite; }

	//-------------------------------------------------------
	// Function Name	: getText
	// Parameters		: none
	// Returns			: m_itemText
	// Purpose			: accessing the text of the menu item
	//-------------------------------------------------------
	GameText& getText() { return m_itemText; }

	//-------------------------------------------------------
	// Function Name	: setText
	// Parameters		: GameText& buttonText
	// Returns			: none
	// Purpose			: setting the text of the button
	//-------------------------------------------------------
	void setText( GameText& buttonText ) { m_itemText = buttonText; }

	//-------------------------------------------------------
	// Function Name	: getActive
	// Parameters		: bool isItemActive
	// Returns			: none
	// Purpose			: changing whether the item is active
	//-------------------------------------------------------
	void setActive( bool isItemActive ) { m_active = isItemActive; }

	//-------------------------------------------------------
	// Function Name	: draw
	// Parameters		: sf::RenderWindow& window
	// Returns			: none
	// Purpose			: drawing the menu item/button
	//-------------------------------------------------------
	void draw( sf::RenderWindow& window );

	//-------------------------------------------------------
	// Function Name	: pressed
	// Parameters		: sf::RenderWindow& window
	// Returns			: none
	// Purpose			: checking if a button is being pressed using mouse coordinates
	//-------------------------------------------------------
	bool pressed( sf::RenderWindow& window );
};
#endif // !MENUITEM_H