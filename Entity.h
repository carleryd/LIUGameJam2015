#include <SFML/Graphics.hpp>
class World;

class Entity
{
public:
	Entity(World* pWorld);
	~Entity();
	virtual void Update();
	virtual void Draw();
	virtual void setTexture(const std::string& filename, const sf::IntRect&	area=sf::IntRect());
	sf::Vector2f getPosition();
	void setPosition(const sf::Vector2f position);
	float getSize();
	void setSize(const float size);

	World* _pWorld;
protected:
	sf::Texture _texture;
	sf::Sprite _sprite;
	float _size;
};