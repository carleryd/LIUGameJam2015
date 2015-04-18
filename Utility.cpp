#include "Utility.h"


float Utility::Length(const sf::Vector2f& v)
{
	return sqrt(pow(v.x, 2) + pow(v.y, 2));
}


void Utility::Normalize(sf::Vector2f& v)
{
	v = v / Length(v);
}