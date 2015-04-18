#include <SFML/Graphics.hpp>
class World;

class Entity
{
public:
	Entity(World* pWorld);
	~Entity();
	virtual void Update();
	virtual void Draw();
	virtual void setTexture(sf::Texture* texture);
	sf::Vector2f getPosition();
	void setPosition(const sf::Vector2f position);
	float getSize();
	void setSize(const float size);

	World* _pWorld;
protected:
	sf::Sprite _sprite;
	float _size;
};