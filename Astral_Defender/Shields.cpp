#include <SFML/Graphics/RenderWindow.hpp>

#include "Shields.h"
#include <iostream>

Shields::Shields()
{
	//Setting up shield positions
	m_x = 400.0f;
	m_y = 750.0f;

	for (int i = 0; i < m_shieldNum; ++i)
	{
		m_shields[i].setPosition( m_x, m_y );

		m_x = m_x + 320.0f;
	};
}

Shields::~Shields()
{
}

void Shields::draw( sf::RenderWindow& window )
{
	//Draw all shields
	for (int i = 0; i < m_shieldNum; ++i)
	{
		window.draw( m_shields[i] );
	}
}

void Shields::update( float deltaTime )
{
	//Update all shields
	for (int i = 0; i < m_shieldNum; ++i)
	{
		m_shields[i].update( deltaTime );
	}
}