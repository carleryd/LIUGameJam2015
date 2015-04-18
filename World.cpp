#include "World.h"
#include "Player.h"

World::World(sf::RenderWindow* pWindow)
{

    
	_pWindow = pWindow;
	Entity* e = new Entity(this);
	e->setPosition(sf::Vector2f(300.0, 300.0));
	//Vet inte var man ska sätta sökvägen

	_pPlayer = new Player(this);
	_pPlayer->setPosition(sf::Vector2f(200.0, 200.0));

	e->setTexture(_textureHandler.getTexture(tt_test));

	Entitys.push_back(e);
}


World::~World()
{
}


void World::Update()
{
	_pPlayer->Update();
}

void World::Draw()
{
	_pWindow->clear(sf::Color::White);
//	for each (Entity* e in Entitys)
    for(Entity* e : Entitys)
	{
		e->Draw();
	}
	_pPlayer->Draw();
    _pWindow->display();
}