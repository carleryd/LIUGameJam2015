#include "EntityEmpty.h"
#include "World.h"

EntityEmpty::EntityEmpty(World* pWorld) : Entity(pWorld)
{
}


void EntityEmpty::Update()
{

}


void EntityEmpty::Draw()
{
	_pWorld->_pWindow->draw(_Sprite);
}


void EntityEmpty::setPosition(sf::Vector2f Position)
{
	_Sprite.setPosition(Position);
}


void EntityEmpty::setTexture(const std::string& filename, const sf::IntRect& area)
{
	if(!_Texture.loadFromFile(filename, area))
	{
		//std::cout <<"failed to load texture " <<filename <<"\n";
	}
	_Sprite.setTexture(_Texture);
}