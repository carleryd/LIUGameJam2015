#include "Entity.h"
#include "Light.h"
#include <memory>

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
    unsigned long int _walkDuration;
	Light* _light;
};
