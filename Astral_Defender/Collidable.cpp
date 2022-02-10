#include "Collidable.h"

Collidable::Collidable()
{
	//Set default settings
	m_collided = false;
	m_active = true;
}

Collidable::~Collidable()
{
}

bool Collidable::collision( const Collidable& collider )
{
	//If the object intersects/overlaps its Colider& collider and is active
	if ( getGlobalBounds().intersects( collider.getGlobalBounds() ) && m_active )
	{
		//The object collided with its set collider
		return true;
	}
	//The object has not collided with anything
	return false;
}