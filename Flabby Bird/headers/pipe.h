#pragma once
#include<SDL.h>
#include"Application.h"
class pipe
{
public:
	pipe(SDL_Renderer *renderer,SDL_Texture *texture,float y,bool isup);
	void tick();
	void draw();
public:
	float y;
	float x;
	bool isup;
private:
	SDL_Renderer *renderer;
	SDL_Texture *texture;
};