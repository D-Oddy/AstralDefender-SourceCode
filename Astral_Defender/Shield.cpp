#include "Shield.h"
#include <iostream>

const char* m_shieldTexture = "assets/graphics/shield.png";

Shield::Shield()
	: AnimatedSprite()
{
	loadSpriteSheet( m_shieldTexture, 6 );
	setFPS( 5.0f );

	setScale( 0.32f, 0.32f );
}

Shield::~Shield()
{
}

void Shield::update( float deltaTime )
{
	AnimatedSprite::update( deltaTime );
}