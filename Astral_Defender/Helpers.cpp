#include "Helpers.h"

sf::Vector2f lerp( const sf::Vector2f& a, const sf::Vector2f& b, float t )
{
	return a + t * (b - a);
}