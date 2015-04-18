#include "Utility.h"
#include <math.h>

#define PI 3.14159265


float Utility::Length(const sf::Vector2f& v)
{
	return sqrt(pow(v.x, 2) + pow(v.y, 2));
}


void Utility::Normalize(sf::Vector2f& v)
{
	v = v / Length(v);
}


void Utility::vMul(sf::Vector2f& v, const float f)
{
	v = sf::Vector2f(v.x * f, v.y * f);
}


float Utility::DtoR(const float& Degree)
{
	return Degree * (PI/180);
}


float Utility::RtoD(const float& Radian)
{
	return Radian * (180/PI);
}

sf::Vector2f Utility::mul(sf::Vector2f& a, sf::Vector2f&b)
{
	return sf::Vector2f(a.x * b.x, a.y * b.y);
}
