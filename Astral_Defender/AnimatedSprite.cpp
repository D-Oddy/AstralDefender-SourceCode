#include "AnimatedSprite.h"
#include "Helpers.h"

AnimatedSprite::AnimatedSprite()
	: Collidable()
	, m_numFrames( 1 )
	, m_frameWidth( 1 )
	, m_textureDimensions( 1, 1 )
	, m_animationTimer( 0.0f )
	, m_animationFramesPerSecond( 15.0f )
{
}

AnimatedSprite::~AnimatedSprite()
{
}

void AnimatedSprite::loadSpriteSheet( const char* textureFileName, int numFrames )
{
	load( textureFileName );

	// Store the number of frames
	m_numFrames = numFrames;

	// Store the texture dimensions
	m_textureDimensions = getTexture().getSize();

	// Calculate the width of the frame now that we have loaded a texture
	m_frameWidth = m_textureDimensions.x / numFrames;

	setFrame( 0 );

	// Set Origin (handle) of the AnimatedSprite to be the centre of the frames (NB: Assumes horizontal sprite-sheet)
	setOrigin( static_cast<float>(m_frameWidth) * 0.5f,
		static_cast<float>(m_textureDimensions.y) * 0.5f );
}

void AnimatedSprite::setFrame( int frame )
{
	ASSERT( frame < m_numFrames );
	setTextureRect( sf::IntRect( m_frameWidth * frame, 0, m_frameWidth, m_textureDimensions.y ) );
}

void AnimatedSprite::setFPS( float animationFramesPerSecond )
{
	m_animationFramesPerSecond = animationFramesPerSecond;
}

void AnimatedSprite::update( float deltaTime )
{
	m_animationTimer += m_animationFramesPerSecond * deltaTime;

	int frame = static_cast<int>(m_animationTimer);

	frame %= m_numFrames;

	setFrame( frame );
}