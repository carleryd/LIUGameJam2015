#include "World.h"
#include "Player.h"

World::World(sf::RenderWindow* pWindow)
{
	_pWindow = pWindow;
	Entity* e = new Entity(this);
	e->setPosition(sf::Vector2f(300.0, 300.0));
	//Vet inte var man ska sätta sökvägen
	e->setTexture("Textures/test.png");

	_pPlayer = new Player(this);
	_pPlayer->setPosition(sf::Vector2f(200.0, 200.0));
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
	for each (Entity* e in Entitys)
	{
		e->Draw();
	}
	_pPlayer->Draw();
    _pWindow->display();
}