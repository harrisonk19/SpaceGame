#include "GameLoop.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

void GameLoop::run()
{
	//Setup game resources (images, sounds, etc.)
	SDL_Window* window = 0; //create a window

	SDL_Surface* screenSurface = 0; //create a surface to apply images

	SDL_Init(SDL_INIT_EVERYTHING); //initialize SDL

	window = SDL_CreateWindow( "Space Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
	
	screenSurface = SDL_GetWindowSurface(window);
	
	//load image stuff
	GameObject* ship = new GameObject("images/ship.bmp");
	gameObjects.push_back(ship);

	bool quit = false;

	while(!quit)
	{
		SDL_Event e;
		//Get and handle SDL events (input, errors, etc)
		while( SDL_PollEvent( &e ) != 0 ) 
		{ 
			if( e.type == SDL_QUIT ) //to close the window
			{ 
				quit = true; 
			} 
			else if( e.type == SDL_KEYDOWN)
			{
				switch( e.key.keysym.sym ) //up arrow key event
				{
					case SDLK_UP:
					break;
				}
			}
		}

		//Draw stuff
		for(int i = 0; i < gameObjects.size(); i++)
		{
			SDL_BlitSurface(gameObjects.at(i)->getSurface(), 0, screenSurface, 0);
		}

		SDL_UpdateWindowSurface(window);

		SDL_Delay(1000.0 / (float)fps);
	}
}
