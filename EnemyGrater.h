#include "Enemy.h"

class EnemyGrater : public Enemy
{
public:
    EnemyGrater(World* pWorld);
    void Update();
    void Draw();
    
private:
    int _gameDuration;
};