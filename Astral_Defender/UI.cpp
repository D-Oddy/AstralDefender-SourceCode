#include "UI.h"

const char* m_font = "assets/fonts/game_over.ttf";

UI::UI()
{
	//Ui element setup
	m_livesText.load( m_font );
	m_livesText.setCharacterSize( 200 );
	m_livesText.setPosition( 60.0f, 500.0f );
	m_livesText.setStyle( sf::Text::Bold );

	m_scoreText.load( m_font );
	m_scoreText.setCharacterSize( 100 );
	m_scoreText.setPosition( 100.0f, -50.0f );
	m_scoreText.setStyle( sf::Text::Bold );

	m_aliveText.load( m_font );
	m_aliveText.setCharacterSize( 100 );
	m_aliveText.setPosition( 100.0f, -50.0f );
	m_aliveText.setStyle( sf::Text::Bold );

	m_levelText.load( m_font );
	m_levelText.setCharacterSize( 100 );
	m_levelText.setPosition( 1500.0f, -50.0f );
	m_levelText.setStyle( sf::Text::Bold );

	m_waveText.load( m_font );
	m_waveText.setCharacterSize( 100 );
	m_waveText.setPosition( 1500.0f, -50.0f );
	m_waveText.setStyle( sf::Text::Bold );
	//End of Ui element setup
}

UI::~UI()
{
}

void UI::draw( sf::RenderWindow& window )
{
	//Draw all UI elements
	window.draw( m_livesText );
	window.draw( m_scoreText );
	window.draw( m_aliveText );
	window.draw( m_levelText );
	window.draw( m_waveText );
}