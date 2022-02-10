#ifndef BULLETPOOL_H
#define BULLETPOOL_H

#include <SFML/Graphics/RenderWindow.hpp>

#include "Bullet.h"

const int m_poolSize = 4;			//amount of bullets per pool / on screen at one time

class BulletPool
{
private:
	Bullet m_bullets[m_poolSize];	//array of bullets that are in the pool

public:
	BulletPool();
	~BulletPool();

	//-------------------------------------------------------
	// Function Name	: getBullet
	// Parameters		: int index
	// Returns			: m_bullets[index]
	// Purpose			: accessing specified bullets from the pool
	//-------------------------------------------------------
	Bullet& getBullet( int index ) { return m_bullets[index]; }

	//-------------------------------------------------------
	// Function Name	: draw
	// Parameters		: sf::RenderWindow& window
	// Returns			: none
	// Purpose			: drawing the bullet pool
	//-------------------------------------------------------
	void draw( sf::RenderWindow& window );

	//-------------------------------------------------------
	// Function Name	: update
	// Parameters		: float deltaTime, Collidable& collider, Collidable& collider1
	// Returns			: none
	// Purpose			: updating the bullet pool
	//-------------------------------------------------------
	void update( float deltaTime, Collidable& collider, Collidable& collider1 );

	//-------------------------------------------------------
	// Function Name	: fire
	// Parameters		: const sf::Vector2f& position
	// Returns			: none
	// Purpose			: firing bullets from within the pool when active
	// See also			: getBullets, Bullet.fired()
	//-------------------------------------------------------
	bool fire( const sf::Vector2f& position );
};
#endif // !BULLETPOOL_H