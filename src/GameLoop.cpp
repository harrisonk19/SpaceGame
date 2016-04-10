#include "GameLoop.h"
#include <iostream>

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
	GameObject* ship = new GameObject("images/ship.bmp"); //NOTE: fix this image
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
				switch( e.key.keysym.sym ) //Keyboard events
				{
					case SDLK_UP: //up
						std::cout << "Up Pressed" << std::endl;
						upPressed = true;
					break;

					case SDLK_DOWN: //down
						std::cout << "Down Pressed" << std::endl;
						downPressed = true;
					break;

					case SDLK_SPACE: //spacebar
						std::cout << "Space Pressed" << std::endl;
						spacePressed = false;
					break;
				}
			}
			else if( e.type == SDL_KEYUP)
			{
				switch( e.key.keysym.sym ) //Keyboard events
				{
					case SDLK_UP: //up
						std::cout << "Up Released" << std::endl;
						upPressed = false;
					break;

					case SDLK_DOWN: //down
						std::cout << "Down Released" << std::endl;
						downPressed = false;
					break;

					case SDLK_SPACE: //spacebar
						std::cout << "Space Released" << std::endl;
						spacePressed = false;
					break;
				}
			}
		}

		if(upPressed)
		{
			ship->Move(ship->getX(), ship->getY() - 2); //2 is the optimal movement speed
		}
		
		if(downPressed)
		{
			ship->Move(ship->getX(), ship->getY() + 2);
		}

		//Draw stuff
		for(int i = 0; i < gameObjects.size(); i++)
		{
			GameObject* currentObj = gameObjects.at(i); //moving stuff

			SDL_Rect currentRect;
			currentRect.x = currentObj->getX();
			currentRect.y = currentObj->getY();
			currentRect.w = currentObj->getSurface()->w;
			currentRect.h = currentObj->getSurface()->h;
			SDL_BlitSurface(currentObj->getSurface(), 0, screenSurface, &currentRect);
		}

		SDL_UpdateWindowSurface(window);
		
		CheckBounds(ship);

		SDL_Delay(1000.0 / (float)fps);
	}

}

void GameLoop::CheckBounds(GameObject* object)
{

	if(object->getY() >= SCREEN_HEIGHT - object->getSurface()->h) //bottom of screen
	{
		object->Move(object->getX(), SCREEN_HEIGHT - object->getSurface()->h);
	}

	else if(object->getY() <= 0) // top of screen
	{
		object->Move(object->getX(), 0);
	}
}
