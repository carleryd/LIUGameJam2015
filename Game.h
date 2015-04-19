#include <SFML/Graphics.hpp>
class World;

enum GameState {Menu, Running, PauseMenu};

class Game
{
public:
	Game();
	~Game();
	void Run();

private:
	sf::RenderWindow* _pWindow;
	World* _pWorld;
	GameState _GameState;
	unsigned int _resolutionX;
	unsigned int _resolutionY;
};