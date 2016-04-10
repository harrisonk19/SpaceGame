#ifndef GAMELOOP_H
#define GAMELOOP_H
#include "SDL2/SDL.h"
#include "imageLoader.h"
#include <vector>
#include "GameObject.h"

class GameLoop
{
	public:
		void run(); //runs the game

		int fps;
		
		void CheckBounds(GameObject* object); //bounds checking to prevent player object from going off screen

	private:
		std::vector<GameObject*> gameObjects;

		//input flags
		bool upPressed;
		bool downPressed;
		bool spacePressed;
};



#endif
