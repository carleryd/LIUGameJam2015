#include "Entity.h"
#include "World.h"

Entity::Entity(World* pWorld)
{
	_pWorld = pWorld;
	_size = 64.0;
}


Entity::~Entity()
{

}


void Entity::Update()
{

}


void Entity::Draw()
{
	_pWorld->_pWindow->draw(_sprite);
}



void Entity::setTexture(sf::Texture* texture)
{
	_sprite.setTexture(*texture);
}


void Entity::setPosition(const sf::Vector2f position)
{
	_sprite.setPosition(position);
}


sf::Vector2f Entity::getPosition()
{
	return _sprite.getPosition();
}


float Entity::getSize()
{
	return _size;
}


void Entity::setSize(float size)
{
	_size = size;
}