#include "World.h"
#include "Player.h"
#include "Entity.h"
#include "OSHandler.h"

World::World(sf::RenderWindow* pWindow)
{
    OSHandler* osHandler = new OSHandler();
    #ifdef _WIN32
        osHandler->win32();
    #elif __APPLE__
        osHandler->mac();
    #else
        std::cout << "Not WIN32 or APPLE" << std::endl;
    #endif
    _resourcePath = osHandler->getResourcePath();
    cout << "resourcePath: " <<  _resourcePath << endl;
    
	_pWindow = pWindow;
	Entity* e = new Entity(this);
	e->setPosition(sf::Vector2f(300.0, 300.0));
	//Vet inte var man ska sätta sökvägen

	_pPlayer = new Player(this);
	_pPlayer->setPosition(sf::Vector2f(200.0, 200.0));

	e->setTexture(_resourcePath + "Textures/test.png");

	Entitys.push_back(e);
}


World::~World()
{
}

string World::getResourcePath() { return _resourcePath; }

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