#include "World.h"
#include "Player.h"
#include "EnemyRabbit.h"
#include "OSHandler.h"
#include "Textor.h"
#include "TextureHandler.h"
//#include <SFML/audio.hpp>

World::World(sf::RenderWindow* pWindow, unsigned int resolutionX, unsigned int resolutionY)
{
	_resolutionX = resolutionX;
	_resolutionY = resolutionY;
	_pWindow = pWindow;
	_mainShader.loadFromFile("f_shader.frag", sf::Shader::Fragment);
	_pRenderTexture = new sf::RenderTexture();
	_pRenderTexture->create(resolutionX, resolutionY);
    _pTextureHandler = new TextureHandler();
    _pTextor = new Textor(_pTextureHandler->getResourcePath());
	_pLevel = new Level(this);
	_pPlayer = new Player(this);
	_pPlayer->setPosition(sf::Vector2f(64.0 * 10.0 + 32.0, 64.0 * 10.0 + 31.0));
    _restart = false;

	//DONT FORGET TO CHANGE LEVELNAME IN initEditorMode!
	_editorMode = false;
	if(_editorMode)
		_pLevel->initEditorMode(20, 15,_pTextureHandler->getResourcePath() + "Levels/1.lvl");
	else
		_pLevel->load(_pTextureHandler->getResourcePath() + "Levels/1.lvl");
		/*_buffer = new sf::SoundBuffer();
		_sound = new sf::Sound();
		_buffer.loadFromFile(getResourcePath() + "apple_bite.wav");
         _sound.setBuffer(_buffer);*/
    _clock.restart();
}


World::~World()
{
}

void World::restart() {
    _gameDuration = 0;
    _pTextor->writeTemporaryText("You have to be more careful!",
                                 _pPlayer->getPosition() + sf::Vector2f(0, -200), 70, sf::Color::White, 1);
	
    while(_gameDuration < 1000) {
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
	//_sound.play();
    _clock.restart();
    _restart = true;
}


void World::Update()
{
    _elapsed = _clock.getElapsedTime();
	_pPlayer->Update();

    for(Entity* e :_pLevel->_entities)
    {
        if(e != nullptr)
            e->Update();
    }
    for(Enemy* e : _pLevel->_enemies)
    {
        if(!_editorMode)
            e->Update();
    }

    if(_editorMode)
        _pLevel->editorModeUpdate();
}

void World::Draw()
{
	_pWindow->clear(sf::Color::White);
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

	_pTextor->handleTemporaryTexts(*_pRenderTexture);


	_pRenderTexture->display();
	const sf::Texture& texture = _pRenderTexture->getTexture();
	sf::Sprite sprite(texture);

	//sf::Vector2f lightPos = _pPlayer->getPosition();
	//_mainShader.setParameter("lightPos", lightPos.x, lightPos.y);

	//_mainShader.setParameter

	_pWindow->draw(sprite, &_mainShader);
	_pWindow->display();
}

