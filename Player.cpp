#include "Player.h"
#include "Utility.h"
#include "World.h"
#include <math.h>

#define Acceleration 0.1
#define TurnSpeed 0.3


Player::Player(World* pWorld) : Entity(pWorld, et_moving)
{
	setTexture(pWorld->_textureHandler.getTexture(tt_player));
	_rotation = 0;
	_speed = 0;
	_maxSpeed = 0.5;
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
	_pWorld->_pWindow->draw(_sprite);

	//temp
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
	for(Entity* e : _pWorld->Entitys)
	{
		//Colission in X
		if(Utility::SSCollision(tempPosX, getOrigin(), getSize(), e->getPosition(), e->getOrigin(), e->getSize()))
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
		//Colission in Y
		if(Utility::SSCollision(tempPosY, getOrigin(), getSize(), e->getPosition(), e->getOrigin(), e->getSize()))
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

	_sprite.move(deltaSpeed);
	//tenp
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