#include "Helpers.h"
#include "Invader.h"

const char* m_invaderTexture = "assets/graphics/enemy.png";
const char* m_explodeAudio = "assets/audio/boom.wav";

Invader::Invader()
	:AnimatedSprite()
	, m_health( 1 )
	, m_speed( 10 )
	, m_bulletSpeed( -55.0f )
	, m_reachedEdge( false )
	, m_reachedPlayer( false )
{
	loadSpriteSheet( m_invaderTexture, 5 );
	setFPS( 0.8f );
	setScale( 0.075f, 0.075f );
	setHealth( 1.0f );

	m_explode.load( m_explodeAudio );
}

Invader::~Invader()
{
}

void Invader::draw( sf::RenderWindow& window )
{
	window.draw( m_bullet );
}

void Invader::update( float deltaTime, Collidable& player, Collidable& shield )
{
	AnimatedSprite::update( deltaTime );

	movement( deltaTime );

	if ( position.y > 700.0f && getActive() )
	{
		m_reachedPlayer = true;
	}

	m_bullet.update( deltaTime, player, shield );
}

void Invader::movement( float deltaTime )
{
	//Handle movement for individual invaders
	position = getPosition();

	int y = static_cast<int>(position.y);

	//Determines the invader's direction based on it's y coordinate
	if ( y % 2 == 0 ) //Go right if y is even
	{
		position.x += m_speed * deltaTime;
		//If the invader has reached the right of the screen
		if ( position.x > m_maxX )
		{
			m_reachedEdge = true;
		}
		else
		{
			m_reachedEdge = false;
		}
	}
	else if ( y % 2 != 0 ) //Go left if y is odd
	{
		position.x -= m_speed * deltaTime;
		//If the invader has reached the left of the screen
		if ( position.x < m_minX )
		{
			m_reachedEdge = true;
		}
		else
		{
			m_reachedEdge = false;
		}
	}

	setPosition( position );
}

void Invader::shooting()
{
	//If the bullet is not aactive, set it to active and fire it
	if ( !m_bullet.getActive() )
	{
		m_bullet.setPosition( getPosition() );
		m_bullet.setActive( true );
		m_bullet.setSpeed( m_bulletSpeed );
		m_bullet.setRotation( 180.0f );
	}
}

void Invader::takeDamage()
{
	m_health = m_health - 1;

	if ( m_health <= 0 )
	{
		destroy();
	}
}

void Invader::destroy()
{
	//Set to inactive and play the explosion sound effect 
	setCollided( false );
	setActive( false );
	m_explode.play();
}