#include "GameObject.h"

GameObject::GameObject(std::string imageFilename)
{
	surf = SDL_LoadBMP(imageFilename.c_str());
}

SDL_Surface* GameObject::getSurface()
{
	return surf;
}
