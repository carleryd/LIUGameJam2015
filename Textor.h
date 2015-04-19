#ifndef TEXTOR_H
#define TEXTOR_H
#include <SFML/Graphics.hpp>
#include <list>
using namespace std;

class OSHandler;

struct tempText
{
	sf::Text text;
	sf::Clock clock;
	int lifespan;
};

class Textor
{
public:
	Textor(string resourcePath);
	~Textor(void);

	sf::Text write(string text, sf::Vector2f position, unsigned int size, sf::Color color);
	void writeTemporaryText(string text, sf::Vector2f position, unsigned int size, sf::Color color, unsigned int lifespan);
	//print text, remove if time has run out.
	void handleTemporaryTexts(sf::RenderTexture& w);
private:
	sf::Font font;
	sf::Text text;
	vector<tempText> temporaryTexts;
};


#endif