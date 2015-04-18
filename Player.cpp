#include "Player.h"
#include "Utility.h"
#include "World.h"
#include <iostream>

#define Acceleration 0.1
#define TurnSpeed 0.3


Player::Player(World* pWorld) : Entity(pWorld)
{
	setTexture("Textures/Player.png");
	_Rotation = 0;
	_Speed = 0;
	_MaxSpeed = 0.5;
	_Sprite.setOrigin(32, 32);

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
	_pWorld->_pWindow->draw(_Sprite);

	//temp
	_pWorld->_pWindow->draw(*c);
}


void Player::Update()
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		_Speed += Acceleration;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		_Speed -= Acceleration;
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		_Rotation += TurnSpeed;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		_Rotation -= TurnSpeed;
	}

	_Sprite.setRotation(_Rotation);
	_Speed *= 0.8;

	if(_Speed > _MaxSpeed)
		_Speed = _MaxSpeed;

	sf::Vector2f direction(cos(Utility::DtoR(_Rotation)), sin(Utility::DtoR(_Rotation)));
	Utility::Normalize(direction);	
	_Sprite.move(direction.x * _Speed, direction.y * _Speed);

	//tenp
	Utility::vMul(direction, 50);
	c->setPosition(_Sprite.getPosition() + direction);
}


void Player::setRotation(float Rotation)
{
	_Sprite.setRotation(Rotation);
}