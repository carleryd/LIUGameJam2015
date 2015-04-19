#include "TextureHandler.h"
#include "OSHandler.h"
#include <iostream>

TextureHandler::TextureHandler()
{
    OSHandler* osHandler = new OSHandler();
    #ifdef _WIN32
        osHandler->win32();
    #elif __APPLE__
        osHandler->mac();
    #else
        std::cout << "Not WIN32 or APPLE" << std::endl;
    #endif
    _resourcePath = osHandler->getResourcePath();


	sf::Texture* t;

	//Add all textures here
	t = new sf::Texture();
	t->loadFromFile(_resourcePath + "Textures/test.png");
	_textures.push_back(std::make_pair(tt_test, t));
    
	t = new sf::Texture();
	t->loadFromFile(_resourcePath + "Textures/placeholder_wall.png");
	_textures.push_back(std::make_pair(tt_wall, t));

    t = new sf::Texture();
	t->loadFromFile(_resourcePath + "Textures/carrot_animation_4.png");
	_textures.push_back(std::make_pair(tt_player_animation_4, t));
    
    t = new sf::Texture();
	t->loadFromFile(_resourcePath + "Textures/placeholder_rabbit.png");
	_textures.push_back(std::make_pair(tt_rabbit, t));
    
    t = new sf::Texture();
	t->loadFromFile(_resourcePath + "Textures/placeholder_plant.png");
	_textures.push_back(std::make_pair(tt_plant, t));

	t = new sf::Texture();
	t->loadFromFile(_resourcePath + "Textures/placeholder_floor.png");
	_textures.push_back(std::make_pair(tt_floor, t));

	t = new sf::Texture();
	t->loadFromFile(_resourcePath + "Textures/placeholder_grass.png");
	_textures.push_back(std::make_pair(tt_grass, t));
}

std::string TextureHandler::getResourcePath() {
    return _resourcePath;
}

TextureHandler::~TextureHandler()
{
	for(std::pair<TextureType, sf::Texture*> p : _textures)
	{
		delete p.second;
	}
}


sf::Texture* TextureHandler::getTexture(TextureType type)
{
	for(std::pair<TextureType, sf::Texture*> p : _textures)
	{
		if(p.first == type)
			return p.second;
	}

	std::cout <<"ERROR! Texture does not exist in TextureHandler";
}