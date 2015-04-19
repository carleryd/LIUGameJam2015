#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHandler.h"
#include <vector>
#include <iostream>
#include "Level.h"

class Player;
class Entity;
class Enemy;

class World
{
public:
	World(sf::RenderWindow* pWindow, unsigned int resolutionX, unsigned int resolutionY);
	~World();
	void Update();
	void Draw();
    Player* getPlayer();
	void restart();
	
	TextureHandler _textureHandler;
	Level* _pLevel;
	std::list<Entity*> _entities;
    std::list<Entity*> _rabbits;
	Player* _pPlayer;
	sf::RenderTexture* _pRenderTexture;
	sf::RenderWindow* _pWindow;
	sf::Shader _mainShader;
	bool _editorMode;
private:
	
};
