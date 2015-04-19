#include <SFML/Graphics.hpp>

class Utility
{
public:
	static float Length(const sf::Vector2f& v);
	static void Normalize(sf::Vector2f& v);
	static void vMul(sf::Vector2f& v, const float f);
	static float DtoR(const float& Degree);
	static float RtoD(const float& Radian);
    static float angle(const sf::Vector2f A, sf::Vector2f B);
    static float angleComplete(const sf::Vector2f A, sf::Vector2f B);
	static sf::Vector2f mul(sf::Vector2f& a, sf::Vector2f&b);
	//Square to Square colission
	static bool SSCollision(sf::Vector2f Aposition, sf::Vector2f Aorigin, float Awidth, sf::Vector2f Bposition, sf::Vector2f Borigin, float Bwidth);
	static float magnitude(sf::Vector2f a);

private:
	Utility();
	~Utility();
};
