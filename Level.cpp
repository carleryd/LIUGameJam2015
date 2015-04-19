#include "Level.h"
#include <fstream>
#include "EnemyRabbit.h"
#include "EnemyGrater.h"
#include "World.h"
#include "TextureHandler.h"

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
				e->setTexture(_pWorld->_pTextureHandler->getTexture(tt_wall));
				myfile >> t;
				float x = stof(t);
				myfile >> t;
				float y = stof(t);
				e->setPosition(sf::Vector2f(x, y));

				_entities.push_back(e);
			}
			//Plant
			else if(t == "B")
			{
				e = new Entity(_pWorld, et_plant);
				e->setTexture(_pWorld->_pTextureHandler->getTexture(tt_plant));
				myfile >> t;
				float x = stof(t);
				myfile >> t;
				float y = stof(t);
				e->setPosition(sf::Vector2f(x, y));
				_entities.push_back(e);
			}
			//Rabbit
			else if(t == "C")
			{
				Enemy* er = new EnemyRabbit(_pWorld);
				er->setTexture(_pWorld->_pTextureHandler->getTexture(tt_rabbit));
				myfile >> t;
				float x = stof(t);
				myfile >> t;
				float y = stof(t);
				er->setPosition(sf::Vector2f(x, y));
				_enemies.push_back(er);
			}
			//Floor
			else if(t == "D")
			{
				e = new Entity(_pWorld, et_floor);
				e->setTexture(_pWorld->_pTextureHandler->getTexture(tt_floor));
				myfile >> t;
				float x = stof(t);
				myfile >> t;
				float y = stof(t);
				e->setPosition(sf::Vector2f(x, y));
				_entities.push_back(e);
			}
            
			//Grass
			else if(t == "E")
			{
				e = new Entity(_pWorld, et_grass);
				e->setTexture(_pWorld->_pTextureHandler->getTexture(tt_grass));
				myfile >> t;
				float x = stof(t);
				myfile >> t;
				float y = stof(t);
				e->setPosition(sf::Vector2f(x, y));
				_entities.push_back(e);
            }
            //Grater
			else if(t == "F")
			{
				e = new EnemyGrater(_pWorld);
				e->setTexture(_pWorld->_pTextureHandler->getTexture(tt_grater));
				myfile >> t;
				float x = stof(t);
				myfile >> t;
				float y = stof(t);
				e->setPosition(sf::Vector2f(x, y));
				_entities.push_back(e);
			}
		}
		myfile.close();
	}
}


void Level::save(const std::string filename)
{
//	std::cout <<"level saved as " <<_levelName <<"! \n";
	ofstream myfile (filename);
  if (myfile.is_open())
  {
	  for(Entity* e : _entities)
	{
		if(e != nullptr)
		{
			if(e->_entityType == et_wall)
				myfile <<"A ";
			else if(e->_entityType == et_plant)
				myfile <<"B ";
			else if(e->_entityType == et_rabbit)
				myfile <<"C ";
			else if(e->_entityType == et_floor)
				myfile <<"D ";
			else if(e->_entityType == et_grass)
				myfile <<"E ";
			else if(e->_entityType == et_grater)
				myfile <<"F ";

			myfile <<e->getPosition().x <<" " <<e->getPosition().y <<" ";
		}
	}
	myfile.close();
  }
}


void Level::initEditorMode(int xSize, int ySize, const std::string levelName)
{
	_levelName = levelName;
	_xSize = xSize;
	_ySize = ySize;
	for(int y = 0; y < ySize; y++)
	{
		for(int x = 0; x < xSize; x++)
		{
			_entities.push_back(nullptr);
		}
	}
}


void Level::editorModeUpdate()
{
	sf::Vector2i localPosition = sf::Mouse::getPosition(*_pWorld->_pWindow);
	//std::cout <<localPosition.x <<", " <<localPosition.y <<"\n";
	int xIndex = localPosition.x / gridSize;
	int yIndex = localPosition.y / gridSize;
	Entity* e;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		e = new Entity(_pWorld, et_wall);
		e->setTexture(_pWorld->_pTextureHandler->getTexture(tt_wall));
		e->setPosition(sf::Vector2f(xIndex * gridSize + 32.0, yIndex * gridSize + 32.0));
		_entities[xIndex + yIndex * _xSize] = e;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		e = new Entity(_pWorld, et_plant);
		e->setTexture(_pWorld->_pTextureHandler->getTexture(tt_plant));
		e->setPosition(sf::Vector2f(xIndex * gridSize + 32.0, yIndex * gridSize + 32.0));
		_entities[xIndex + yIndex * _xSize] = e;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		e = new Entity(_pWorld, et_floor);
		e->setTexture(_pWorld->_pTextureHandler->getTexture(tt_floor));
		e->setPosition(sf::Vector2f(xIndex * gridSize + 32.0, yIndex * gridSize + 32.0));
		_entities[xIndex + yIndex * _xSize] = e;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		e = new Entity(_pWorld, et_grass);
		e->setTexture(_pWorld->_pTextureHandler->getTexture(tt_grass));
		e->setPosition(sf::Vector2f(xIndex * gridSize + 32.0, yIndex * gridSize + 32.0));
		_entities[xIndex + yIndex * _xSize] = e;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::T))
	{
		e = new EnemyGrater(_pWorld);
		e->setTexture(_pWorld->_pTextureHandler->getTexture(tt_grater));
		e->setPosition(sf::Vector2f(xIndex * gridSize + 32.0, yIndex * gridSize + 32.0));
		_entities[xIndex + yIndex * _xSize] = e;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
	{
		_entities[xIndex + yIndex * _xSize] = nullptr;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	{
		save(_levelName);
	}
}