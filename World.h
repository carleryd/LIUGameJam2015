#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Level.h"
#include <list>

class Player;
class Entity;
class Enemy;
class Textor;
class TextureHandler;
using namespace sf;
class SoundBuffer;
class Sound;

class World
{
public:
	World(sf::RenderWindow* pWindow, unsigned int resolutionX, unsigned int resolutionY);
	~World();
	void Update();
	void Draw();
    Player* getPlayer();
	void restart();
	
	TextureHandler* _pTextureHandler;
	Level* _pLevel;
	std::list<Entity*> _entities;
	Player* _pPlayer;
	sf::RenderTexture* _pRenderTexture;
	sf::RenderWindow* _pWindow;
	sf::Shader _mainShader;
    Textor* _pTextor;
    int _gameDuration;
	bool _editorMode;

	unsigned int _resolutionX;
	unsigned int _resolutionY;
private:
	SoundBuffer* _buffer;
	Sound* _sound;
};
