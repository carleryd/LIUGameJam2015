#include "Entity.h"
#include "World.h"

Entity::Entity(World* pWorld)
{
	_pWorld = pWorld;
}


void Entity::Update()
{

}


void Entity::Draw()
{
	_pWorld->_pWindow->draw(_Sprite);
}


void Entity::setPosition(sf::Vector2f Position)
{
	_Sprite.setPosition(Position);
}


void Entity::setTexture(const std::string& filename, const sf::IntRect& area)
{
	if(!_Texture.loadFromFile(filename, area))
	{
		//std::cout <<"failed to load texture " <<filename <<"\n";
	}
	_Sprite.setTexture(_Texture);
}