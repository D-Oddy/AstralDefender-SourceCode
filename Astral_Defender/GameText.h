#ifndef GAMETEXT_H
#define GAMETEXT_H

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>

#include "Helpers.h"

class GameText : public sf::Text
{
private:
	sf::Font m_font;

public:
	GameText();
	~GameText();

	//-------------------------------------------------------
	// Function Name	: load
	// Parameters		: const char* fontFileName
	// Returns			: none
	// Purpose			: loading in a font to the game
	//-------------------------------------------------------
	bool load( const char* fontFileName );
};
#endif // !GAMETEXT_H