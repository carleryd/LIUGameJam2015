#include "World.h"
#include "Player.h"
#include "EnemyRabbit.h"
#include "OSHandler.h"

World::World(sf::RenderWindow* pWindow)
{
	_pWindow = pWindow;
    
	_level = new Level(this);
	_pPlayer = new Player(this);
	_pPlayer->setPosition(sf::Vector2f(200.0, 200.0));
	_level->load("Levels/1.lvl");

}


World::~World()
{
}


void World::Update()
{
	_pPlayer->Update();
	for(Entity* e :_level->_entities) {
        e->Update();
    }
}

void World::Draw()
{
	_pWindow->clear(sf::Color::White);
    for(Entity* e : _level->_entities) {
		e->Draw();
	}

	_pPlayer->Draw();
    _pWindow->display();
}
