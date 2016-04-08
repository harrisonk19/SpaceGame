#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
 
#include "SDL2/SDL.h"
#include <string>

class GameObject
{
	public:
		GameObject(std::string imageFilename);

		void Move(int newX, int newY);

		SDL_Surface* getSurface();
		
	private:

		SDL_Surface* surf;
		int x,y;
};

#endif
