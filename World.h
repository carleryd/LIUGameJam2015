#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio.hpp>
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
    sf::Vector2f _spawn;
    
    
    sf::Clock _clock;
    sf::Time _elapsed;
    
    int _gameDuration;
	bool _editorMode;
    bool _restart;

	unsigned int _resolutionX;
	unsigned int _resolutionY;
private:
    sf::SoundBuffer _buffer;
    sf::Sound _sound;
};
