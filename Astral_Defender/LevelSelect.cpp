#include "LevelSelect.h"

const char* m_itemTexture1 = "assets/graphics/selected1.png";

LevelSelect::LevelSelect()
{
	m_x = 600.0f;
	m_y = 500.0f;

	m_buttonSpacing = 300.0f;

	//Level buttons setup
	for (int i = 0; i < m_levelNumber; ++i)
	{
		GameSprite& sprite = m_levelButtons[i].getSprite();
		GameSprite& hoverSprite = m_levelButtons[i].getHoverSprite();

		GameText& levelText = m_levelButtons[i].getText();

		sprite.load( m_itemTexture1 );
		sprite.setScale( 0.7f, 0.7f );
		sprite.setPosition( m_x, m_y );

		hoverSprite.load( m_itemTexture1 );
		hoverSprite.setScale( 0.7f, 0.7f );
		hoverSprite.setPosition( m_x, m_y );

		m_x = m_x + m_buttonSpacing;

		sf::String levelNumber = std::to_string( i + 1 );

		levelText.setString( levelNumber );
		levelText.setCharacterSize( 200 );
		levelText.setPosition( m_x - 325, m_y - 175 );
	}
	//End of level buttons setup

	//Back button setup
	GameText& backText = m_backButton.getText();

	backText.setString( "> Back" );
	backText.setCharacterSize( 200 );
	backText.setPosition( 450.0f, 570.0f );

	m_backButton.getSprite().setPosition( 600.0f, 740.0f );
	m_backButton.getSprite().setScale( 0.75f, 0.75f );
	m_backButton.getHoverSprite().setPosition( 600.0f, 740.0f );
	m_backButton.getHoverSprite().setScale( 0.75f, 0.75f );
	//End of back button setup

	m_display = false;
}

LevelSelect::~LevelSelect()
{
}

void LevelSelect::draw( sf::RenderWindow& window )
{
	//Call draw on all level selection buttons
	for ( int i = 0; i < m_levelNumber; ++i )
	{
		if ( m_display )
		{
			m_levelButtons[i].draw( window );
			m_levelButtons[i].setActive( true );

			m_backButton.draw( window );
			m_backButton.setActive( true );
		}
		else
		{
			m_levelButtons[i].setActive( false );
			m_backButton.setActive( false );
		}
	}
}