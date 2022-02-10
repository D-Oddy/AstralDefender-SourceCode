#ifndef INVADER_H
#define INVADER_H

#include "AnimatedSPrite.h"
#include "BulletPool.h"
#include "GameSound.h"

class Invader : public AnimatedSprite
{
private:
	sf::Vector2f	position;			//current position of the invader

	GameSound		m_explode;			//sound for enemies exploding on hit

	Bullet			m_bullet;			//using a single bullet to save space ( each enemy doesn't need a whole pool of bullets )

	float			m_health;			//health amount of the enemy
	float			m_speed;			//speed of the enemy
	float			m_bulletSpeed;		//speed of the invader's bullets

	bool			m_reachedEdge;		//has an invader reached the edge of the play area?
	bool			m_reachedPlayer;	//has an invader reached the bottom of the play area?

public:
	Invader();
	~Invader();

	//-------------------------------------------------------
	// Function Name	: setHealth
	// Parameters		: float h 
	// Returns			: none
	// Purpose			: setting the health value of an enemy
	//-------------------------------------------------------
	void setHealth( float h ) { m_health = h; }

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
	// Function Name	: getSides
	// Parameters		: none
	// Returns			: m_reachedEdge
	// Purpose			: detecting if an invader has reached a side boundary
	// See also         : getBottom
	//-------------------------------------------------------
	bool getSides() { return m_reachedEdge; }

	//-------------------------------------------------------
	// Function Name	: getBottom
	// Parameters		: none
	// Returns			: m_reachedPlayer
	// Purpose			: detecting if an invader has reached the bottom boundary/the player
	// See also         : getSides
	//-------------------------------------------------------
	bool getBottom() { return m_reachedPlayer; }

	//-------------------------------------------------------
	// Function Name	: draw
	// Parameters		: sf::RenderWindow& window
	// Returns			: none
	// Purpose			: drawing the invader
	//-------------------------------------------------------
	void draw( sf::RenderWindow& window );

	//-------------------------------------------------------
	// Function Name	: update
	// Parameters		: float deltaTime, Collidable& collider, Collidable& collider1
	// Returns			: none
	// Purpose			: updating the invader
	//-------------------------------------------------------
	void update( float deltaTime, Collidable& collider, Collidable& collider1 );

	//-------------------------------------------------------
	// Function Name	: movement
	// Parameters		: float deltaTime
	// Returns			: none
	// Purpose			: handling individual invader movement
	// See also			: rowDown, rowMax
	//-------------------------------------------------------
	void movement( float deltaTime );

	//-------------------------------------------------------
	// Function Name	: shooting
	// Parameters		: float deltaTime, Collidable& player, Collidable& shield 
	// Returns			: none
	// Purpose			: handling invader shooting and bullets
	// See also			: m_bullet.fired(), m_bullet.update()
	//-------------------------------------------------------
	void shooting();

	//-------------------------------------------------------
	// Function Name	: takeDamage
	// Parameters		: none
	// Returns			: none
	// Purpose			: depleating the enemy's health when collidig with an player bullet
	// See also			: collidable.collision(), destroyed()
	//-------------------------------------------------------
	void takeDamage();

	//-------------------------------------------------------
	// Function Name	: destroyed
	// Parameters		: none 
	// Returns			: none
	// Purpose			: handling enemy behaviour when hit by the player
	// See also			: Collidable.collision(), takeDamage()
	//-------------------------------------------------------
	void destroy();
};
#endif // !INVADER_H