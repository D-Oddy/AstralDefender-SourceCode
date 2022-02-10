#include <SFML/System/Vector2.hpp>

#include "Bullet.h"
#include "Helpers.h"

const char* m_bulletTexture = "assets/graphics/bullet.png";

Bullet::Bullet()
	:Collidable()
	, m_active( false )
	, m_speed( 120.0f )
{
	load( m_bulletTexture );
	setScale( 0.13f, 0.16f );
}

Bullet::~Bullet()
{
}

void Bullet::update( float deltaTime, Collidable& collider, Collidable& collider1 )
{
	if ( m_active )
	{
		fired( deltaTime );

		//If the bullet collides with its first collider
		if ( collision( collider ) && collider.getActive() )
		{
			collider.setCollided( true );
			setCollided( true );
			m_active = false;
		}
		//With its second collider
		if ( collision( collider1 ) )
		{
			m_active = false;
		}
	}
}

void Bullet::fired( float deltaTime )
{
	sf::Vector2f position = getPosition();

	//Move the bullet down the screen
	position.y -= m_speed * deltaTime; 

	//Update the bullet's position
	setPosition( position );

	//Set the bullet to inactive if it goes off the screen (bullet re-enters the queue)
	if ( position.y <= m_minY || position.y >= m_maxY )
	{
		m_active = false;
	}
}