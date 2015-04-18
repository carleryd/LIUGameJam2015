#pragma once
#include <vector>
class World;
class Entity;
class Enemy;

class Level
{
public:
	Level(World* pWorld);
	~Level();
	void load(const std::string filename);
	void save(const std::string filename);

	std::vector<Entity*> _entities;
	std::vector<Enemy*> _enemies;
	World* _pWorld; 
	float gridSize;
};