#pragma once
#include <SFML/Graphics.hpp>
#include <list>
class World;

enum EntityType {et_moving, et_wall, et_floor, et_plant, et_rabbit};

class Entity
{
public:
    Entity();
	Entity(World* pWorld, EntityType entityType);
	~Entity();
    
	virtual void Update();
	virtual void Draw();
	virtual void setTexture(sf::Texture* texture);
    virtual void setAnimationTexture(sf::Texture* textures, int animationCount);
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
    std::vector<sf::Sprite> _sprites;
	float _size;
    bool animation;
};