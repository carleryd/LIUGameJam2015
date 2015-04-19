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
	World(sf::RenderWindow* pWindow);
	~World();
	void Update();
	void Draw();
    Player* getPlayer();
	void restart();
	
	TextureHandler* _pTextureHandler;
	Level* _pLevel;
	std::list<Entity*> _entities;
//    std::list<Entity*> _rabbits;
	Player* _pPlayer;
	sf::RenderWindow* _pWindow;
    Textor* _pTextor;
    int _gameDuration;
	bool _editorMode;
private:
	SoundBuffer* _buffer;
	Sound* _sound;
};
