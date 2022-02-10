#ifndef GAMESOUND_H
#define GAMESOUND_H

#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

class GameSound : public sf::Sound
{
private:
	sf::SoundBuffer m_soundBuffer;

public:
	GameSound();
	~GameSound();

	//-------------------------------------------------------
	// Function Name	: load
	// Parameters		: const char* audioFileName
	// Returns			: none
	// Purpose			: loading an audio file into the game
	//-------------------------------------------------------
	bool load( const char* audioFileName );
};
#endif // !GAMESOUND_H