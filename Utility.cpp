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

float Utility::angle(const sf::Vector2f A, sf::Vector2f B) {
    return atan2f(A.y - B.y,  A.x - B.x) * (180 / PI);
}

sf::Vector2f Utility::mul(sf::Vector2f& a, sf::Vector2f&b)
{
	return sf::Vector2f(a.x * b.x, a.y * b.y);
}

bool Utility::SSCollision(sf::Vector2f Aposition, sf::Vector2f Aorigin, float Awidth, sf::Vector2f Bposition, sf::Vector2f Borigin, float Bwidth)
{
	float Aleft = Aposition.x - Aorigin.x;
	float Aright = Aleft + Awidth;
	float Atop = Aposition.y - Aorigin.y;
	float Abottom = Atop + Awidth;

	float Bleft = Bposition.x - Borigin.x;
	float Bright = Bleft + Bwidth;
	float Btop = Bposition.y - Borigin.y;
	float Bbottom = Btop + Bwidth;

	return !(Aleft > Bright || 
			Aright < Bleft || 
			Atop > Bbottom ||
			Abottom < Btop);
}

float Utility::magnitude(sf::Vector2f a)
{
	return sqrt(pow(a.x,2) + pow(a.y,2));
}
