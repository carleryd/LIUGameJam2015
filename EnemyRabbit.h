#include "Enemy.h"
class World;

class EnemyRabbit : public Enemy
{
public:
    EnemyRabbit(World* pWorld);
    void Update();

private:
    int _walkDuration;
    float _speed;
};