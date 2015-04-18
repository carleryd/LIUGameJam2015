#include <SFML/Graphics.hpp>
class World;

class Entity
{
public:
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void setPosition(sf::Vector2f Position) = 0;

	World* _pWorld;
protected:
	Entity(World* pWorld);
	~Entity();
};