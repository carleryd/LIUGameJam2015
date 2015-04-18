#include <SFML/Graphics.hpp>
#include <list>
#include <utility>

enum TextureType {tt_test, tt_player_animation_4, tt_rabbit, tt_plant, tt_wall};

class TextureHandler
{
public:
	TextureHandler();
	~TextureHandler();
	sf::Texture* getTexture(TextureType type);

private:
	std::list<std::pair<TextureType, sf::Texture*> > _textures;
	std::string _resourcePath;
};