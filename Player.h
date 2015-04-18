#include "Entity.h"

class Player : public Entity
{
public:
	Player(World* pWorld);
	~Player();
	void Update();
	void Draw();
	void setRotation(float Rotation);

private:
	float _rotation;
	float _speed;
	float _maxSpeed;

	//temp
	sf::CircleShape* c;
};