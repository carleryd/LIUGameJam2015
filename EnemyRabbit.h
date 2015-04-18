#include "Enemy.h"
class World;

class EnemyRabbit : public Enemy
{
public:
	EnemyRabbit(World* pWorld);
    void Update();
    bool aggro();
    void collisionHandling();

private:
    int _walkDuration;
    float _speed;
    float _rotation;
};