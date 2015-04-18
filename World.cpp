#include "World.h"
#include "Player.h"
#include "EnemyRabbit.h"
#include "OSHandler.h"

World::World(sf::RenderWindow* pWindow)
{
	_pWindow = pWindow;
    
	/*Entity* e = new Entity(this, et_wall);
	e->setTexture(_textureHandler.getTexture(tt_wall));
	e->setPosition(sf::Vector2f(300.0, 300.0));
	entities.push_back(e);
    
	e = new Entity(this, et_wall);
	e->setPosition(sf::Vector2f(364.0, 364.0));
	e->setTexture(_textureHandler.getTexture(tt_wall));
    entities.push_back(e);

	e = new Entity(this, et_wall);
	e->setPosition(sf::Vector2f(600.0, 500.0));
	e->setTexture(_textureHandler.getTexture(tt_wall));
    entities.push_back(e);

    Entity* plant1 = new Entity(this, et_wall);
    Entity* plant2 = new Entity(this, et_wall);
    Entity* plant3 = new Entity(this, et_wall);
  	plant1->setPosition(sf::Vector2f(300.0, 100.0));
   	plant2->setPosition(sf::Vector2f(400.0, 100.0));
   	plant3->setPosition(sf::Vector2f(500.0, 100.0));
	//Vet inte var man ska sätta sökvägen
    
    Enemy* rabbit = new EnemyRabbit(this);
    rabbit->setPosition(sf::Vector2f(500.0, 450.0));

	_pPlayer = new Player(this);
	_pPlayer->setPosition(sf::Vector2f(200.0, 200.0));
    
    rabbit->setTexture(_textureHandler.getTexture(tt_rabbit));
    plant1->setTexture(_textureHandler.getTexture(tt_plant));
    plant2->setTexture(_textureHandler.getTexture(tt_plant));
    plant3->setTexture(_textureHandler.getTexture(tt_plant));

	entities.push_back(e);
    entities.push_back(plant1);
    entities.push_back(plant2);
    entities.push_back(plant3);
	entities.push_back(rabbit);
	*/
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
    /*for(Enemy* rabbit : rabbits) {
        rabbit->Draw();
        rabbit->Update();
    }*/
	_pPlayer->Draw();
    _pWindow->display();
}
