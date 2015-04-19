#include "Game.h"
#include "World.h"

Game::Game()
{
	_resolutionX = 1224;
	_resolutionY = 768;
	_pWindow = new sf::RenderWindow(sf::VideoMode(_resolutionX, _resolutionY), "CAROTTEN BITTE!");
    _pWindow->setFramerateLimit(100);
	_pWorld = new World(_pWindow, _resolutionX, _resolutionY);
	_GameState = Running;
}


Game::~Game()
{
	delete _pWindow;
}

void Game::Run()
{
    while (_pWindow->isOpen())
    {
		switch (_GameState)
		{
		case Menu:
			break;
		case Running:
			_pWorld->Update();
			_pWorld->Draw();
			break;
		case PauseMenu:
			break;
		default:
			break;
		}

		sf::Event event;
		while (_pWindow->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                _pWindow->close();
        }
	}
}