#include <SFML/System/Vector2.hpp>

#include "GameSprite.h"

GameSprite::GameSprite()
{
}

GameSprite::~GameSprite()
{
}

bool GameSprite::load( const char* textureFileName )
{
	bool loadedSuccess = m_texture.loadFromFile( textureFileName );
	ASSERT( loadedSuccess );

	setTexture( m_texture );

	sf::Vector2u dimensions = m_texture.getSize();
	setOrigin( static_cast<float>(dimensions.x) * 0.5f,
		static_cast<float>(dimensions.y) * 0.5f );

	return loadedSuccess;
}