#ifndef HELPERS_H
#define HELPERS_H

#include <cassert>

#include <SFML/System/Vector2.hpp>

#ifdef _DEBUG
#define ASSERT assert
#else
#define ASSERT
#endif

//Defining the play area
const float m_maxX = 1460.0f;
const float m_minX = 340.0f;
const float m_maxY = 1000.0f;
const float m_minY = -100.0f;

inline sf::Vector2f lerp( const sf::Vector2f& a, const sf::Vector2f& b, float t );

template <typename T> void safeDelete( T* &p )
{
	if ( p )
	{
		delete p;
			p = nullptr;
	}
}
#endif