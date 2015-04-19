#pragma once
#include <vector>
#include <string>
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
	void initEditorMode(int xSize, int ySize, const std::string levelName);
	void editorModeUpdate();

	std::vector<Entity*> _entities;
	std::vector<Enemy*> _enemies;
	World* _pWorld; 
	int gridSize;
	int _xSize;
	int _ySize;
	std::string _levelName;
};