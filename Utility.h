#include <SFML/Graphics.hpp>

class Utility
{
public:
	static float Length(const sf::Vector2f& v);
	static void Normalize(sf::Vector2f& v);
	static void vMul(sf::Vector2f& v, const float f);
	static float DtoR(const float& Degree);
	static float RtoD(const float& Radian);
	static sf::Vector2f mul(sf::Vector2f& a, sf::Vector2f&b);

private:
	Utility();
	~Utility();
};
