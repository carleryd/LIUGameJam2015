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
	t->loadFromFile(_resourcePath + "Textures/player.png");
	_textures.push_back(std::make_pair(tt_player, t));
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