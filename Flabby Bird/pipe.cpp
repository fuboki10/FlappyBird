#include "pipe.h"
#include<SDL.h>
#include"Application.h"
#include<iostream>
#include<string>

pipe::pipe(SDL_Renderer *renderer,SDL_Texture *texture,float y,bool isup):
	renderer(renderer),
	texture(texture),
	x(Application::SCREEN_WIDTH + 128),y(y),isup(isup)
{
}


void pipe::tick()
{
	x-=0.5;
}

void pipe::draw()
{
	if(!isup)
	{
		SDL_Rect r;
		r.x = x-128;
		r.y = y ;
		r.h = 720;
		r.w = 256;
		auto res = SDL_RenderCopyEx(renderer,texture,NULL,&r,0,0,SDL_FLIP_NONE);
		if (res!=0)
			throw std::runtime_error(std::string("SDL_RenderCopy")+SDL_GetError());
	}
	else{
		SDL_Rect r;
		r.x = x-128;
		r.y = y - Application::SCREEN_HEIGHT;
		r.h = 720;
		r.w = 256;
		auto res = SDL_RenderCopyEx(renderer,texture,NULL,&r,0,0,SDL_FLIP_VERTICAL);
		if (res!=0)
			throw std::runtime_error(std::string("SDL_RenderCopy")+SDL_GetError());
	}
}