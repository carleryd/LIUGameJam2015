#include "Entity.h"
#include "World.h"

Entity::Entity() {}
Entity::Entity(World* pWorld, EntityType entityType)
{
	_pWorld = pWorld;
	_size = 64.0;
	_entityType = entityType;
    _sprite.setOrigin(sf::Vector2f(_size/2, _size/2));
}

void Entity::Update()
{

}

void Entity::Draw()
{
	_pWorld->_pRenderTexture->draw(_sprite);
}


void Entity::setTexture(sf::Texture* texture)
{
	_sprite.setTexture(*texture);
}

void Entity::setPosition(const sf::Vector2f position)
{
	_sprite.setPosition(position);
}

void Entity::setPositionX(float x)
{
	_sprite.setPosition(x, _sprite.getPosition().y);
}


void Entity::setPositionY(float y)
{
	_sprite.setPosition(_sprite.getPosition().x, y);
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


sf::Vector2f Entity::getOrigin()
{
	return _sprite.getOrigin();
}


void Entity::setOrigin(sf::Vector2f origin)
{
	_sprite.setOrigin(origin);
}