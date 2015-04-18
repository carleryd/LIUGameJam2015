#include "Light.h"
#include "World.h"
#include "Player.h"
#include "Utility.h"
#include <iostream>
using namespace std;

Light::Light(World* pWorld, Player* p):
_lightCone(sf::Triangles, 3) /*,_lightDetector(pWorld, et_moving)*/
{
	_pWorld = pWorld;
	_pPlayer = p;
	_lightCone[0].position = p->getPosition(); //player
	_lightCone[1].position = sf::Vector2f(10, 10); //left
	_lightCone[2].position = sf::Vector2f(25, 500); //right
	sf::Color yellow(255,255,0, 150);
	_lightCone[0].color = yellow;
	_lightCone[1].color = yellow;
	_lightCone[2].color = yellow;
}

void Light::draw()
{
	_pWorld->_pWindow->draw(_lightCone);
}

void Light::update(sf::Vector2f direction, float rotation)
{
	_lightCone[0].position = _pPlayer->getPosition();
	sf::Vector2f pp = _pPlayer->getPosition();
	//_lightDetector.



	//Utility::vMul(direction, 5);
	float width = 15.0;
	float length = 500.0;
	float leftAngle = Utility::DtoR(rotation - width);
	float rightAngle = Utility::DtoR(rotation + width);
	float lampAngle = Utility::DtoR(rotation - 90);

	sf::Vector2f leftPoint(cos(leftAngle), sin(leftAngle));
	sf::Vector2f rightPoint(cos(rightAngle), sin(rightAngle));
	sf::Vector2f lampPoint(cos(lampAngle), sin(lampAngle));

	Utility::Normalize(leftPoint);
	Utility::Normalize(rightPoint);
	Utility::Normalize(lampPoint);
	Utility::vMul(leftPoint, length);
	Utility::vMul(rightPoint, length);
	Utility::vMul(lampPoint, 20);
	Utility::vMul(direction, 0.15);
	_lightCone[1].position = leftPoint + pp;
	_lightCone[2].position = rightPoint + pp;
	_lightCone[0].position = lampPoint + pp + direction;
}
