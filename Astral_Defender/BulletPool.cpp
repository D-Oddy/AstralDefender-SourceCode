#include "BulletPool.h"

BulletPool::BulletPool()
{
}

BulletPool::~BulletPool()
{
}

void BulletPool::draw( sf::RenderWindow& window )
{
	//Call draw on all active bullets
	for (int i = 0; i < m_poolSize; ++i)
	{
		//Only draw the bullet if it is set to active
		if (m_bullets[i].getActive())
		{
			window.draw( m_bullets[i] );
		}
	}
}

void BulletPool::update( float deltaTime, Collidable& collider, Collidable& collider1 )
{
	//Call update on all active bullets
	for (int i = 0; i < m_poolSize; ++i)
	{
		//Only update the bullet if it is set to active
		//This is so that all bullets don't get fired at the same time
		if (m_bullets[i].getActive())
		{
			m_bullets[i].update( deltaTime, collider, collider1 );
		}
	}
}

bool BulletPool::fire( const sf::Vector2f& position )
{
	//Set the next inactive bullet to active so that it can be fired
	for (int i = 0; i < m_poolSize; ++i)
	{
		Bullet& bullet = m_bullets[i];

		if (!bullet.getActive())
		{
			// Found the 1st inactive one! It is 'm_bullets[ i ]'. Set it's positoin and set it to active
			bullet.setPosition( position ); //Sets where the bullet is fired from
			bullet.setActive( true ); //Bullet can now be used

			return true;
		}
	}
	// Couldn't find an inactive Bullet
	return false;
}