#include <SFML/Graphics.hpp>
class World;

enum EntityType {et_moving, et_wall, et_floor};

class Entity
{
public:
	Entity(World* pWorld, EntityType entityType);
	~Entity();
	virtual void Update();
	virtual void Draw();
	virtual void setTexture(sf::Texture* texture);
	sf::Vector2f getPosition();
	void setPosition(const sf::Vector2f position);
	float getSize();
	void setSize(const float size);
	sf::Vector2f getOrigin();
	void setOrigin(sf::Vector2f origin);

	EntityType _entityType;
	World* _pWorld;
protected:
	sf::Sprite _sprite;
	float _size;
};