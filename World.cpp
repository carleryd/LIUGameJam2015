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
	_level->load(_textureHandler.getResourcePath() + "Levels/1.lvl");

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
	for(Enemy* e : _level->_enemies)
	{
		e->Update();
	}
}

void World::Draw()
{
	_pWindow->clear(sf::Color::White);
    
    for(Entity* e : _level->_entities) {
		e->Draw();
	}
	for(Enemy* e : _level->_enemies)
	{
		e->Draw();
	}
	_pPlayer->Draw();
    _pWindow->display();
}
