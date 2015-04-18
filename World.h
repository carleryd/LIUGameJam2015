#include <SFML/Graphics.hpp>
#include <list>
class Entity;
class Player;

using namespace std;

class World
{
public:
	World(sf::RenderWindow* pWindow);
	~World();
	void Update();
	void Draw();
    string getResourcePath();

	std::list<Entity*> Entitys;
	Player* _pPlayer;
	sf::RenderWindow* _pWindow;
    string _resourcePath;
};