#ifndef SHIELDS_H
#define SHIELDS_H

#include <SFML/Graphics/RenderWindow.hpp>

#include "Shield.h"

const int m_shieldNum = 4;			//number of shields in the array

class Shields
{
private:
	Shield m_shields[m_shieldNum];

	float m_x;			//the x coordinate of the shield
	float m_y;			//the y coordinate of the shield

public:
	Shields();
	~Shields();

	//-------------------------------------------------------
	// Function Name	: getShields
	// Parameters		: int index
	// Returns			: m_shields[index]
	// Purpose			: accessing a specified shield/shields in the array
	//-------------------------------------------------------
	Shield& getShields( int index ) { return m_shields[index]; }

	//-------------------------------------------------------
	// Function Name	: draw
	// Parameters		: sf::RenderWindow& window
	// Returns			: none
	// Purpose			: drawing the shields
	//-------------------------------------------------------
	void draw( sf::RenderWindow& window );

	//-------------------------------------------------------
	// Function Name	: update
	// Parameters		: float deltaTime
	// Returns			: none
	// Purpose			: updating the shields
	//-------------------------------------------------------
	void update( float deltaTime );
};
#endif // !SHIELDS_H