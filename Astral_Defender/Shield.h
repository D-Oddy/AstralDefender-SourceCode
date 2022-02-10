#ifndef SHIELD_H
#define SHIELD_H

#include "AnimatedSprite.h"

class Shield : public AnimatedSprite
{
private:

public:
	Shield();

	~Shield();

	//-------------------------------------------------------
	// Function Name	: update
	// Parameters		: float deltaTime
	// Returns			: none
	// Purpose			: updating the shield
	//-------------------------------------------------------
	void update( float deltaTime );
};
#endif // !SHIELD_H