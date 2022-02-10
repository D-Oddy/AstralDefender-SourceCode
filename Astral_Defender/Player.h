#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics/RenderWindow.hpp>

#include "AnimatedSprite.h"
#include "Bullet.h"
#include "BulletPool.h"
#include "GameSound.h"
#include "ScoreManager.h"
#include "UI.h"

class Player : public AnimatedSprite
{
private:
	sf::Vector2f position;					//the current position of the player

	BulletPool   m_bulletPool;				//group of bullets for the player to shoot
	ScoreManager m_scoreManager;			//handes functions relating to the score	

	GameSound    m_fire;					//the sound used for player shooting

	int			m_lives;					//number of player lives

	float		m_speed;					//speed of the player

	bool		m_isFired;					//has the player fired a bullet
	bool		m_inverted;					//are the player controls inverted?

public:
	Player();
	~Player();

	//-------------------------------------------------------
	// Function Name	: getScoreManager
	// Parameters		: none
	// Returns			: m_scoreManager
	// Purpose			: accessing the player's score manager component
	//-------------------------------------------------------
	ScoreManager& getScoreManager() { return m_scoreManager; }

	//-------------------------------------------------------
	// Function Name	: getLives
	// Parameters		: none
	// Returns			: m_lives
	// Purpose			: accessing the amount of lives the player has left
	//-------------------------------------------------------
	int getLives() { return m_lives; }

	//-------------------------------------------------------
	// Function Name	: setSpeed
	// Parameters		: float s
	// Returns			: none
	// Purpose			: changing the speed of the player
	//-------------------------------------------------------
	void setSpeed( float s ) { m_speed = s; }

	//-------------------------------------------------------
	// Function Name	: setInvert
	// Parameters		: bool isInverted 
	// Returns			: none
	// Purpose			: changing the state of the inversion
	//-------------------------------------------------------
	void setInvert( bool isInverted ) { m_inverted = isInverted; }

	//-------------------------------------------------------
	// Function Name	: draw
	// Parameters		: sf::RenderWindow& window
	// Returns			: none
	// Purpose			: drawing the player
	//-------------------------------------------------------
	void draw( sf::RenderWindow& window );

	//-------------------------------------------------------
	// Function Name	: update
	// Parameters		: float deltaTime, Collidable& collider, Collidable& collider1
	// Returns			: none
	// Purpose			: updating the player
	//-------------------------------------------------------
	void update( float deltaTime, Collidable& enemy, Collidable& shield );

	//-------------------------------------------------------
	// Function Name	: movement
	// Parameters		: float deltaTime
	// Returns			: none
	// Purpose			: moving the player left and right
	// See also			: moveRight, moveLeft
	//-------------------------------------------------------
	void movement( float deltaTime );

	//-------------------------------------------------------
	// Function Name	: moveRight
	// Parameters		: float deltaTime
	// Returns			: none
	// Purpose			: moving the player right
	// See also			: movement, moveLeft
	//-------------------------------------------------------
	void moveRight( float deltaTime );

	//-------------------------------------------------------
	// Function Name	: moveLeft
	// Parameters		: float deltaTime
	// Returns			: none
	// Purpose			: moving the player left
	// See also			: movement, moveRight
	//-------------------------------------------------------
	void moveLeft( float deltaTime );

	//-------------------------------------------------------
	// Function Name	: shooting
	// Parameters		: none
	// Returns			: none
	// Purpose			: calling fire() in the player's bullet pool
	// See also			: m_bulletPool.fire(), m_bulletPool.update()
	//-------------------------------------------------------
	void shooting();

	//-------------------------------------------------------
	// Function Name	: takeDamage
	// Parameters		: none
	// Returns			: none
	// Purpose			: depleating the player's health when collidig with an enemy bullet
	// See also			: collidable.collision(), defeated()
	//-------------------------------------------------------
	void takeDamage();

	//-------------------------------------------------------
	// Function Name	: defeated
	// Parameters		: none
	// Returns			: none
	// Purpose			: conditions and events for when the player has been defeated
	// See also			: takeDamage()
	//-------------------------------------------------------
	bool defeated();

	void reset();
};
#endif 