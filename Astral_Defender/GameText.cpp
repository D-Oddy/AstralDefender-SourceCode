#include "GameText.h"

GameText::GameText()
{
}

GameText::~GameText()
{
}

bool GameText::load( const char* fontFileName )
{
	bool loadedSuccess = m_font.loadFromFile( fontFileName );
	ASSERT( loadedSuccess );

	setFont( m_font );

	return loadedSuccess;
}