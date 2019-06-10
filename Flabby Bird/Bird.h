#pragma once
#include<SDL.h>
#include"Application.h"
class Bird
{
public:
	float y;
	float x;
private:
	SDL_Texture *bird1;
	SDL_Texture *bird2;
	SDL_Renderer *renderer;
	float velocity;
	float gravity ;
public:
	Bird(SDL_Renderer *renderer);
	~Bird(void);
	void draw();
	void tick(bool isMouseDown);
	void key();
};
