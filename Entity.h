#include <SFML/Graphics.hpp>
class World;

class Entity
{
public:
	Entity(World* pWorld);
	~Entity();
	virtual void Update();
	virtual void Draw();
	virtual void setSpritePos(sf::Vector2f Position);
	virtual void setTexture(const std::string& filename, const sf::IntRect&	area=sf::IntRect());
	void setPos(const sf::Vector2f pos);
    void setSize(const sf::Vector2f size);
    
    sf::Vector2f getPos();
    sf::Vector2f getSize();

	World* _pWorld;
protected:
	sf::Texture _texture;
	sf::Sprite _sprite;
    sf::Vector2f _pos, _size;
};