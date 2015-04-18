#include <SFML/Graphics.hpp>
#include "Entity.h"
class World;

class EntityEmpty : public Entity
{
public:
	EntityEmpty(World* pWorld);
	~EntityEmpty();
	virtual void Update();
	virtual void Draw();
	virtual void setPosition(sf::Vector2f Position);
	virtual void setTexture(const std::string& filename, const sf::IntRect&	area=sf::IntRect());

private:
	sf::Texture _Texture;
	sf::Sprite _Sprite;
};