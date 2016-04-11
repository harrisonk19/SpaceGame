#include "GameObject.h"

GameObject::GameObject(std::string imageFilename)
{
	surf = SDL_LoadBMP(imageFilename.c_str());
}

SDL_Surface* GameObject::getSurface()
{
	return surf;
}

void GameObject::Move(int newX, int newY)// this acts as a setter for both x and y
{
	x = newX;
	y = newY;
}

int GameObject::getX()
{
	return x;
}

int GameObject::getY()
{
	return y;
}
