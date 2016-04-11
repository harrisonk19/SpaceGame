#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
 
#include "SDL2/SDL.h"
#include <string>

class GameObject
{
	public:
		GameObject(std::string imageFilename);

		void Move(int newX, int newY); // handles moving objects

		SDL_Surface* getSurface();
		
		int getX();
		int getY();
		
	private:

		SDL_Surface* surf;
		int x;
		int y;
};

#endif
