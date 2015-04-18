#include <SFML/Graphics.hpp>
#include <list>
class Entity;

class World
{
public:
	World(sf::RenderWindow* pWindow);
	~World();
	void Update();
	void Draw();

	std::list<Entity*> Entitys;
	sf::RenderWindow* _pWindow;
};