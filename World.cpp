#include "World.h"
#include "EntityEmpty.h"

World::World(sf::RenderWindow* pWindow)
{
	_pWindow = pWindow;
	EntityEmpty* e = new EntityEmpty(this);
	e->setPosition(sf::Vector2f(300.0, 300.0));
	//Vet inte var man ska sätta sökvägen
	e->setTexture("Textures/test.png");
	Entitys.push_back(e);
}


World::~World()
{
}


void World::Update()
{

}


void World::Draw()
{
	_pWindow->clear(sf::Color::White);
	for each (Entity* e in Entitys)
	{
		e->Draw();
	}
    _pWindow->display();
}