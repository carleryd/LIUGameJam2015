#include "Entity.h"
#include "World.h"

Entity::Entity(World* pWorld)
{
	_pWorld = pWorld;
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

sf::Vector2f Entity::getPos() { return _pos; }
sf::Vector2f Entity::getSize() { return _size; }

void Entity::setSpritePos(sf::Vector2f Position) { _sprite.setPosition(Position); }
void Entity::setTexture(const std::string& filename, const sf::IntRect& area)
{
	if(!_texture.loadFromFile(filename, area))
	{
		//std::cout <<"failed to load texture " <<filename <<"\n";
	}
	_sprite.setTexture(_texture);
}
void Entity::setPos(const sf::Vector2f pos) { _pos = pos; }