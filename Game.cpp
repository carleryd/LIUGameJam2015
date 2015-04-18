#include "Game.h"


Game::Game()
{
	_pWindow = new sf::RenderWindow(sf::VideoMode(800, 600), "CAROTTEN BITTE!");
	_pWorld = new World(_pWindow);
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