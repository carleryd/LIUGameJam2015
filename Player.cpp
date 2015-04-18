#include "Player.h"
#include "Utility.h"
#include "World.h"
#include <math.h>
#include <iostream>
using namespace std;

#define Acceleration 0.8
#define TurnSpeed 3


Player::Player(World* pWorld) : Entity(pWorld, et_moving)
{
	setTexture(pWorld->_textureHandler.getTexture(tt_player_animation_4));
//    setAnimationTexture(pWorld->_textureHandler.getTexture(tt_player_animation_4), 4);
    setTexture(pWorld->_textureHandler.getTexture(tt_player_animation_4));
	_rotation = 0;
	_speed = 0;
	_maxSpeed = 3;
	_sprite.setOrigin(32, 32);

	//temp
	c = new sf::CircleShape(6);
	c->setOrigin(3, 3);
	c->setFillColor(sf::Color::Black);
	_light = std::unique_ptr<Light>(new Light(pWorld, this));
}


Player::~Player()
{

}


void Player::Draw()
{
    // animation stuff
    int walk = _walkDuration % 40;
    _sprite.setTextureRect(sf::IntRect((walk-1)/10*64, 0, 64, 64));
    _pWorld->_pWindow->draw(_sprite);
	

	//temp? :)
	_pWorld->_pWindow->draw(*c);
	_light->draw();
}


void Player::Update()
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		_speed += Acceleration;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		_speed -= Acceleration;
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		_rotation += TurnSpeed;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		_rotation -= TurnSpeed;
	}
	if(_speed > 0.1) _walkDuration++;
    if(_walkDuration > 4000000000) _walkDuration = 0;
	_sprite.setRotation(_rotation);
	_speed *= 0.8;

	if(_speed > _maxSpeed)
		_speed = _maxSpeed;

	float rotationRadian = Utility::DtoR(_rotation);
	sf::Vector2f direction(cos(rotationRadian), sin(rotationRadian));
	Utility::Normalize(direction);

	sf::Vector2f deltaSpeed(direction.x * _speed, direction.y * _speed);
	sf::Vector2f tempPosX = getPosition();
	sf::Vector2f tempPosY = getPosition();
	tempPosX.x += deltaSpeed.x;
	tempPosY.y += deltaSpeed.y;
	for(Entity* e : _pWorld->entities)
	{
		//Colission in X
		if(Utility::SSCollision(tempPosX, getOrigin(), getSize(), e->getPosition(), e->getOrigin(), e->getSize()))
		{
			if(e->_entityType == et_wall)
			{
				if(deltaSpeed.x > 0)
				{
					setPositionX(e->getPosition().x - e->getOrigin().x - getOrigin().x - 1);
				}
				else
				{
					setPositionX(e->getPosition().x + e->getOrigin().x + e->getSize() + getOrigin().x + 1);
				}
				deltaSpeed.x = 0;
			}
		}
		//Colission in Y
		if(Utility::SSCollision(tempPosY, getOrigin(), getSize(), e->getPosition(), e->getOrigin(), e->getSize()))
		{
			if(e->_entityType == et_wall)
			{
				if(deltaSpeed.y > 0)
				{
					setPositionY(e->getPosition().y - e->getOrigin().y - getOrigin().y - 1);
				}
				else
				{
					setPositionY(e->getPosition().y + e->getOrigin().y + e->getSize() + getOrigin().y + 1);
				}
				deltaSpeed.y = 0;
			}
		}
	}

	_sprite.move(deltaSpeed);
	//temp
	Utility::vMul(direction, 50);
	c->setPosition(_sprite.getPosition() + direction);
}


void Player::setRotation(float Rotation)
{
	_sprite.setRotation(Rotation);
}


void Player::setPositionX(float x)
{
	_sprite.setPosition(x, _sprite.getPosition().y);
}


void Player::setPositionY(float y)
{
	_sprite.setPosition(_sprite.getPosition().x, y);
}
