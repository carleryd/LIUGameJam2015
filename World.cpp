#include "World.h"
#include "Player.h"

World::World(sf::RenderWindow* pWindow)
{
	_pWindow = pWindow;
	Entity* e = new Entity(this, et_wall);
	e->setPosition(sf::Vector2f(300.0, 300.0));
	e->setTexture(_textureHandler.getTexture(tt_wall));
	Entitys.push_back(e);
	e = new Entity(this, et_wall);
	e->setPosition(sf::Vector2f(364.0, 364.0));
	e->setTexture(_textureHandler.getTexture(tt_wall));
	Entitys.push_back(e);

	_pPlayer = new Player(this);
	_pPlayer->setPosition(sf::Vector2f(200.0, 200.0));
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
    for(Entity* e : Entitys)
	{
		e->Draw();
	}
	_pPlayer->Draw();
    _pWindow->display();
}
