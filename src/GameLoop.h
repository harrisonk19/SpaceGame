#ifndef GAMELOOP_H
#define GAMELOOP_H
#include "SDL2/SDL.h"
#include "imageLoader.h"
#include <vector>
#include "GameObject.h"

class GameLoop
{
	public:
		void run();

		int fps;

	private:
		std::vector<GameObject*> gameObjects;
};



#endif
