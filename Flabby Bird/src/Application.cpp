#include "Application.h"
using namespace std;
#include<iostream>
#include"Bird.h"
#include"Game.h"
#include<SDL.h>
#include"Screen.h"
Application::Application(void)
{
	auto res = SDL_Init(SDL_INIT_EVERYTHING);
	if (res != 0)
	{
		cout<<"ERROR INIT"<<SDL_GetError()<<endl;
		return;
	}	
	SDL_CreateWindowAndRenderer(SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN,&window,&renderer);
	SDL_SetRenderDrawBlendMode(renderer,SDL_BLENDMODE_BLEND);
}


Application::~Application(void)
{
}

int Application::exec()
{
	SDL_SetWindowTitle(window,"FlappyHassan");
	Screen screen(renderer);
	screen.start();
	Game g(renderer);
	return 	g.exec();
	
}
