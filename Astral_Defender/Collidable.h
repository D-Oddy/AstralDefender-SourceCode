#ifndef COLLIDABLE_H
#define COLLIDABLE_H

#include "GameSprite.h"

class Collidable : public GameSprite
{
private:
	bool m_collided;			//has there been  a collision with another game object?
	bool m_active;				//is the collidable active currently?

public:
	Collidable();
	~Collidable();

	//-------------------------------------------------------
	// Function Name	: getCollided
	// Parameters		: none
	// Returns			: m_collided
	// Purpose			: check if the collidable has collided with something
	// See also			: collision
	//-------------------------------------------------------
	bool getCollided() { return m_collided; }

	//-------------------------------------------------------
    // Function Name	: getCollided
    // Parameters		: none
    // Returns			: m_collided
	// Purpose			: changing the value of the collided variable
	// See also			: collision
	//-------------------------------------------------------
	void setCollided( bool hasCollided ) { m_collided = hasCollided; }

	//-------------------------------------------------------
	// Function Name	: getActive
	// Parameters		: none
	// Returns			: m_active
	// Purpose			: check if a collidable is active
	//-------------------------------------------------------
	bool getActive() { return m_active; }

	//-------------------------------------------------------
	// Function Name	: setActive
	// Parameters		: none
	// Returns			: m_active
	// Purpose			: changing wheather a collidable is active
	//-------------------------------------------------------
	void setActive( bool isActive ) { m_active = isActive; }

	//-------------------------------------------------------
	// Function Name	: movement
	// Parameters		: const Collidable& collider
	// Returns			: none
	// Purpose			: detect collisions of selected objects
	// See also			: getCollided, setCollided
	//-------------------------------------------------------
	bool collision( const Collidable& collider );
};
#endif // !COLLIDABLE_H