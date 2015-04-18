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
	void setPositionX(float x);
	void setPositionY(float y);

	float _rotation;
	float _speed;
	float _maxSpeed;
	std::unique_ptr<Light> _light;
	//temp
	sf::CircleShape* c;
};
