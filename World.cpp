#include "World.h"
#include "Player.h"
#include "EnemyRabbit.h"
#include "OSHandler.h"
#include "Textor.h"
#include "TextureHandler.h"

World::World(sf::RenderWindow* pWindow)
{
	_pWindow = pWindow;
    
    _pTextureHandler = new TextureHandler();
    _pTextor = new Textor(_pTextureHandler->getResourcePath());
	_pLevel = new Level(this);
	_pPlayer = new Player(this);
	_pPlayer->setPosition(sf::Vector2f(64.0 * 10.0 + 32.0, 64.0 * 10.0 + 31.0));

	//DONT FORGET TO CHANGE LEVELNAME IN initEditorMode!
	_editorMode = false;
	if(_editorMode)
		_pLevel->initEditorMode(20, 15,_pTextureHandler->getResourcePath() + "Levels/1.lvl");
	else
		_pLevel->load(_pTextureHandler->getResourcePath() + "Levels/1.lvl");
}


World::~World()
{
}

void World::restart() {
    _gameDuration = 0;
    _pTextor->writeTemporaryText("You have to be more careful!",
                                 sf::Vector2f(200, 200), 70, sf::Color::Black, 1);
    while(_gameDuration < 100) {
        _gameDuration++;
    }
    
//    for(Entity* rabbit : _rabbits) {
//        delete rabbit;
//    }
    while(_pLevel->_enemies.size() != 0) {
        delete _pLevel->_enemies.back();
        _pLevel->_enemies.pop_back();
    }
    
	_pPlayer = new Player(this);
	_pPlayer->setPosition(sf::Vector2f(64.0 * 10.0 + 32.0, 64.0 * 10.0 + 31.0));
	_pLevel->load(_pTextureHandler->getResourcePath() + "Levels/1.lvl");
}


void World::Update()
{
	_pPlayer->Update();

	for(Entity* e :_pLevel->_entities) 
	{
		if(e != nullptr)
			e->Update();
    }
	for(Enemy* e : _pLevel->_enemies)
	{
		e->Update();
	}

	if(_editorMode)
		_pLevel->editorModeUpdate();


}

void World::Draw()
{
	_pWindow->clear(sf::Color::White);
    
    for(Entity* e : _pLevel->_entities)
	{
		if(e != nullptr)
			e->Draw();
	}
    cout << "Amount of enemies: " << _pLevel->_enemies.size() << endl;
	for(Enemy* e : _pLevel->_enemies)
	{
		e->Draw();
	}
	_pPlayer->Draw();
    _pTextor->handleTemporaryTexts(*_pWindow);
	_pWindow->display();
}

