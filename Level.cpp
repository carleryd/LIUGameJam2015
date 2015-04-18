#include "Level.h"
#include <fstream>
#include <iostream>
#include "EnemyRabbit.h"
#include "World.h"

using namespace std;


Level::Level(World* pWorld)
{
	_pWorld = pWorld;
	gridSize = 64;
}


Level::~Level()
{
	for(Entity* e : _entities)
		delete e;
}


void Level::load(const std::string filename)
{
	ifstream myfile (filename);
	string line;
	if(myfile.is_open())
	{
		string t;
		while ( myfile >> t)
		{
			Entity* e;
			//Wall
			if(t == "A")
			{
				e = new Entity(_pWorld, et_wall);
				e->setTexture(_pWorld->_textureHandler.getTexture(tt_wall));
			}
			//Plant
			else if(t == "B")
			{
				e = new Entity(_pWorld, et_plant);
				e->setTexture(_pWorld->_textureHandler.getTexture(tt_plant));
			}
			//Rabbit
			else if(t == "C")
			{
				e = new EnemyRabbit(_pWorld);
				e->setTexture(_pWorld->_textureHandler.getTexture(tt_rabbit));
			}
			//Floor
			else if(t == "D")
			{
				e = new Entity(_pWorld, et_floor);
				e->setTexture(_pWorld->_textureHandler.getTexture(tt_floor));
			}

			myfile >> t;
			float x = stof(t);
			myfile >> t;
			float y = stof(t);

			e->setPosition(sf::Vector2f(x, y));
			_entities.push_back(e);
		}
		myfile.close();
	}
}


void Level::save(const std::string filename)
{
	ofstream myfile (filename);
  if (myfile.is_open())
  {
	  for(Entity* e : _entities)
	{
		std::cout <<"saving";
		if(e->_entityType == et_wall)
			myfile <<"A ";
		else if(e->_entityType == et_plant)
			myfile <<"B ";
		else if(e->_entityType == et_rabbit)
			myfile <<"C ";
		else if(e->_entityType == et_floor)
			myfile <<"D ";

		myfile <<e->getPosition().x <<" " <<e->getPosition().y <<" ";
	}
	myfile.close();
  }
}


void editorModeUpdate()
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{

	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{

	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{

	}
}