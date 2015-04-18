#include "World.h"
#include "Player.h"
#include "EnemyRabbit.h"
#include "OSHandler.h"

World::World(sf::RenderWindow* pWindow)
{
	_pWindow = pWindow;
    
	_level = new Level(this);
//	Entity* e = new Entity(this, et_wall);
//	e->setTexture(_textureHandler.getTexture(tt_wall));
//	e->setPosition(sf::Vector2f(300.0, 300.0));
//	entities.push_back(e);
//    
//	e = new Entity(this, et_wall);
//	e->setPosition(sf::Vector2f(364.0, 364.0));
//	e->setTexture(_textureHandler.getTexture(tt_wall));
//    entities.push_back(e);

//	e = new Entity(this, et_wall);
//	e->setPosition(sf::Vector2f(600.0, 500.0));
//	e->setTexture(_textureHandler.getTexture(tt_wall));
//    _entities.push_back(e);
//    
//    for(int i = 0; i < 10; i++) {
//        e = new Entity(this, et_wall);
//        e->setPosition(sf::Vector2f(200.0+i*64, 300.0));
//        e->setTexture(_textureHandler.getTexture(tt_wall));
//        _entities.push_back(e);
//    }
//
//    Entity* plant1 = new Entity(this, et_wall);
//    Entity* plant2 = new Entity(this, et_wall);
//    Entity* plant3 = new Entity(this, et_wall);
//  	plant1->setPosition(sf::Vector2f(300.0, 100.0));
//   	plant2->setPosition(sf::Vector2f(400.0, 100.0));
//   	plant3->setPosition(sf::Vector2f(500.0, 100.0));
//	//Vet inte var man ska sätta sökvägen
//    
//    Enemy* rabbit = new EnemyRabbit(this);
//    rabbit->setPosition(sf::Vector2f(500.0, 450.0));

	_pPlayer = new Player(this);
	_pPlayer->setPosition(sf::Vector2f(200.0, 200.0));
	_level->load(_textureHandler.getResourcePath() + "Levels/1.lvl");

//	_entities.push_back(e);
//    _entities.push_back(plant1);
//    _entities.push_back(plant2);
//    _entities.push_back(plant3);
//    _rabbits.push_back(rabbit);
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
