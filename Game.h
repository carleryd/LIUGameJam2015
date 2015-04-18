#include <SFML/Graphics.hpp>
#include "World.h"

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
};