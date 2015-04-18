#include <SFML/Graphics.hpp>
#include <list>
class Entity;
class Player;

class World
{
public:
	World(sf::RenderWindow* pWindow);
	~World();
	void Update();
	void Draw();

	std::list<Entity*> Entitys;
	Player* _pPlayer;
	sf::RenderWindow* _pWindow;
};