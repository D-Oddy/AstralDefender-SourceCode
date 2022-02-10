#ifndef WAVE_H
#define WAVE_H

#include <SFML/Graphics/RenderWindow.hpp>

#include "Invader.h"

const int m_waveSize = 8;

class Wave
{
private:
	Invader	m_invaders[m_waveSize];     //array of invader inside the wave 

	int		m_aliveInvaders;			//amount of invaders currently alive/active

	float	m_x;						//x position of the invader row
	float	m_y;						//y position of the invader row

	float	m_colSpacing;				//amount of space between each collumn of invaders
	float	m_rowSpacing;				//amount of space between each row of invaders

	float	m_speed;					//the speed of the invaders in the wave

public:
	Wave();
	~Wave();

	//-------------------------------------------------------
	// Function Name	: getInvader
	// Parameters		: int index
	// Returns			: m_invaders[index]
	// Purpose			: access a specified invader within the wave
	//-------------------------------------------------------
	Invader& getInvader( int index ) { return m_invaders[index]; }

	//-------------------------------------------------------
	// Function Name	: getAlive
	// Parameters		: none
	// Returns			: m_aliveInvaders
	// Purpose			: access the numver of alive invaders
	//-------------------------------------------------------
	int getAlive() { return m_aliveInvaders; }

	//-------------------------------------------------------
	// Function Name	: setSpeed
	// Parameters		: float s
	// Returns			: none
	// Purpose			: setting the speed value of an enemy
	//-------------------------------------------------------
	float getSpeed() { return m_speed; }

	//-------------------------------------------------------
	// Function Name	: setSpeed
	// Parameters		: float s
	// Returns			: none
	// Purpose			: setting the speed value of an enemy
	//-------------------------------------------------------
	void setSpeed( float s ) { m_speed = s; }

	//-------------------------------------------------------
	// Function Name	: draw
	// Parameters		: sf::RenderWindow& window
	// Returns			: none
	// Purpose			: drawing the wave of invaders
	//-------------------------------------------------------
	void draw( sf::RenderWindow& window );

	//-------------------------------------------------------
	// Function Name	: update
	// Parameters		: float deltaTime, Collidable& collider, Collidable& collider1
	// Returns			: none
	// Purpose			: updating the wave of invaders
	//-------------------------------------------------------
	void update( float deltaTime, Collidable& collider, Collidable& collider1 );

	//-------------------------------------------------------
	// Function Name	: movement
	// Parameters		: float deltaTime
	// Returns			: none
	// Purpose			: handling movement the rows of invaders
	// See also			: getInvaders, m_invaders.movement()
	//-------------------------------------------------------
	void movement( float deltaTime );

	//-------------------------------------------------------
	// Function Name	: waveOver
	// Parameters		: none
	// Returns			: none
	// Purpose			: conditions and events for when the wave is over
	// See also			: getInvaders, m_invaders.movement()
	//-------------------------------------------------------
	bool reachedPlayer();

	//-------------------------------------------------------
	// Function Name	: defeated
	// Parameters		: none
	// Returns			: none
	// Purpose			: conditions and events for when the wave has been defeated
	//-------------------------------------------------------
	bool defeated();

	void reset();
};
#endif // !WAVE_H