#include <SFML\Window\Mouse.hpp>

#include "MenuItem.h"

const char* m_itemTexture = "assets/graphics/selected.png";
const char* m_itemFont = "assets/fonts/game_over.ttf";

MenuItem::MenuItem()
{
	//buttton setup
	m_itemSprite.load( m_itemTexture );
	
	m_hoverSprite.load( m_itemTexture );
	m_hoverSprite.setColor( sf::Color( 0xea168eff ) );

	m_itemText.load( m_itemFont );
	//end of button setup

	m_active = true;	//is the menu item active/able to be used
}

MenuItem::~MenuItem()
{
}

void MenuItem::draw( sf::RenderWindow& window )
{
	//Draw the button and the text that is written on the button
	if (m_active)
	{
		window.draw( m_itemSprite );
		window.draw( m_itemText );
	}
}

bool MenuItem::pressed( sf::RenderWindow& window )
{
	//Check if the mouse is inside the bounds of the button sprite*
	if (m_itemSprite.getGlobalBounds().contains( window.mapPixelToCoords( sf::Mouse::getPosition( window ) ) )
		&& m_active)
	{
		//draw a sprite to show that the button is being hovered over
		window.draw( m_hoverSprite );

		//*and if the left mouse button is being pressed at the same time
		if (sf::Mouse::isButtonPressed( sf::Mouse::Left ))
		{
			// in game button has been pressed
			return true;
		}
	}

	//in game button has not been pressed 
	return false;
}