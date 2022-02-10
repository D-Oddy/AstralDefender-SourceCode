#include "GameSound.h"
#include "Helpers.h"

GameSound::GameSound()
{
}

GameSound::~GameSound()
{
}

bool GameSound::load( const char* audioFileName )
{
	bool loadedSuccess = m_soundBuffer.loadFromFile( audioFileName );
	ASSERT( loadedSuccess );

	setBuffer( m_soundBuffer );

	return loadedSuccess;
}