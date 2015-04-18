#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHandler.h"
#include <list>
#include <iostream>
class Player;
class Entity;
class Enemy;

class World
{
public:
	World(sf::RenderWindow* pWindow);
	~World();
	void Update();
	void Draw();
	
	TextureHandler _textureHandler;

	std::list<Entity*> entities;
    std::list<Enemy*> rabbits;
	Player* _pPlayer;
	sf::RenderWindow* _pWindow;
};