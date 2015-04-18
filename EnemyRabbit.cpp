#include "EnemyRabbit.h"
#include <stdlib.h>

EnemyRabbit::EnemyRabbit(World* pWorld) : Enemy(pWorld, et_rabbit) {
	_speed = 0.5;
}

void EnemyRabbit::Update() {
    if(_walkDuration <= 0) {
        int direction = rand() % 4 + 1;
        switch(direction) {
            case 1: _direction = up;
                break;
            case 2: _direction = right;
                break;
            case 3: _direction = down;
                break;
            case 4: _direction = left;
                break;
        }
        _walkDuration = 400;
    }
    _walkDuration--;
    
    switch(_direction) {
        case up: _sprite.move(0, -_speed);
            break;
        case right: _sprite.move(_speed, 0);
            break;
        case down: _sprite.move(0, _speed);
            break;
        case left: _sprite.move(-_speed, 0);
            break;
    }
}