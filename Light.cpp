#include "Light.h"
#include "World.h"
#include "Player.h"
#include "Utility.h"
#include <iostream>
#include <math.h>
using namespace std;

Light::Light(World* pWorld, Player* p):
_lightCone(sf::Triangles, 3), 
_leftShade(5), _rightShade(5), _topShade(4)
{
	_pWorld = pWorld;
	_pPlayer = p;
	_lightCone[0].position = p->getPosition(); //player
	_lightCone[1].position = sf::Vector2f(10, 10); //left
	_lightCone[2].position = sf::Vector2f(25, 500); //right*/
	sf::Color yellow(255,255,0, 150);
	_lightCone[0].color = yellow;
	_lightCone[1].color = yellow;
	_lightCone[2].color = yellow;
}

void Light::draw()
{
	_pWorld->_pWindow->draw(_lightCone);
	_pWorld->_pWindow->draw(_leftShade);
	_pWorld->_pWindow->draw(_rightShade);
//	_pWorld->_pWindow->draw(_topShade);
}

sf::VertexArray& Light::getVertexArray() {
    return _lightCone;
}

void Light::update(sf::Vector2f direction, float rotation)
{
	_lightCone[0].position = _pPlayer->getPosition();
	//_lightCone[0].position =sf::Vector2f(10.0, 10.0);
	sf::Vector2f pp = _pPlayer->getPosition();
	//_lightDetector.

	

	//Utility::vMul(direction, 5);
	float width = 15.0;
	float length = 5000.0;
	float leftAngle = Utility::DtoR(rotation - width);
	float rightAngle = Utility::DtoR(rotation + width);
	float lampAngle = Utility::DtoR(rotation - 90);
	float langle = Utility::DtoR(rotation - 70);
	float wideLeftAngle = Utility::DtoR(rotation - 90);
	float wideRightAngle = Utility::DtoR(rotation + 90);

	sf::Vector2f leftPoint(cos(leftAngle), sin(leftAngle));
	sf::Vector2f rightPoint(cos(rightAngle), sin(rightAngle));
	sf::Vector2f lampPoint(cos(lampAngle), sin(lampAngle));
	sf::Vector2f wideLeftPoint(cos(wideLeftAngle), sin(wideLeftAngle));
	sf::Vector2f wideRightPoint(cos(wideRightAngle), sin(wideRightAngle));	

	Utility::Normalize(leftPoint);
	Utility::Normalize(rightPoint);
	Utility::Normalize(lampPoint);
	Utility::vMul(leftPoint, length);
	Utility::vMul(rightPoint, length);
	Utility::vMul(lampPoint, 20);
	sf::Vector2f d = direction;
	Utility::vMul(d, 0.15);
	_lightCone[1].position = leftPoint + pp;
	_lightCone[2].position = rightPoint + pp;
	_lightCone[0].position = lampPoint + pp + d;

	//shades	
	sf::Color shadow(0,0,0, 251);
	_leftShade.setFillColor(shadow);
	_rightShade.setFillColor(shadow);
	_topShade.setFillColor(shadow);

	_leftShade.setPoint(0, _lightCone[1].position);

	float lrot = Utility::DtoR(rotation-90);
	sf::Vector2f pl1(cos(langle), sin(langle));
	Utility::Normalize(pl1);
	Utility::vMul(pl1, 2000);

	sf::Vector2f d2 = direction;
	Utility::vMul(d2, 100);
	Utility::vMul(lampPoint, 100);

	Utility::Normalize(wideLeftPoint);
	Utility::Normalize(wideRightPoint);
	Utility::vMul(wideRightPoint, 1000000);
	Utility::vMul(wideLeftPoint, 1000000);
	
	_leftShade.setPoint(1, pp + wideLeftPoint);
	_leftShade.setPoint(2, pp - sf::Vector2f(-200,-200) + lampPoint);
	_leftShade.setPoint(3, pp - sf::Vector2f(-200,0) - d2);
/*	_leftShade.setPoint(1, getClosestCorner(pp - sf::Vector2f(200,-200)));
	_leftShade.setPoint(2, getClosestCorner(pp - sf::Vector2f(-200,-200)));
	_leftShade.setPoint(3, getClosestCorner(pp - d2));*/
	_leftShade.setPoint(4, _lightCone[0].position);


	_rightShade.setPoint(0, _lightCone[2].position);
	
	_rightShade.setPoint(1,pp + wideRightPoint);
	//_rightShade.setPoint(1, pp - sf::Vector2f(200,-200) - pl1);
	_rightShade.setPoint(2, pp - sf::Vector2f(-200,-200) - lampPoint);
	_rightShade.setPoint(3, pp - sf::Vector2f(-200,0) - d2);
	_rightShade.setPoint(4, _lightCone[0].position);

	Utility::vMul(d2, 100);
	_topShade.setPoint(0, _leftShade.getPoint(1));
	_topShade.setPoint(1, _leftShade.getPoint(1)+d2);
	_topShade.setPoint(2, _rightShade.getPoint(1)+d2);
	_topShade.setPoint(3, _rightShade.getPoint(1));
}

bool Light::inTriangle(sf::Vector2f p)
{
/*	bool b1, b2, b3;

    b1 = sign(pt, _lightCone[0], _lightCone[1]) < 0.0f;
    b2 = sign(pt, _lightCone[1], _lightCone[2]) < 0.0f;
    b3 = sign(pt, _lightCone[2], _lightCone[0]) < 0.0f;

    return ((b1 == b2) && (b2 == b3));*/
}

sf::Vector2f Light::getClosestCorner(sf::Vector2f v)
{
	sf::Vector2f dist(99999,99999);
	int corner; float mag = 99999;
	sf::Vector2f c1(-100, -100);
	sf::Vector2f c2(1500, -100);
	sf::Vector2f c3(1500, 1500);
	sf::Vector2f c4(-100, 1500);

	dist = c1-v;
	corner = 1;
	mag = Utility::magnitude(dist);
	float tmag = Utility::magnitude(c2-v);
	if(tmag < mag)
	{
		mag = tmag;
		corner = 2;
	}
	tmag = Utility::magnitude(c3-v);
	if(tmag < mag)
	{
		mag = tmag;
		corner = 3;
	}
	tmag = Utility::magnitude(c4-v);
	if(tmag < mag)
	{
		mag = tmag;
		corner = 4;
	}
	switch(corner)
	{
	case 1:
		return c1;
		break;
	case 2:
		return c2;
		break;
	case 3:
		return c3;
		break;
	case 4:
		return c4;
		break;
	}
}
