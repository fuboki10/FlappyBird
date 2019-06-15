#include "Bird.h"
#include"Application.h"
#include"LoadTextureh.h"
#include<iostream>
#include<string>
#include<SDL.h>
Bird::Bird(SDL_Renderer *renderer):renderer(renderer),
	bird1(loadTexture(renderer,"bird1.bmp")),
	bird2(loadTexture(renderer,"bird2.bmp")),
	velocity(0),
	x(Application::SCREEN_WIDTH/2-50),
	y(Application::SCREEN_HEIGHT/2-50),
	gravity(0.001)
{
}


Bird::~Bird(void)
{
	SDL_DestroyTexture(bird1);
	SDL_DestroyTexture(bird2);
}




void Bird::draw()
{
	SDL_Rect r;
	r.x = x -64;
	r.y = y -64 ;
	r.h = 64;
	r.w = 64;
	auto res = SDL_RenderCopyEx(renderer,rand()%500>250?bird1:bird2,NULL,&r,velocity * 50,0,SDL_FLIP_NONE);
	if (res!=0)
		throw std::runtime_error(std::string("SDL_RenderCopy")+SDL_GetError());

}

void Bird::tick(bool isMouseDown )
{
	velocity -= isMouseDown ? 0.0025 : 0;
	
	velocity += gravity;
	y += velocity;
}

