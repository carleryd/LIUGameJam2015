#include "Entity.h"

class Player : public Entity
{
public:
	Player(World* pWorld);
	~Player();
	void Update();
	//void Draw();
	void setRotation(float Rotation);

private:
	float _Rotation;
	float _Speed;
	float _MaxSpeed;

	//temp
	sf::CircleShape* c;
};