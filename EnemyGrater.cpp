#include "EnemyGrater.h"
#include "World.h"

EnemyGrater::EnemyGrater(World* pWorld) : Enemy(pWorld, et_grater) {
}

void EnemyGrater::Update() {
    _pWorld->_gameDuration++;
    if(_pWorld->_gameDuration > 40000000) _pWorld->_gameDuration = 0;
}

void EnemyGrater::Draw() {
    int steps = _pWorld->_gameDuration % 16;//
    _sprite.setTextureRect(sf::IntRect((steps-1)/4*64, 0, 64, 64));
    _pWorld->_pRenderTexture->draw(_sprite);
}