#ifndef SCOREMANAGER_H
#define SCOREMANAGER_H

#include "GameText.h"

class ScoreManager
{
private:
	int m_currentScore;		//player's score at current time
	int m_highScore;		//log of highest score that the playe has ever achieved

	int m_scoreValue;		//amount of points earned per kill

public:
	ScoreManager();
	~ScoreManager();

	//-------------------------------------------------------
	// Function Name	: getScore
	// Parameters		: none
	// Returns			: none
	// Purpose			: accessing the current score value
	// See also			: highScore, scoreUp
	//-------------------------------------------------------
	int getScore() { return m_currentScore; }

	//-------------------------------------------------------
	// Function Name	: update
	// Parameters		: none
	// Returns			: none
	// Purpose			: updating the score manager
	//-------------------------------------------------------
	void update();

	//-------------------------------------------------------
	// Function Name	: scoreUp
	// Parameters		: none
	// Returns			: none
	// Purpose			: increasing the score when an enemy is hit
	// See also			: highScore, getScore
	//-------------------------------------------------------
	void scoreUp();

	//-------------------------------------------------------
	// Function Name	: highScore
	// Parameters		: none
	// Returns			: none
	// Purpose			: setting and managing the player's high score
	// See also			: highScore, getScore
	//-------------------------------------------------------
	void highScore();
};
#endif // !SCOREMANAGER_H