#include "Entity.h"
#include "World.h"

Entity::Entity() {}
Entity::Entity(World* pWorld, EntityType entityType)
{
    animation = false;
	_pWorld = pWorld;
	_size = 64.0;
	_entityType = entityType;
    _sprite.setOrigin(sf::Vector2f(_size/2, _size/2));
}


Entity::~Entity()
{

}


void Entity::Update()
{

}


void Entity::Draw()
{
    if(animation) {
        // fixa
        _pWorld->_pWindow->draw(_sprites.front());
    }
    else {
		_pWorld->_pWindow->draw(_sprite);
    }
}



void Entity::setTexture(sf::Texture* texture)
{
	_sprite.setTexture(*texture);
}

void Entity::setAnimationTexture(sf::Texture* texture, int animationCount) {
    animation = true;
    for(int i = 0; i < animationCount; ++i) {
        sf::Sprite sprite;
        sprite.setTexture(*texture);
        sprite.setTextureRect(sf::IntRect(i*64, 0, (i+1)*64, 64));
        _sprites.push_back(sprite);
    }
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


sf::Vector2f Entity::getOrigin()
{
	return _sprite.getOrigin();
}


void Entity::setOrigin(sf::Vector2f origin)
{
	_sprite.setOrigin(origin);
}