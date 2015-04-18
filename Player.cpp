#include "Player.h"
#include "Utility.h"

#define Acceleration 0.1
#define TurnSpeed 0.1


Player::Player(World* pWorld) : Entity(pWorld)
{
	setTexture("Textures/Player.png");
	_Rotation = 0;
	_Speed = 0;
	_MaxSpeed = 0.5;
	_Sprite.setOrigin(32, 32);

	//temp
	//c
}


Player::~Player()
{

}


/*void Player::Draw()
{

}*/


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

	sf::Vector2f direction(cos(_Rotation), sin(_Rotation));
	Utility::Normalize(direction);
	_Sprite.move(direction.x * _Speed, direction.y * _Speed);
}


void Player::setRotation(float Rotation)
{
	_Sprite.setRotation(Rotation);
}