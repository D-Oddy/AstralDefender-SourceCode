#include "ScoreManager.h"

ScoreManager::ScoreManager()
{
	m_currentScore = 0;
	m_highScore = 0;

	m_scoreValue = 10;
}

ScoreManager::~ScoreManager()
{
}

void ScoreManager::update()
{

}

void ScoreManager::scoreUp()
{
	//Increase score by set amount
	m_currentScore = m_currentScore + m_scoreValue;
}

void ScoreManager::highScore()
{
	if (m_currentScore > m_highScore)
	{
		m_highScore = m_currentScore;
	}
}


