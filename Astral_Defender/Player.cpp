#include <SFML\Window\Keyboard.hpp>

#include "Helpers.h"
#include "Player.h"

const char* m_playerTexture = "assets/graphics/player.png";
const char* m_fireAudio = "assets/audio/pew.wav";

Player::Player()
	:AnimatedSprite()
	, position( getPosition() )
	, m_lives( 3 )
	, m_speed( 40.0f )
	, m_isFired( false )
	, m_inverted( false )
{
	loadSpriteSheet( m_playerTexture, 6 );
	setFPS( 1.5f );
	setScale( 0.18f, 0.23f );

	position.x = 900.0f;
	position.y = 900.0f;

	m_fire.load( m_fireAudio );
}

Player::~Player()
{
}

void Player::draw( sf::RenderWindow& window )
{
	m_bulletPool.draw( window );
}

void Player::update( float deltaTime, Collidable& enemy, Collidable& shield )
{
	AnimatedSprite::update( deltaTime );

	setPosition( position.x, position.y );

	movement( deltaTime );

	shooting();

	m_bulletPool.update( deltaTime, enemy, shield );

	if ( getCollided() )
	{
		takeDamage();
	}

	//Change colour based on how many lives are left
	switch ( m_lives ) 
	{
	case 3:
		setColor( sf::Color::White );
		break;
	case 2:
		setColor( sf::Color( 0xF5B7B1ff ) );
		break;
	case 1:
		setColor( sf::Color( 0xE74C3Cff ) );
		break;
	case 0:
		setColor( sf::Color::Transparent );
		break;
	}
}

void Player::movement( float deltaTime )
{
	if ( !m_inverted )
	{
		if ( position.x <= m_maxX )//Movement boundaries
		{
			moveRight( deltaTime );
		}
		if ( position.x >= m_minX )//Movement boundaries
		{
			moveLeft( deltaTime );
		}
	}
	else
	{
		if ( position.x <= m_maxX )//Movement boundaries
		{
			moveLeft( deltaTime );
		}
		if ( position.x >= m_minX )//Movement boundaries
		{
			moveRight( deltaTime );
		}
	}
}

void Player::moveRight( float deltaTime )
{
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::D )
		|| sf::Keyboard::isKeyPressed( sf::Keyboard::Right ) )
	{
		if ( !m_inverted )
		{
			position.x += m_speed * deltaTime;
		}
		else
		{
			position.x -= m_speed * deltaTime;
		}
	}
}

void Player::moveLeft( float deltaTime )
{
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::A )
		|| sf::Keyboard::isKeyPressed( sf::Keyboard::Left ) )
	{
		if ( !m_inverted )
		{
			position.x -= m_speed * deltaTime;
		}
		else
		{
			position.x += m_speed * deltaTime;
		}
	}
}

void Player::shooting()
{
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Space ) )
	{
		//IsFired bool ensures that only one bullet can be fired at a time
		if ( m_isFired == false )
		{
			m_isFired = true;
			m_bulletPool.fire( position );
			m_fire.play();
		}
	}
	else
	{
		m_isFired = false;
	}

	for ( int i = 0; i < m_poolSize; ++i )
	{
		Bullet& bullet = m_bulletPool.getBullet( i );

		//If the bullet collides with an enemy
		if ( bullet.getCollided() )
		{
			//Add to the score and set collided to false so that the score doesn't continue to go up
			m_scoreManager.scoreUp();
			bullet.setCollided( false );
		}
	}
}

void Player::takeDamage()
{
	//Take away a life and set collided to false so that lives don't continue to go down
	m_lives--;
	setCollided( false );
}

bool Player::defeated()
{
	//If lives is less than or equal to 0
	if ( m_lives <= 0 )
	{
		//Player has been defeated
		return true;
	}
	//Player has not been defeated
	return false;
}

void Player::reset()
{
}
