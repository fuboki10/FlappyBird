#pragma once
#include<SDL.h>
#include<string>
#include<iostream>
class Screen
{
private:
	SDL_Renderer *renderer;
	SDL_Texture *start1;
public:
	Screen(SDL_Renderer *renderer);
	~Screen();
	void start();
};

		
