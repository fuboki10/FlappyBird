#include "Screen.h"
#include"LoadTextureh.h"
#include"Application.h"
#include<iostream>
#include<string>
Screen::Screen(SDL_Renderer *renderer): 
	renderer(renderer),
	start1(loadTexture(renderer,"start.bmp"))
{
}


Screen::~Screen(void)
{
	SDL_DestroyTexture(start1);
}

void Screen::start()
{
	SDL_RenderCopy(renderer,start1,NULL,NULL);
	SDL_RenderPresent(renderer);
	SDL_Event e;
	bool exit=false;
	while (!exit)
	{ 
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				exit = true;
			}
			/*if(e.type == SDL_KEYDOWN)
			{
				switch( e.key.keysym.sym )
				{
				case SDLK_p:
					exit = true;
					break;
				}
			}*/
		}
	}
	//SDL_Delay(2000);
}
