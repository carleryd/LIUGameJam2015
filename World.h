#include <SFML/Graphics.hpp>
#include "TextureHandler.h"
#include <vector>
class Entity;
class Player;

class World
{
public:
	World(sf::RenderWindow* pWindow);
	~World();
	void Update();
	void Draw();
	
	TextureHandler _textureHandler;
	std::vector<Entity*> Entitys;
	Player* _pPlayer;
	sf::RenderWindow* _pWindow;
};