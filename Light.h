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
	sf::VertexArray& getVertexArray();

private:

	sf::Vector2f _left;
	sf::Vector2f _right;
	Player* _pPlayer;
	sf::VertexArray _lightCone;
	sf::ConvexShape _leftShade;
	sf::ConvexShape _rightShade;
	sf::ConvexShape _topShade;
	World* _pWorld;
	//Entity _lightDetector;
public:
};

#endif
