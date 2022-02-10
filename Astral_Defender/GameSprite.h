#ifndef GAMESPRITE_H
#define GAMESPRITE_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "Helpers.h"

class GameSprite : public sf::Sprite
{
private:
	sf::Texture m_texture;			//the texture to use for the sprite

public:
	GameSprite();
	~GameSprite();

	//-------------------------------------------------------
	// Function Name	: getTexture
	// Parameters		: none
	// Returns			: m_texture
	// Purpose			: accessing the texture of a gameSprite
	//-------------------------------------------------------
	sf::Texture& getTexture() { return m_texture; }

	//-------------------------------------------------------
	// Function Name	: load
	// Parameters		: const char* textureFileName
	// Returns			: none
	// Purpose			: loading in a texture to the game
	//-------------------------------------------------------
	bool load( const char* textureFileName );
};
#endif