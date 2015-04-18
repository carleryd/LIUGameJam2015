#include <SFML/Graphics.hpp>

class Utility
{
public:
	static float Length(const sf::Vector2f& v);
	static void Normalize(sf::Vector2f& v);

private:
	Utility();
	~Utility();
};