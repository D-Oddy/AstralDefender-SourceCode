#ifndef BULLET_H
#define BULLET_H

#include "Collidable.h"

class Bullet : public Collidable
{
private:
	float m_speed;		//speed of the bullet

	bool m_active;		//is the bullet currently being used?

public:
	Bullet();
	~Bullet();

	//-------------------------------------------------------
	// Function Name	: getActive
	// Parameters		: none
	// Returns			: m_active
	// Purpose			: checking if a bullet is active
	//-------------------------------------------------------
	bool getActive() { return m_active; }

	//-------------------------------------------------------
	// Function Name	: setActive
	// Parameters		: bool isBulletActive
	// Returns			: none
	// Purpose			: changing whether a bullet is active
	//-------------------------------------------------------
	void setActive( bool isBulletActive ) { m_active = isBulletActive; }

	//-------------------------------------------------------
	// Function Name	: setSpeed
	// Parameters		: float speed
	// Returns			: none
	// Purpose			: changing the speed of the bullets
	//-------------------------------------------------------
	void setSpeed( float speed ) { m_speed = speed; }

	//-------------------------------------------------------
	// Function Name	: update
	// Parameters		: float deltaTime, Collidable& collider, Collidable& collider1
	// Returns			: none
	// Purpose			: updating the bullet 
	//-------------------------------------------------------
	void update( float deltaTime, Collidable& collider, Collidable& collider1 );

	//-------------------------------------------------------
	// Function Name	: fired
	// Parameters		: float deltaTime
	// Returns			: none
	// Purpose			: handle bullet behaviour once fired
	// See also			: getActive, setActive
	//-------------------------------------------------------
	void fired( float deltaTime );
};
#endif // BULLET_H