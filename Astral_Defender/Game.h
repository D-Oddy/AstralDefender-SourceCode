#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics/RenderWindow.hpp>

#include "GameMenus.h"
#include "LevelManager.h"
#include "MainMenu.h"
#include "Player.h"
#include "Shields.h"
#include "Wave.h"
#include "WaveHandler.h"

class Game
{
	enum class State
	{
		Menu,		// 0
		Levels,		// 1
		Arcade, 	// 2
	};

private:
	// Main Render window. Everything gets drawn to this
	sf::RenderWindow	m_window;

	// Member variables of game
	sf::Clock			m_clock;

	GameSound			m_music;
	GameSprite			m_background;

	LevelManager*		m_levelManager;			//Holds all code that controls levels
	MainMenu			m_mainMenu;
	GameMenus			m_gameMenus;
	Player				m_player;
	State				m_state;
	WaveHandler* 		m_waveHandler;			//Holds all code that controls waves

	void handleWindowsEvents();

public:
	Game();
	~Game();

	//-------------------------------------------------------
	// Function Name	: run
	// Parameters		: none
	// Returns			: none
	// Purpose			: run the game 
	//-------------------------------------------------------
	void run();

	//-------------------------------------------------------
	// Function Name	: menu
	// Parameters		: sf::RenderWindow& window
	// Returns			: none
	// Purpose			: starting the game's main menu
	//-------------------------------------------------------
	void menu();

	//-------------------------------------------------------
	// Function Name	: levelMode
	// Parameters		: float deltaTime, sf::RenderWindow& window, GameEnd& endScreen
	// Returns			: none
	// Purpose			: playing the game in levelled mode
	//-------------------------------------------------------
	void levelMode( float deltaTime );

	//-------------------------------------------------------
	// Function Name	: arcadeMode
	// Parameters		: float deltaTime, sf::RenderWindow& window, GameEnd& endScreen
	// Returns			: none
	// Purpose			: playing the game in arcade mode
	//-------------------------------------------------------
	void arcadeMode( float deltaTime );
};
#endif // End of '#ifndef GAME_H'