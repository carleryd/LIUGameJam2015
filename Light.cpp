#include "Light.h"
#include "World.h"
#include "Player.h"

Light::Light(World* pWorld, Player* p):
_lightCone(sf::Triangles, 3)
{
	_pWorld = pWorld;
	_pPlayer = p;
	_lightCone[0].position = p->getPosition(); //player
	_lightCone[1].position = sf::Vector2f(10, 10);
	_lightCone[2].position = sf::Vector2f(25, 500);
	_lightCone[0].color = sf::Color::Red;
	_lightCone[1].color = sf::Color::Red;
	_lightCone[2].color = sf::Color::Red;
}

void Light::draw()
{
	//_pWorld->_pWindow->draw(_lightCone);
}
