#include "World.h"
#include "Player.h"
#include "EnemyRabbit.h"
#include "OSHandler.h"

World::World(sf::RenderWindow* pWindow, unsigned int resolutionX, unsigned int resolutionY)
{
	_pWindow = pWindow;
    
	_mainShader.loadFromFile("f_shader.frag", sf::Shader::Fragment);
	_pRenderTexture = new sf::RenderTexture();
	_pRenderTexture->create(resolutionX, resolutionY);
	_pLevel = new Level(this);
	_pPlayer = new Player(this);
	_pPlayer->setPosition(sf::Vector2f(64.0 * 10.0 + 32.0, 64.0 * 10.0 + 31.0));

	//DONT FORGET TO CHANGE LEVELNAME IN initEditorMode!
	_editorMode = false;
	if(_editorMode)
		_pLevel->initEditorMode(20, 15,_textureHandler.getResourcePath() + "Levels/1.lvl");
	else
		_pLevel->load(_textureHandler.getResourcePath() + "Levels/1.lvl");
}


World::~World()
{
}

void World::restart() {
	_pPlayer = new Player(this);
	_pPlayer->setPosition(sf::Vector2f(64.0 * 10.0 + 32.0, 64.0 * 10.0 + 31.0));
	_pLevel->load(_textureHandler.getResourcePath() + "Levels/1.lvl");
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
	_pRenderTexture->clear(sf::Color::White);
    
    for(Entity* e : _pLevel->_entities)
	{
		if(e != nullptr)
			e->Draw();
	}
	for(Enemy* e : _pLevel->_enemies)
	{
		e->Draw();
	}
	_pPlayer->Draw();

	_pRenderTexture->display();
	const sf::Texture& texture = _pRenderTexture->getTexture();
	sf::Sprite sprite(texture);

	sf::Vector2f lightPos = _pPlayer->getPosition();
	_mainShader.setParameter("lightPos", lightPos.x, lightPos.y);

	_pWindow->draw(sprite, &_mainShader);
	_pWindow->display();
}
