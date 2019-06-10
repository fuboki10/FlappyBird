#include"LoadTextureh.h"
#include<iostream>
#include<stdexcept>
SDL_Texture *loadTexture(SDL_Renderer*renderer,const char*filename)
{
	auto surface = SDL_LoadBMP(filename);
	if (!surface)
	{
		throw std::runtime_error(SDL_GetError());
	}
	Uint32 colorkey = SDL_MapRGB(surface->format, 255, 255, 255);
	SDL_SetColorKey(surface, SDL_TRUE, colorkey);
	auto res = SDL_CreateTextureFromSurface(renderer,surface);
	SDL_FreeSurface(surface);
	return res;

}