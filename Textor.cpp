#include "Textor.h"
#include "OSHandler.h"
#include <iostream>
#include <stack>
using namespace std;

Textor::Textor(string resourcePath)
{
	if (!font.loadFromFile(resourcePath + "Fonts/sansation.ttf")) {
        cerr << "Could not load " << resourcePath + "Fonts/sansation.ttf" << endl;
    }
	text.setFont(font);
	text.setColor(sf::Color(255, 100, 255));
    
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f,
                   textRect.top  + textRect.height/2.0f);
}

Textor::~Textor(void)
{
    cout << "Destructor not implemented" << endl;
}

sf::Text Textor::write(string text_, sf::Vector2f pos, unsigned int size, sf::Color color)
{
	text.setString(text_);
    text.setCharacterSize(size);
    text.setColor(color);
    
    text.setPosition(pos);
	return text;
}

void Textor::writeTemporaryText(string text, sf::Vector2f pos, unsigned int size, sf::Color color, unsigned int lifespan)
{
    tempText tt;
    tt.text = write(text, pos, size, color);
    tt.lifespan = lifespan;
	temporaryTexts.push_back(tt);
//	temporaryTexts.back().text = write(text, pos, size, color);
//	temporaryTexts.back().lifespan = lifespan;
}

void Textor::handleTemporaryTexts(sf::RenderWindow& w)
{
	for (tempText tt: temporaryTexts)
	{
		w.draw(tt.text);
	}
	auto remove = remove_if(temporaryTexts.begin(), temporaryTexts.end(), [](tempText tt)  
		{
			return tt.clock.getElapsedTime().asSeconds() > tt.lifespan;
		});
	if(remove != temporaryTexts.end())
	{
		temporaryTexts.erase(remove);
	}
}