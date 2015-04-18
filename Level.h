#pragma once
#include <vector>
#include "Entity.h"

class Level
{
public:
	void load(const std::string filename);
	void save(const std::string filename);

	std::vector<Entity*> entities;
};