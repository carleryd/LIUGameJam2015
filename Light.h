#ifndef LIGHT_H
#define LIGHT_H
#include <SFML/Graphics.hpp>
class Player;
class World;

class Light 
{
public:
	Light(World* pWorld, Player* p);
	~Light(){};
	void draw();
	void update(sf::Vector2f v, float rotation);
private:
	sf::Vector2f _left;
	sf::Vector2f _right;
	Player* _pPlayer;
	sf::VertexArray _lightCone;
	World* _pWorld;
};

#endif
