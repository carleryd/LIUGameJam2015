#include "Player.h"
#include "Utility.h"
#include "World.h"
#include <math.h>

#define Acceleration 0.1
#define TurnSpeed 0.3


Player::Player(World* pWorld) : Entity(pWorld)
{
	setTexture(pWorld->getResourcePath() + "Textures/Player.png");
	_rotation = 0;
	_speed = 0;
	_maxSpeed = 0.5;
	_sprite.setOrigin(32, 32);

	//temp
	c = new sf::CircleShape(6);
	c->setOrigin(3, 3);
	c->setFillColor(sf::Color::Black);
}


Player::~Player()
{

}


void Player::Draw()
{
	_pWorld->_pWindow->draw(_sprite);

	//temp
	_pWorld->_pWindow->draw(*c);
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

	sf::Vector2f direction(cos(Utility::DtoR(_rotation)), sin(Utility::DtoR(_rotation)));
	Utility::Normalize(direction);	
	_sprite.move(direction.x * _speed, direction.y * _speed);

	//tenp
	Utility::vMul(direction, 50);
	c->setPosition(_sprite.getPosition() + direction);
}


void Player::setRotation(float Rotation)
{
	_sprite.setRotation(Rotation);
}