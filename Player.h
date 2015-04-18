#include "Entity.h"

class Player : public Entity
{
public:
	Player(World* pWorld);
	~Player();
	void Update();
	void Draw();
};