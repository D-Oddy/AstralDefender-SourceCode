#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

#include "Collidable.h"

class AnimatedSprite : public Collidable
{
private:
	sf::Vector2u	m_textureDimensions;

	int				m_numFrames;
	int				m_frameWidth;

	float			m_animationTimer;
	float			m_animationFramesPerSecond;

public:
	AnimatedSprite();
	~AnimatedSprite();

	//-------------------------------------------------------
	// Function Name	: loadSpriteSheet
	// Parameters		: const char* textureFileName, int numFrames
	// Returns			: none
	// Purpose			: loading in a sprite sheet texture for the animation (specifying a frame number)
	//-------------------------------------------------------
	void loadSpriteSheet( const char* textureFileName, int numFrames );

	//-------------------------------------------------------
	// Function Name	: setFrame
	// Parameters		: int frame
	// Returns			: none
	// Purpose			: Choosing a frame of the sprite-sheet
	// See also			: setFPS
	//-------------------------------------------------------
	void setFrame( int frame ); 

	//-------------------------------------------------------
	// Function Name	: setFPS
	// Parameters		: float animationFramesPerSecond 
	// Returns			: none
	// Purpose			: Choosing a frames per second of an animated sprite sheet
	// See also			: setFrame
	//-------------------------------------------------------
	void setFPS( float framesPerSecond );

	//-------------------------------------------------------
	// Function Name	: update
	// Parameters		: float deltaTime
	// Returns			: none
	// Purpose			: Updating the animation
	//-------------------------------------------------------
	void update( float deltaTime );
};
#endif