#pragma once
#include "Entity.h"

enum Direction { up, right, down, left };

class Enemy : public Entity
{
public:
	Enemy(World* pWorld, EntityType entityType);
    
protected:
    Direction _direction;
    
private:
};