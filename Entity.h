#include <SFML/Graphics.hpp>
class World;

class Entity
{
public:
	Entity(World* pWorld);
	~Entity();
	virtual void Update();
	virtual void Draw();
	virtual void setPosition(sf::Vector2f Position);
	virtual void setTexture(const std::string& filename, const sf::IntRect&	area=sf::IntRect());

	World* _pWorld;
private:
	sf::Texture _Texture;
	sf::Sprite _Sprite;
};